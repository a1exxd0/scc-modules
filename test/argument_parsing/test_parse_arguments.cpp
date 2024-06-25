#include <gtest/gtest.h>
#include "command_read.h"

TEST(Parse_Arguments, Argument_Separation) {
    smod::input_arguments expected = {{"-d", "-f"}, true};

    char* args[] = {"-d", "-f"};
    smod::input_arguments test_case = smod::get_arguments(2, args);

    ASSERT_EQ(test_case, expected);
}