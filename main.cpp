#include <iostream>
#include <string>
#include "main.h"
#include <cmath>

using namespace std;

double getA(const string& problem){
    double a = 0;
    int tenth = 1;

    for (int i = 0; i < problem.size(); i++) {
        if (problem.find("x^2",0) == -1){
            return 0;
        }
        if (problem[i] == 'x'){
            break;
        }
        if (problem[i] == ',' || problem[i] == '.') {
            tenth = 10;
        } else {
            int temp = problem[i] - 48;
            double tempd = (double) temp / tenth;
            a += tempd;
            if (tenth != 1){
                tenth *= 10;
            }
        }
    }
    if (a == 0) {
        return 1;
    }
    return a;
}

double getB(const string& problem){
    double b = 0;
    int tenth = 1, num = -1;
    for (int i = 0; i < problem.size(); ++i) {
        if(problem[i] == '2'){
            if (problem.find("x+", 0) != -1) {
                num = i + 2;
            }
        }
    }

    for (int i = num; i < problem.size(); ++i) {
        if (problem[i] == 'x'){
            break;
        }
        if (problem[i] == ',' || problem[i] == '.') {
            tenth = 10;
        } else {
            b +=(double) (problem[i] - 48) / tenth;
            if (tenth != 1){
                tenth *= 10;
            }
        }
    }
    if (b == 0) {
        if (num == -1){
            return 0;
        }
        return 1;
    }
    return b;
}

double getC(const string& problem){
    double c = 0;
    int num = -1, tenth = 1;
    for (int i = 0; i < problem.size(); ++i) {
        if(problem[i] == 'x'){
            if (i + 2 < problem.size()){
                if (problem[i + 1] == '+'){
                    num = i + 2;
                }
            }
        }
    }

    for (int i = num; i < problem.size(); ++i) {
        if (problem[i] == ',' || problem[i] == '.') {
            tenth = 10;
        } else {
                c += (double) (problem[i] - 48) / tenth;
                if (tenth != 1) {
                    tenth *= 10;
                }
        }
    }
    return c;
}

pair<double, double> quadraticSolution(const double args[]){
    double D = sqrt(args[1]*args[1] - 4 * args[0] * args[2]);
    pair<double, double> x;
    x.first = (-1 * args[1] + D) / (2 * args[0]);
    x.second = (-1 * args[1] - D) / (2 * args[0]);
    return x;
}

double linearSolution(const double args[]){
    return (double) -1 * args[2] / args[1];
}

int Main() {
    string problem;
    cout << "Enter the quadratic polynomial: ";
    cin >> problem;
    double args[3];
    args[0] = getA(problem);
    args[1] = getB(problem);
    args[2] = getC(problem);
    if (args[1]*args[1] - 4 * args[0] * args[2] < 0){
        cout << "This quadratic equation does not have any solutions in real numbers";
        return 0;
    }
    if (args[0] == 0){
        cout << "The answer is " << linearSolution(args) << endl;
    } else {
        pair<double, double> x = quadraticSolution(args);
        cout << "The first solution is " << x.first << " and the second solution " << x.second << endl;
    }
    return 0;
}
