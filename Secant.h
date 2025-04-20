#pragma once

#include <string>
#include <sstream>

using namespace std;

class SecantSolver {
private:

    string expr;
    double x0, x1, tol;
    int maxIter;
    std::ostringstream resultStream;
public:
    SecantSolver(string expr, int x0, int x1, double tol, int maxIter);
    double solve();
    std::string GetResult();
};