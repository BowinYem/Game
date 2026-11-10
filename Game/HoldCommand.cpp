#include "HoldCommand.h"

HoldCommand::HoldCommand(std::function<void(void)> callback_, SDL_Scancode assignedInput_) : 
    Command{callback_, CommandType::CommandTypeHold}, assignedInput{assignedInput_}
{
    // Empty
}
