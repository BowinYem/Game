#pragma once
#include "Command.h"
#include "SDL_keycode.h"

class ActionCommand : public Command
{
public:
    ActionCommand(std::function<void(void)> callback_, SDL_Keycode assignedInput_);
    inline void AssignCommandInput(const SDL_Keycode newInput) { assignedInput = newInput; };
    inline SDL_Keycode GetAssignedInput() { return assignedInput; }     

private:
    SDL_Keycode assignedInput = SDLK_UNKNOWN; // Unassigned by default
};