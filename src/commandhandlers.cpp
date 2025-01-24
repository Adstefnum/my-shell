#include <string>
#include "commandhandlers.h"
#include "types.h"


CommandHandlerType CommandHandler::exitCommand = [](const std::string& args) {
    exit(0);
};



