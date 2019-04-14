#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "../myproject/MyMessage.h"


TEST(message, ArgsOverload){
    EXPECT_FALSE(message(std::cout, "% + % = %", 1, 2));
    EXPECT_FALSE(message(std::cout, "% + % = %", 1, 2, 3, 4));
}

TEST(message, EqualityTest){
    std::stringstream testOut;
    message(testOut, "% + % = %", 1, 2.2, "word");
    std::string expectedOut = "1 + 2.2 = word";
    EXPECT_EQ(testOut.str(), expectedOut);
}

