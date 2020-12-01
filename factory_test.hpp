#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "lab4/op.hpp"
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/div.hpp"
#include "lab4/mult.hpp"
#include "factory.hpp"

TEST(FactoryTest_Simple, Add) {
    char *test_val[4] = {" ", "8", "+", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000+2.000000");
    EXPECT_EQ(conversion->evaluate(), 10.000000);

}

TEST(FactoryTest_Simple, Sub) {
    char *test_val[4] = {" ", "8", "-", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000-2.000000");
    EXPECT_EQ(conversion->evaluate(), 6.000000);

}

TEST(FactoryTest_Simple, Mult) {
    char *test_val[4] = {" ", "8", "*", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000*2.000000");
    EXPECT_EQ(conversion->evaluate(), 16.000000);

}

TEST(FactoryTest_Simple, Div) {
    char *test_val[4] = {" ", "8", "/", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000/2.000000");
    EXPECT_EQ(conversion->evaluate(), 4.000000);

}

TEST(FactoryTest_Simple, Pow) {
    char *test_val[4] = {" ", "8", "**", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000**2.000000");
    EXPECT_EQ(conversion->evaluate(), 64.000000);

}

TEST(FactoryTest_Complex, Test_1) {
    char *test_val[12] = {" ", "3", "+", "5", "/", "2", "*", "5", "-", "9", "**", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "3.000000+5.000000/2.000000*5.000000-9.000000**2.000000");
    EXPECT_EQ(conversion->evaluate(), 121.000000);

}

TEST(FactoryTest_Complex, Test_2) {
    char *test_val[12] = {" ", "1", "*", "5", "+", "2", "**", "2", "/", "2", "-", "4"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "1.000000*5.000000+2.000000**2.000000/2.000000-4.000000");
    EXPECT_EQ(conversion->evaluate(), 20.500000);

}

TEST(FactoryTest_Complex, Test_3) {
    char *test_val[12] = {" ", "9", "-", "4", "**", "3", "/", "5", "+", "5", "*", "6"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "9.000000-4.000000**3.000000/5.000000+5.000000*6.000000");
    EXPECT_EQ(conversion->evaluate(), 180.000000);

}

#endif
