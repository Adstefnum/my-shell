#include <unordered_map>
#include <string>
#include "commandhandlers.h"
#include "types.h"
#include "commands.h"
std::unordered_map<std::string, CommandHandlerType> Commands::commands = {
    {"exit 0", CommandHandler::exitCommand}
};