#include <gtest/gtest.h>
#include "command_read.h"
#include <vector>
#include <string>

// ---------- BASIC PARSE CHECKS ---------- //
TEST(Full_Parse_Arguments, Empty_Parse) 
{
    char arg[] = "smodule";
    char* args[] = {arg};
    EXPECT_THROW(smod::get_arguments(1, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Keyword_As_Parameter) 
{
    char arg[] = "smodule";
    char arg0[] = "avail";
    char arg1[] = "load";
    char* args[] = {arg, arg0, arg1};
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, No_Command) 
{
    char arg[] = "smodule";
    char arg0[] = "cpp15";
    char arg1[] = "openmpi/cpp-15";
    char* args[] = {arg, arg0, arg1};
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Lots_of_Arguments)
{
    std::vector<std::string> cmds;
    cmds.push_back("smodule");
    cmds.push_back("avail");
    for (std::size_t i = 0; i < 100; i++) cmds.push_back("cpp15");
    char* args[103];
    for (std::size_t i = 0; i < 103; i++) {
        args[i] = const_cast<char*>(cmds[i].c_str());
    }
    args[cmds.size()] = nullptr;
    EXPECT_THROW(smod::get_arguments(102, args), std::invalid_argument);
}

// ---------- AVAIL ---------- //

TEST(Full_Parse_Arguments, Avail_Positive) 
{
    smod::input_arguments expected;
    expected.avail = true;

    char arg[] = "smodule";
    char arg0[] = "avail";
    char* args[] = {arg, arg0};
    auto test_case = smod::get_arguments(2, args);

    ASSERT_EQ(expected, test_case);
}

TEST(Full_Parse_Arguments, Avail_Negative) 
{
    char arg[] = "smodule";
    char arg0[] = "avail";
    char arg1[] = "cpp15";
    char* args[] = {arg, arg0, arg1};
    EXPECT_THROW(smod::get_arguments(3, args), std::invalid_argument);
}

// ---------- LOAD ---------- //

TEST(Full_Parse_Arguments, Load_Positive) 
{
    smod::input_arguments expected;
    expected.load = {true, "cpp15"};

    char arg[] = "smodule";
    char arg0[] = "load";
    char arg1[] = "cpp15";
    char* args[] = {arg, arg0, arg1};
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Load_Too_Many_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "load";
    char arg1[] = "cpp15";
    char arg2[] = "openmpi/cpp15";
    char* args[] = {arg, arg0, arg1, arg2};
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Load_Too_Few_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "load";
    char* args[] = {arg, arg0};
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

// ---------- UNLOAD ---------- //

TEST(Full_Parse_Arguments, Unload_Positive) 
{
    smod::input_arguments expected;
    expected.unload = {true, "cpp15"};

    char arg[] = "smodule";
    char arg0[] = "unload";
    char arg1[] = "cpp15";
    char* args[] = {arg, arg0, arg1};
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Unload_Too_Many_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "unload";
    char arg1[] = "cpp15";
    char arg2[] = "openmpi/cpp15";
    char* args[] = {arg, arg0, arg1, arg2};
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Unload_Too_Few_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "unload";
    char* args[] = {arg, arg0};
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

// ---------- SPIDER ---------- //

TEST(Full_Parse_Arguments, Spider_Positive) 
{
    smod::input_arguments expected;
    expected.spider = {true, "cpp15"};

    char arg[] = "smodule";
    char arg0[] = "spider";
    char arg1[] = "cpp15";
    char* args[] = {arg, arg0, arg1};
    auto test_case = smod::get_arguments(3, args);

    ASSERT_EQ(test_case, expected);
}

TEST(Full_Parse_Arguments, Spider_Too_Many_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "spider";
    char arg1[] = "cpp15";
    char arg2[] = "openmpi/cpp15";
    char* args[] = {arg, arg0, arg1, arg2};
    EXPECT_THROW(smod::get_arguments(4, args), std::invalid_argument);
}

TEST(Full_Parse_Arguments, Spider_Too_Few_Args) 
{
    char arg[] = "smodule";
    char arg0[] = "spider";
    char* args[] = {arg, arg0};
    EXPECT_THROW(smod::get_arguments(2, args), std::invalid_argument);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}