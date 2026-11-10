#include "ActionCommand.h"

ActionCommand::ActionCommand(std::function<void(void)> callback_, SDL_Keycode assignedInput_) : 
    Command{callback_, CommandType::CommandTypeAction}, assignedInput{assignedInput_}
{
    // Empty
}
