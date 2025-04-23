#include "EulerMethods.h"
#include "parser.h"
#include <sstream>
#include <iomanip>

// Basic Euler Implementation
void BasicEuler::solve(const std::string& equation, double x0, double y0, double h, int steps)
{
    EquationParser parser;
    parser.setAllowXY(true);
    parser.parseEquation(equation);

    output.str("");  // clear previous content
    output.clear();

    output << "Basic Euler Method:\n";
    output << std::fixed << std::setprecision(6);
    output << std::setw(6) << "Step" << std::setw(15) << "x" << std::setw(15) << "y\n";
    output << "----------------------------------------\n";

    for (int i = 0; i < steps; ++i)
    {
        double f = parser.evaluate(x0, y0);
        y0 += h * f;
        x0 += h;
        output << std::setw(6) << i + 1 << std::setw(15) << x0 << std::setw(15) << y0 << "\n";
    }
}

// Modified Euler Implementation
void ModifiedEuler::solve(const std::string& equation, double x0, double y0, double h, int steps)
{
    EquationParser parser;
    parser.setAllowXY(true);
    parser.parseEquation(equation);

    output.str("");  // clear previous content
    output.clear();

    output << "Modified Euler Method:\n";
    output << std::fixed << std::setprecision(6);
    output << std::setw(6) << "Step" << std::setw(15) << "x" << std::setw(15) << "y\n";
    output << "----------------------------------------\n";

    for (int i = 0; i < steps; ++i)
    {
        double k1 = parser.evaluate(x0, y0);
        double k2 = parser.evaluate(x0 + h, y0 + h * k1);
        y0 += h * (k1 + k2) / 2;
        x0 += h;
        output << std::setw(6) << i + 1 << std::setw(15) << x0 << std::setw(15) << y0 << "\n";
    }
}

// Shared output buffer
std::ostringstream output;

// Getter for output
std::string getEulerOutput() {
    return output.str();
}
