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