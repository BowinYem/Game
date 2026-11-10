#pragma once
#include <functional>

enum class CommandType
{
    CommandTypeHold,
    CommandTypeAction
};

class Command
{
public:
    Command(std::function<void(void)> callback_, CommandType type_); 
    inline void Execute() { if(callback) { callback(); }}
    inline void AssignFunction(void (*function_)(void)) { if(function_) callback = function_; } 
    inline CommandType GetCommandType() { return type; }
private:
    std::function<void(void)> callback;
    CommandType type;
};

