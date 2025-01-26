#include <string>
#include <iostream>
#include "commandhandlers.h"
#include "types.h"
#include "helpers.h"
#include <unistd.h>
#include "direct.h"

CommandHandlerType CommandHandler::exitCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    exit(0);
};

CommandHandlerType CommandHandler::echoCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    for (int i = 1; i < args.size(); i++) {
        std::string arg = args[i];
        if(arg.front() == '"' || arg.front() == '\'') {
            arg = arg.substr(1, arg.length() - 1);
        }
        if(arg.back() == '"' || arg.back() == '\'') {
            arg = arg.substr(0, arg.length() - 1);
        }
        std::cout << arg << " ";
    }
    std::cout << std::endl;
};

CommandHandlerType CommandHandler::typeCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    std::string command = "which " + args[1];
    std::string exe_path = Helpers::exec(command.c_str());
    
    if (args.size() < 2) {
        std::cout << "type: missing argument" << std::endl;
        return;
    }
    if (exists(args[1])) {
        std::cout << args[1] << " is a shell builtin" << std::endl;
    }
    else if (exe_path != "") {
        std::cout << args[1] << " is " << exe_path;
    } else {
        std::cout << args[1] << ": not found" << std::endl;
    }
};

CommandHandlerType CommandHandler::pwdCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    std::cout << Helpers::exec("pwd");
};

CommandHandlerType CommandHandler::cdCommand = [](const std::vector<std::string>& args, CommandExistsFunc exists) {
    if(args[1] == "~") {
        chdir(getenv("HOME"));
    } else {
        if (!chdir(args[1].c_str()) == 0) {
            std::cout << "cd: " << args[1] << ": No such file or directory" << std::endl;
        }
    }
};



