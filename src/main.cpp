#include <iostream>
#include <string>
#include <unordered_map>
#include "commands.h"
#include <sstream>
#include "helpers.h"

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> args;
    std::string token;
    bool in_quotes = false;
    std::string current_token;

    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '\'' || c == '"') {
            in_quotes = !in_quotes;
            continue;
        }
        if (c == ' ' && !in_quotes) {
            if (!current_token.empty()) {
                args.push_back(current_token);
                current_token.clear();
            }
        } else {
            current_token += c;
        }
    }
    if (!current_token.empty()) {
        args.push_back(current_token);
    }
    
    auto it = Commands::commands.find(args[0]);
    if (it != Commands::commands.end()) {
      it->second(args, [](const std::string& command) {
        return Commands::commands.find(command) != Commands::commands.end();
      });
    } else {
      std::string exe_path = Helpers::exec(("which " + args[0]).c_str());
      if (exe_path != "") {
        std::string command = args[0] + " " + args[1];
        system(command.c_str());
      } else {
        std::cout << args[0] << ": command not found" << std::endl;
      }
    }

  }
}
