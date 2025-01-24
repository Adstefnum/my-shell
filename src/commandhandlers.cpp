#include <string>
#include <iostream>
#include "commandhandlers.h"
#include "types.h"


CommandHandlerType CommandHandler::exitCommand = [](const std::vector<std::string>& args) {
    exit(0);
};

CommandHandlerType CommandHandler::echoCommand = [](const std::vector<std::string>& args) {
    for (int i = 1; i < args.size(); i++) {
        std::cout << args[i] << " ";
    }
    std::cout << std::endl;
};



