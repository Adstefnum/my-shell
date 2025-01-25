#include <string>
#include <iostream>
#include "commandhandlers.h"
#include "types.h"

CommandHandlerType CommandHandler::exitCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    exit(0);
};

CommandHandlerType CommandHandler::echoCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    for (int i = 1; i < args.size(); i++) {
        std::cout << args[i] << " ";
    }
    std::cout << std::endl;
};

CommandHandlerType CommandHandler::typeCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    if (args.size() < 2) {
        std::cout << "type: missing argument" << std::endl;
        return;
    }
    if (exists(args[1])) {
        std::cout << args[1] << " is a shell builtin" << std::endl;
    } else {
        std::cout << args[1] << ": not found" << std::endl;
    }
};



