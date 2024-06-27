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
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Swap_Alias_Switch) 
{
    smod::input_arguments expected;
    expected.swap = {true, "cpp15", "cpp17"};

    auto args = smod::format_args({"smodule", "switch", "cpp15", "cpp17"});
    auto test_case = smod::get_arguments(4, args);

    ASSERT_EQ(test_case, expected);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Swap_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "swap", "cpp15", "cpp17", "cpp20"});
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Swap_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "swap", "cpp15"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
    delete[] args;
}

// ---------- SAVE--------- //

TEST(Full_Parse_Arguments_2, Save_Positive) 
{
    smod::input_arguments expected;
    expected.save = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "save", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Save_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "save", "cpp15", "cpp17", "cpp20"});
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Save_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "save"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
    delete[] args;
}

// ---------- SAVERM--------- //

TEST(Full_Parse_Arguments_2, Saverm_Positive) 
{
    smod::input_arguments expected;
    expected.saverm = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "saverm", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Saverm_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "saverm", "cpp15", "cpp17", "cpp20"});
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Saverm_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "saverm"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
    delete[] args;
}

// ---------- SAVESHOW--------- //

TEST(Full_Parse_Arguments_2, Saveshow_Positive) 
{
    smod::input_arguments expected;
    expected.saveshow = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "saveshow", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Saveshow_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "saveshow", "cpp15", "cpp17", "cpp20"});
    EXPECT_THROW(smod::get_arguments(5, args), std::invalid_argument);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Saveshow_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "saveshow"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
    delete[] args;
}

// ---------- SAVELIST ---------- //

TEST(Full_Parse_Arguments_2, Savelist_Positive) 
{
    smod::input_arguments expected;
    expected.savelist = true;

    auto args = smod::format_args({"smodule", "savelist"});
    auto test_case = smod::get_arguments(2, args);

    delete[] args;
}

TEST(Full_Parse_Arguments_2, Savelist_Negative) 
{
    auto args = smod::format_args({"smodule", "savelist", "cpp15"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
    delete[] args;
}

// ---------- RESTORE--------- //

TEST(Full_Parse_Arguments_2, Restore_Positive) 
{
    smod::input_arguments expected;
    expected.restore = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "restore", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Restore_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "restore", "cpp15", "cpp17"});
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
    delete[] args;
}

TEST(Full_Parse_Arguments_2, Restore_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "restore"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
    delete[] args;
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}