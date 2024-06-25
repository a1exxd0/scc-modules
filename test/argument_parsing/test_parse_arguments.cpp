#include <gtest/gtest.h>
#include "command_read.h"

TEST(Full_Parse_Arguments, Avail_True) {
    smod::input_arguments expected;
    expected.avail = true;

    char* args[] = {"avail"};
    auto test_case = smod::get_arguments(1, args);

    ASSERT_EQ(expected, test_case);
}