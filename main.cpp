#include <iostream>
#include <string>
#include "main.h"
#include <cmath>

using namespace std;

double getA(const string& problem){
    int a, tenth = 1;

    for (char i : problem) {
        if (i == 'x'){
            break;
        }
        if (a == ',' || a == '.') {
            tenth = 10;
        } else {
            a = (i - 48) / tenth;
            if (tenth != 1){
                tenth *= 10;
            }
        }
    }
    return a;
}

double getB(const string& problem){
    int b, tenth = 1, num;
    for (int i = 0; i < problem.size(); ++i) {
        if(problem[i] == '2' && problem[i + 1] == '+'){
            num = i + 2;
        }
    }

    for (int i = num; i < problem.size(); ++i) {
        if (i == 'x'){
            break;
        }
        if (b == ',' || b == '.') {
            tenth = 10;
        } else {
            b = (i - 48) / tenth;
            if (tenth != 1){
                tenth *= 10;
            }
        }
    }
    return b;
}

double getC(const string& problem){
    int c, num, tenth;
    for (int i = 0; i < problem.size(); ++i) {
        if(problem[i] == 'x' && problem[i + 1] == '+'){
            num = i + 2;
        }
    }

    for (int i = num; i < problem.size(); ++i) {
        if (i == 'x'){
            break;
        }
        if (c == ',' || c == '.') {
            tenth = 10;
        } else {
            c = (i - 48) / tenth;
            if (tenth != 1){
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

double linearSolution(double args[]){
    return -1 * args[2] / args[1];
}

int main() {
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
