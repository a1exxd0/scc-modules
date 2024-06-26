#include <gtest/gtest.h>
#include "command_read.h"
#include <vector>
#include <string>

// ---------- SWAP ---------- //

TEST(Full_Parse_Arguments_2, Swap_Positive) 
{
    smod::input_arguments expected;
    expected.swap = {true, "cpp15", "cpp17"};

    auto args = smod::format_args({"smodule", "swap", "cpp15", "cpp17"});
    auto test_case = smod::get_arguments(4, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments_2, Swap_Alias_Switch) 
{
    smod::input_arguments expected;
    expected.swap = {true, "cpp15", "cpp17"};

    auto args = smod::format_args({"smodule", "switch", "cpp15", "cpp17"});
    auto test_case = smod::get_arguments(4, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments_2, Swap_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "swap", "cpp15", "cpp17", "cpp20"});
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments_2, Swap_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "swap", "cpp15"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}