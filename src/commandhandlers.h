#pragma once
#include <string>
#include "types.h"

class CommandHandler {
public:
    static CommandHandlerType exitCommand;
    static CommandHandlerType echoCommand;
    static CommandHandlerType typeCommand;
    static CommandHandlerType pwdCommand;
    static CommandHandlerType cdCommand;
};

