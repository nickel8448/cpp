#include "gtest/gtest.h"
#include "src/salesperson/compensation.h"

TEST(Compensation, MethodOne) {
    double expected = 600;
    ASSERT_EQ(expected, calcMethod1());
}

TEST(Compensation, MethodTwo) {
    double expected = 392.5;
    int sales = 5;
    ASSERT_EQ(expected, calcMethod2(sales));
}

TEST(Compensation, MethodThree) {
    double expected = 325;
    int sales = 5;
    ASSERT_EQ(expected, calcMethod3(sales));
}