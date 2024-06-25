#include <gtest/gtest.h>
#include "command_read.h"

#pragma gcc ignore()
TEST(Full_Parse_Arguments, Avail_Positive) {
    smod::input_arguments expected;
    expected.avail = true;

    char* args[] = {"avail"};
    auto test_case = smod::get_arguments(1, args);

    ASSERT_EQ(expected, test_case);
}

TEST(Full_Parse_Arguments, Empty_Parse) {

    char* args[] = {nullptr};
    EXPECT_ANY_THROW(smod::get_arguments(0, args));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}