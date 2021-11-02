//
// Created by skalem on 29.10.21.
//

#include "gtest/gtest.h"
#include "main.h"

TEST(linear, 1){
    double args[3];
    args[0] = 0;
    args[1] = 6;
    args[2] = 7;
    double result = (double) -7 / 6;
    ASSERT_EQ(linearSolution(args), result);
}

TEST(quadratic, 1){
    double args[3];
    args[0] = -1;
    args[1] = 6;
    args[2] = 7;

    std::pair<double, double> x;
    x.first = 7;
    x.second = -1;
    std::pair<double, double> xV;
    xV.first = x.second;
    xV.second = x.first;
    ASSERT_TRUE((quadraticSolution(args) == x) || (quadraticSolution(args) == xV));
}

TEST(getC, 1){
    ASSERT_EQ(getC("8x^2+9x+7"), 7);
}

TEST(getB, 1){
    ASSERT_EQ(getB("8x^2+9x+7"), 9);
}

TEST(getA, 1){
    ASSERT_EQ(getA("8x^2+9x+7"), 8);
}

TEST(getC, 2){
    ASSERT_EQ(getC("8x^2+9x+7.78952"), 7.78952);
}

TEST(getB, 2){
    ASSERT_EQ(getB("8x^2+9.5693x+7"), 9.5693);
}

TEST(getA, 2){
    ASSERT_EQ(getA("8.7634x^2+9x+7"), 8.7634);
}

TEST(getC, 3){
    ASSERT_EQ(getC("8x^2+9x+7,78952"), 7.78952);
}

TEST(getB, 3){
    ASSERT_EQ(getB("8x^2+9,5693x+7"), 9.5693);
}

TEST(getA, 3){
    ASSERT_EQ(getA("8,7634x^2+9x+7"), 8.7634);
}

TEST(getC, 4){
    ASSERT_EQ(getC("8x^2+9x"), 0);
}

TEST(getB, 4){
    ASSERT_EQ(getB("8x^2+x+7"), 1);
}

TEST(getA, 4){
    ASSERT_EQ(getA("x^2+9x+7"), 1);
}

TEST(getC, 5){
    ASSERT_EQ(getC("8x^2+9x"), 0);
}

TEST(getB, 5){
    ASSERT_EQ(getB("8x^2+7"), 0);
}

TEST(getA, 5){
    ASSERT_EQ(getA("9x+7"), 0);
}
