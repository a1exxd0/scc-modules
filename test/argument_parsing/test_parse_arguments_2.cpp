#include <gtest/gtest.h>
#include "command_read.h"
#include <vector>
#include <string>

// ---------- SWAP ---------- //

TEST(Full_Parse_Arguments_2, Swap_Positive) 
{
    smod::input_arguments expected;
    expected.swap = {true, "cpp15", "cpp17"};

    char arg[] = "smodule";
    char arg0[] = "swap";
    char arg1[] = "cpp15";
    char arg2[] = "cpp17";
    char* args[] = {arg, arg0, arg1, arg2};
    auto test_case = smod::get_arguments(4, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments_2, Swap_Alias_Switch) 
{
    smod::input_arguments expected;
    expected.swap = {true, "cpp15", "cpp17"};

    char arg[] = "smodule";
    char arg0[] = "switch";
    char arg1[] = "cpp15";
    char arg2[] = "cpp17";
    char* args[] = {arg, arg0, arg1, arg2};
    auto test_case = smod::get_arguments(4, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments_2, Swap_Too_Many_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "swap";
    char arg1[] = "cpp15";
    char arg2[] = "openmpi/cpp15";
    char arg3[] = "openmpi/cpp17";
    char* args[] = {arg, arg0, arg1, arg2, arg3};
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments_2, Swap_Too_Few_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "swap";
    char* args[] = {arg, arg0};
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}