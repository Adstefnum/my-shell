#include <iostream>
#include <string>
#include <unordered_map>
#include "commands.h"

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    auto it = Commands::commands.find(input);
    if (it != Commands::commands.end()) {
      it->second(input);
    } else {
      std::cout << input << ": command not found" << std::endl;
    }

  }
}
