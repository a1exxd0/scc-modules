#ifndef COMMAND_READ_H
#define COMMAND_READ_H

#include <cstddef>
#include <string>
#include <vector>
#include <tuple>

namespace smod {

// ---------- INPUT ARGUMENT STRUCT ---------- //

struct input_arguments {
    bool avail = false;
    std::pair<bool, std::string> load = {false, ""};
    std::pair<bool, std::string> unload = {false, ""};
    std::pair<bool, std::string> spider= {false, ""};
    std::tuple<bool, std::string, std::string> swap = {false, "", ""};
    std::pair<bool, std::string> save = {false, ""};
    std::pair<bool, std::string> saverm = {false, ""};
    std::pair<bool, std::string> saveshow = {false, ""};
    bool savelist = false;
    std::pair<bool, std::string> restore = {false, ""};
    bool help = false;
    std::pair<bool, std::string> display = {false, ""};
    std::pair<bool, std::string> use = {false, ""};
    std::pair<bool, std::string> unuse = {false, ""};
    bool reload = false;
    bool purge = false;
    std::pair<bool, std::string> source = {false, ""};
    std::pair<bool, std::string> path = {false, ""};

    input_arguments() = default;
};

bool operator==(const input_arguments &arg1, const input_arguments &arg2);

// ---------- METHODS ---------- //

input_arguments get_arguments(std::size_t argc, char* argv[]);
    
} // namespace smod


#endif // COMMAND_READ_H