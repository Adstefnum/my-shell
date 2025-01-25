#pragma once
#include <functional>
#include <string>


using CommandExistsFunc = std::function<bool(const std::string&)>;
using CommandHandlerType = std::function<void(const std::vector<std::string>&, CommandExistsFunc)>;
using CommandType = std::unordered_map<std::string, CommandHandlerType>;
