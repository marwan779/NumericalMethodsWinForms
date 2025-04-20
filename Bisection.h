#pragma once

#include <string>
#include <sstream>


using namespace std;
class bisection {
private:
    string expr;
    double a, b, tol;
    int maxIter;
    std::ostringstream resultStream;

public:
    bisection(string expr, int a, int b, double tol, int maxIter);
    void bisection_solve();
    std::string GetResult();
};
