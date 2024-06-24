#include <gtest/gtest.h>
#include "command_read.h"

TEST(Fake_Test, Add_Two_Numbers) {
    int x = smod::add_two_numbers(5, 7);

    EXPECT_EQ(x, 12);
}