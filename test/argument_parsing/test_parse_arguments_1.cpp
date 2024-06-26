#include <gtest/gtest.h>
#include "command_read.h"
#include <vector>
#include <string>

// ---------- BASIC PARSE CHECKS ---------- //

TEST(Full_Parse_Arguments, Empty_Parse) 
{
    auto args = smod::format_args({"smodule"});
    EXPECT_THROW(smod::get_arguments(1, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Keyword_As_Parameter) 
{
    auto args = smod::format_args({"smodule", "avail", "load"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, No_Command) 
{
    auto args = smod::format_args({"smodule", "cpp15", "openmpi/cpp15"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Lots_of_Arguments)
{
    std::vector<std::string> cmds;
    cmds.push_back("smodule");
    cmds.push_back("avail");
    for (std::size_t i = 0; i < 100; i++) cmds.push_back("cpp15");
    char** args = smod::format_args(cmds);
    EXPECT_THROW(smod::get_arguments(102, args), std::invalid_argument);
}

// ---------- AVAIL ---------- //

TEST(Full_Parse_Arguments, Avail_Positive) 
{
    smod::input_arguments expected;
    expected.avail = true;

    auto args = smod::format_args({"smodule", "avail"});
    auto test_case = smod::get_arguments(2, args);

    ASSERT_EQ(expected, test_case);
}

TEST(Full_Parse_Arguments, Avail_Negative) 
{
    auto args = smod::format_args({"smodule", "avail", "cpp15"});
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

// ---------- LOAD ---------- //

TEST(Full_Parse_Arguments, Load_Positive) 
{
    smod::input_arguments expected;
    expected.load = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "load", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Load_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "load", "cpp15", "openmpi/cpp15"});
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Load_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "load"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

// ---------- UNLOAD ---------- //

TEST(Full_Parse_Arguments, Unload_Positive) 
{
    smod::input_arguments expected;
    expected.unload = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "unload", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Unload_Aliased_Rm) 
{
    smod::input_arguments expected;
    expected.unload = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "rm", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Unload_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "unload", "cpp15", "openmpi/cpp15"});
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Unload_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "unload"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

// ---------- SPIDER ---------- //

TEST(Full_Parse_Arguments, Spider_Positive) 
{
    smod::input_arguments expected;
    expected.spider = {true, "cpp15"};

    auto args = smod::format_args({"smodule", "spider", "cpp15"});
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Spider_Too_Many_Args) 
{
    auto args = smod::format_args({"smodule", "spider", "cpp15", "openmpi/cpp15"});
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Spider_Too_Few_Args) 
{
    auto args = smod::format_args({"smodule", "unload"});
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}