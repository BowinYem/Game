#pragma once
#include "System.h"
#include "Command.h"
#include "GameGlobals.h"
#include <vector>


class InputSystem : public System
{
public:
    friend struct InputSystemHelper;

    InputSystem(const InputSystem&) = delete;
    InputSystem(InputSystem&&) = delete;
    InputSystem& operator=(const InputSystem&) = delete;
    InputSystem& operator=(InputSystem&&) = delete;

    static bool InitSystem();

    void Update();
    void OnNotify(GameEntity& entity, const std::shared_ptr<const Event> e) override;
    void ReadInput();
    bool GetActionState(GameGlobals::ActionEnumType enumArg);

    inline void AddCommand(const std::shared_ptr<Command> newCommand) { commandList.push_back(newCommand); }
    static inline std::shared_ptr<InputSystem> GetInstance() { return ((!instance) ? nullptr : instance); }

protected:
    InputSystem() = default;

private:
    
    inline bool IsPressed(const SDL_Scancode button) { return keyboardState[button]; }
    inline bool IsPressed(const SDL_Keycode button)  { return actionEvent == button; }

    static std::vector<std::shared_ptr<Command>> commandList;
    const uint8_t* keyboardState = nullptr;
    SDL_Keycode actionEvent;
    static std::shared_ptr<InputSystem> instance; 
};

// TODO: Can we move this System.h/.cpp somehow?
struct InputSystemHelper : public InputSystem
{
    InputSystemHelper() : InputSystem() { /*Empty */ }
};