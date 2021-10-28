//
// Created by skalem on 29.10.21.
//

#include "gtest/gtest.h"
#include "main.h"

TEST(quadraticSolution, 1){
    double args[3];
    args[0] = -1;
    args[1] = 6;
    args[2] = 7;

    std::pair<double, double> x;
    x.first = 7;
    x.second = -1;
    ASSERT_EQ(quadraticSolution(args), x);
}