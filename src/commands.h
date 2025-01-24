#include <unordered_map>
#include <string>
#include "commandhandlers.h"
#include "types.h"

namespace Commands {
    std::unordered_map<std::string, CommandHandlerType> commands = {
        {"exit", CommandHandler::exitCommand},
        {"echo", CommandHandler::echoCommand}
    };
}