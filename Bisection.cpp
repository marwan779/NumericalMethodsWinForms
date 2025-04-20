#include "Parser.h"
#include "Bisection.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bisection::bisection(string expr, int a, int b, double tol, int maxIter)
{
    this->expr = expr;
    this->a = a;
    this->b = b;
    this->tol = tol;
    this->maxIter = maxIter;

    bisection_solve();

}

void bisection::bisection_solve()
{
    EquationParser Parser;

    Parser.parseEquation(expr);
    double fa = Parser.evaluate(a);

    Parser.parseEquation(expr);
    double fb = Parser.evaluate(b);

    if (fa * fb >= 0) {
        resultStream << "No sign change: f(a) and f(b) must have opposite signs.\n";
        return;
    }

    resultStream << left << setw(15) << "Iter"
        << setw(25) << "a"
        << setw(25) << "b"
        << setw(25) << "c"
        << setw(25) << "f(c)" << "\n";

    resultStream << fixed << setprecision(6);

    for (int i = 1; i <= maxIter; ++i) {
        double c = (a + b) / 2;
        Parser.parseEquation(expr);
        double fc = Parser.evaluate(c);

        resultStream << left << setw(8) << i
            << setw(20) << a
            << setw(20) << b
            << setw(20) << c
            << setw(20) << fc << "\n";

        if (fabs(fc) < tol) {
            resultStream << "\nRoot found: " << c << "\n";
            return;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }

    resultStream << "\nApproximate root after max iterations: " << (a + b) / 2 << "\n";
}

std::string bisection::GetResult() {
    return resultStream.str();
}