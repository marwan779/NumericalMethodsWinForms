#include "secant.h"
#include "parser.h"
#include <iostream>
#include <cmath>

using namespace std;

SecantSolver::SecantSolver(string expr, int x0, int x1, double tol, int maxIter)
{
    this->expr = expr;
    this->x0 = x0;
    this->x1 = x1;
    this->tol = tol;
    this->maxIter = maxIter;

    solve();

}


double SecantSolver::solve() {

    EquationParser Parser;

    Parser.parseEquation(expr);
    double f0 = Parser.evaluate(x0);

    Parser.parseEquation(expr);
    double f1 = Parser.evaluate(x1);

    double x2;

    for (int i = 0; i < maxIter; ++i) {
        if (fabs(f1 - f0) < 1e-12) {
            resultStream << "Division by zero error in secant method." << endl;
            return x1;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        Parser.parseEquation(expr);
        double f2 = Parser.evaluate(x2);

        resultStream << "Iteration " << i + 1 << ": x = " << x2 << ", f(x) = " << f2 << endl;

        if (fabs(x2 - x1) < tol) {
            resultStream << "Converged to root: " << x2 << endl;
            return x2;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
    }

    resultStream << "Did not converge within the maximum number of iterations. Last approximation: " << x2 << endl;
    return x2;
}

std::string SecantSolver::GetResult() {
    return resultStream.str();
}