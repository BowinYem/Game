#pragma once
#include "SDL_scancode.h"
#include "Command.h"

class HoldCommand : public Command
{
public:
    HoldCommand(std::function<void(void)> callback_, SDL_Scancode assignedInput_);
    inline void AssignCommandInput(const SDL_Scancode newInput) { assignedInput = newInput; };
    inline SDL_Scancode GetAssignedInput() { return assignedInput; }     
private:
    SDL_Scancode assignedInput = SDL_SCANCODE_UNKNOWN; // Unassigned by default
};