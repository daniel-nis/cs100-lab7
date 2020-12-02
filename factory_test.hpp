#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "lab4/op.hpp"
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/div.hpp"
#include "lab4/mult.hpp"
#include "factory.hpp"

TEST(FactoryAdd, Add_1) {
    char *test_val[4] = {" ", "8", "+", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000+2.000000");
    EXPECT_EQ(conversion->evaluate(), 10.000000);

}

TEST(FactoryAdd, Add_2) {
    char *test_val[4] = {" ", "6", "+", "6"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "6.000000+6.000000");
    EXPECT_EQ(conversion->evaluate(), 12.000000);

}

TEST(FactoryAdd, Add_Zero) {
    char *test_val[4] = {" ", "6", "+", "0"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "6.000000+0.000000");
    EXPECT_EQ(conversion->evaluate(), 6.000000);

}

TEST(FactorySub, Sub_1) {
    char *test_val[4] = {" ", "8", "-", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000-2.000000");
    EXPECT_EQ(conversion->evaluate(), 6.000000);

}

TEST(FactorySub, Sub_2) {
    char *test_val[4] = {" ", "9", "-", "4"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "9.000000-4.000000");
    EXPECT_EQ(conversion->evaluate(), 5.000000);

}

TEST(FactorySub, Sub_Zero) {
    char *test_val[4] = {" ", "5", "-", "0"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "5.000000-0.000000");
    EXPECT_EQ(conversion->evaluate(), 5.000000);

}

TEST(FactoryMult, Mult_1) {
    char *test_val[4] = {" ", "8", "*", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000*2.000000");
    EXPECT_EQ(conversion->evaluate(), 16.000000);

}

TEST(FactoryMult, Mult_2) {
    char *test_val[4] = {" ", "9", "*", "9"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "9.000000*9.000000");
    EXPECT_EQ(conversion->evaluate(), 81.000000);

}

TEST(FactoryMult, Mult_Zero) {
    char *test_val[4] = {" ", "3", "*", "0"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "3.000000*0.000000");
    EXPECT_EQ(conversion->evaluate(), 0.000000);

}

TEST(FactoryDiv, Div_1) {
    char *test_val[4] = {" ", "8", "/", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000/2.000000");
    EXPECT_EQ(conversion->evaluate(), 4.000000);

}

TEST(FactoryDiv, Div_2) {
    char *test_val[4] = {" ", "9", "/", "3"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "9.000000/3.000000");
    EXPECT_EQ(conversion->evaluate(), 3.000000);

}

TEST(FactoryDiv, Div_3) {
    char *test_val[4] = {" ", "5", "/", "5"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "5.000000/5.000000");
    EXPECT_EQ(conversion->evaluate(), 1.000000);

}

TEST(FactoryPow, Pow_1) {
    char *test_val[4] = {" ", "8", "**", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "8.000000**2.000000");
    EXPECT_EQ(conversion->evaluate(), 64.000000);

}

TEST(FactoryPow, Pow_2) {
    char *test_val[4] = {" ", "9", "**", "3"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "9.000000**3.000000");
    EXPECT_EQ(conversion->evaluate(), 729.000000);

}

TEST(FactoryPow, Pow_Zero) {
    char *test_val[4] = {" ", "5", "**", "0"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,4);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "5.000000**0.000000");
    EXPECT_EQ(conversion->evaluate(), 1.000000);

}

TEST(FactoryTest_Complex, Test_1) {
    char *test_val[12] = {" ", "3", "+", "5", "/", "2", "*", "5", "-", "10", "**", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "3.000000+5.000000/2.000000*5.000000-10.000000**2.000000");
    EXPECT_EQ(conversion->evaluate(), 100.000000);

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

TEST(FactoryTest_Complex, Test_DoubleDigits) {
    char *test_val[12] = {" ", "10", "*", "10", "+", "25", "**", "2", "/", "20", "-", "30"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "10.000000*10.000000+25.000000**2.000000/20.000000-30.000000");
    EXPECT_EQ(conversion->evaluate(), 751.250000);

}

TEST(FactoryTest_Complex, Test_Negative) {
    char *test_val[12] = {" ", "5", "-", "25", "**", "3", "/", "5", "+", "5", "*", "2"};
    Factory* factory = new Factory();

    Base* conversion = factory->parse( test_val,12);

    ASSERT_NE(conversion, nullptr);
    EXPECT_EQ(conversion->stringify(), "5.000000-25.000000**3.000000/5.000000+5.000000*2.000000");
    EXPECT_EQ(conversion->evaluate(), -3190.000000);

}
#endif
