#include <gtest/gtest.h>
#include "command_read.h"

TEST(Full_Parse_Arguments, Avail_Positive) {
    smod::input_arguments expected;
    expected.avail = true;

    char arg0[] = "avail";
    char* args[] = {arg0};
    auto test_case = smod::get_arguments(1, args);

    ASSERT_EQ(expected, test_case);
}

TEST(Full_Parse_Arguments, Empty_Parse) {

    char* args[] = {nullptr};
    EXPECT_THROW(smod::get_arguments(0, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Avail_Negative) {
    char arg0[] = "avail";
    char arg1[] = "cpp15";
    char* args[] = {arg0, arg1};
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}