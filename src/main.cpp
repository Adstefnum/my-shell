#include <iostream>
#include <string>
#include <unordered_map>
#include "commands.h"
#include <sstream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::vector<std::string> args;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream iss(input);
    std::string token;

    while (std::getline(iss, token, ' ')) {
      args.push_back(token);
    }
 
    auto it = Commands::commands.find(args[0]);
    if (it != Commands::commands.end()) {
      it->second(args, [](const std::string& command) {
        return Commands::commands.find(command) != Commands::commands.end();
      });
    } else {
      std::cout << args[0] << ": command not found" << std::endl;
    }

  }
}
