#pragma once
#include <unordered_map>
#include <string>
#include "commandhandlers.h"
#include "types.h"

namespace Commands {
    CommandType commands = {
        {"exit", CommandHandler::exitCommand},
        {"echo", CommandHandler::echoCommand},
        {"type", CommandHandler::typeCommand},
        {"pwd", CommandHandler::pwdCommand},
    };
} 