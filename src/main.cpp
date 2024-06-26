#include <iostream>
#include "command_read.h"

int main(int argc, char* argv[]) 
{

    // Read arguments from command line
    try {
        smod::input_arguments args = smod::get_arguments((std::size_t) argc, argv);
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}