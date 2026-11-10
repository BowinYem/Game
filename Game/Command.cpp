#include "Command.h"

Command::Command(std::function<void(void)> callback_, CommandType type_) : callback{callback_}, type{type_}
{
    // Empty
}