#ifndef COMMAND_READ_H
#define COMMAND_READ_H

#include <cstddef>
#include <string>
#include <vector>

namespace smod {

// ---------- INPUT ARGUMENT STRUCT ---------- //

struct input_arguments {
    std::vector<std::string> unfiltered_args; 
    bool flag;
};

bool operator==(const input_arguments &arg1, const input_arguments &arg2);

// ---------- METHODS ---------- //

input_arguments get_arguments(std::size_t argc, char* argv[]);
    
} // namespace smod


#endif // COMMAND_READ_H