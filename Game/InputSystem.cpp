#include "InputSystem.h"
#include "GameSystems.h"
#include "EnumOperators.h"
#include "InputFunctions.h"
#include "GameGlobals.h"
#include "HoldCommand.h"
#include "ActionCommand.h"

#include <iostream> // TODO: REMOVE

// Initialize static members

std::shared_ptr<InputSystem> InputSystem::instance(nullptr);
std::vector<std::shared_ptr<Command>> InputSystem::commandList(+GameGlobals::ActionEnumType::TotalActions);

// Function definitions

bool InputSystem::InitSystem()
{
    if(!instance)
        { instance = std::make_shared<InputSystemHelper>(); } 
    
    // Hold Commands
    commandList[+GameGlobals::ActionEnumType::ActionMoveForward]   = std::make_shared<HoldCommand>(ActionMoveForwardFunction,   SDL_SCANCODE_UP);
    commandList[+GameGlobals::ActionEnumType::ActionMoveBack]      = std::make_shared<HoldCommand>(ActionMoveBackFunction,      SDL_SCANCODE_DOWN);
    commandList[+GameGlobals::ActionEnumType::ActionRotateLeft]    = std::make_shared<HoldCommand>(ActionRotateLeftFunction,    SDL_SCANCODE_LEFT);
    commandList[+GameGlobals::ActionEnumType::ActionRotateRight]   = std::make_shared<HoldCommand>(ActionRotateRightFunction,   SDL_SCANCODE_RIGHT);
    commandList[+GameGlobals::ActionEnumType::ActionDebugCamUp]    = std::make_shared<HoldCommand>(ActionDebugCamUpFunction,    SDL_SCANCODE_W);
    commandList[+GameGlobals::ActionEnumType::ActionDebugCamDown]  = std::make_shared<HoldCommand>(ActionDebugCamDownFunction,  SDL_SCANCODE_S);
    commandList[+GameGlobals::ActionEnumType::ActionDebugCamLeft]  = std::make_shared<HoldCommand>(ActionDebugCamLeftFunction,  SDL_SCANCODE_A);
    commandList[+GameGlobals::ActionEnumType::ActionDebugCamRight] = std::make_shared<HoldCommand>(ActionDebugCamRightFunction, SDL_SCANCODE_D);

    // Action Commands
    commandList[+GameGlobals::ActionEnumType::ActionShoot]         = std::make_shared<ActionCommand>(ActionShootFunction,       SDLK_SPACE);

    return (instance ? true : false);
}

void InputSystem::Update()
{
    for(auto& currCommand : commandList)
    {
        auto currCommandType = currCommand->GetCommandType();
        switch(currCommandType)
        {
            case CommandType::CommandTypeHold:
            {
                auto currHoldCommand = std::static_pointer_cast<HoldCommand>(currCommand);
                if(keyboardState[currHoldCommand->GetAssignedInput()]) { currHoldCommand->Execute(); }
                break;
            }

            case CommandType::CommandTypeAction:
            {
                auto currActionCommand = std::static_pointer_cast<ActionCommand>(currCommand);
                if(actionEvent == currActionCommand->GetAssignedInput()) { currActionCommand->Execute(); }
                break;
            }
        }
    }
}
    
void InputSystem::OnNotify(GameEntity& entity, const std::shared_ptr<const Event> e)
{
    // Empty...for now
}

    
void InputSystem::ReadInput()
{
    actionEvent = SDLK_UNKNOWN;
    SDL_Event event;

    while(SDL_PollEvent(&event) != 0)
    { 
        if (event.type == SDL_QUIT)
        {
            GameSystems::quit = true;
        }
        else if(event.type == SDL_KEYUP)
        {
            actionEvent = event.key.keysym.sym;
        }
    }
    
    keyboardState = SDL_GetKeyboardState(nullptr);
}
    
bool InputSystem::GetActionState(GameGlobals::ActionEnumType enumArg)
{
    auto& cmd = commandList.at(+enumArg);

    if(cmd->GetCommandType() == CommandType::CommandTypeHold)
    {
        auto holdCmd = std::static_pointer_cast<HoldCommand>(cmd); 
        return IsPressed(holdCmd->GetAssignedInput());
    }

    if(cmd->GetCommandType() == CommandType::CommandTypeAction)
    {
        auto actionCmd = std::static_pointer_cast<ActionCommand>(cmd);
        return IsPressed(actionCmd->GetAssignedInput());
    }

    return false;
}
