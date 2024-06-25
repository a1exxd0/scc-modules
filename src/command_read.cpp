#include "command_read.h"
#include <iostream>
#include <vector>
#include <string>

namespace smod {

// ---------- INPUT ARGUMENT STRUCT ---------- //

bool operator==(const input_arguments &arg1, const input_arguments &arg2) {
    return
        arg1.unfiltered_args == arg2.unfiltered_args &&
        arg1.flag == arg2.flag;
}

input_arguments get_arguments(std::size_t argc, char* argv[]) {
    std::vector<std::string> args;

    for (std::size_t i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }

    input_arguments res = {args, true};

    return res;
}


} // namespace smod