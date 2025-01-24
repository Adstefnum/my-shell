#include <unordered_map>
#include <string>
#include "types.h"

class Commands {
public:
    static std::unordered_map<std::string, CommandHandlerType> commands;
};

