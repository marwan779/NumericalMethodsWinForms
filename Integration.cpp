#include "integration.h"
#include <stdexcept>
#include <cmath>

void NumericalIntegrator::setEquation(const std::string& Equation) {
    parser.parseEquation(Equation);
}

void NumericalIntegrator::setBoundsFromText(const std::string& lowerText, const std::string& upperText) {
    EquationParser temp;
    temp.parseEquation(lowerText);
    a = temp.evaluate(0);

    temp.parseEquation(upperText);
    b = temp.evaluate(0);

    if (b <= a) throw std::runtime_error("Upper bound must be greater than lower bound.");
}

void NumericalIntegrator::setPoints(int numPoints) {
    if (numPoints < 2) throw std::runtime_error("Number of points must be >= 2");
    n = numPoints;
}

void NumericalIntegrator::generateTable() {
    h = (b - a) / (n - 1);
    x.resize(n);
    fx.resize(n);

    for (int i = 0; i < n; i++) {
        x[i] = a + i * h;
        fx[i] = parser.evaluate(x[i]);
    }
}

void NumericalIntegrator::loadTable(const std::vector<std::pair<double, double>>& table) {
    n = table.size();
    x.resize(n);
    fx.resize(n);
    for (int i = 0; i < n; ++i) {
        x[i] = table[i].first;
        fx[i] = table[i].second;
    }

    if (n > 1)
        h = x[1] - x[0];  // Assume equal spacing
}

double NumericalIntegrator::trapezoidalRule() {
    double sum = fx[0] + fx[n - 1];
    for (int i = 1; i < n - 1; i++)
        sum += 2 * fx[i];
    return (h / 2.0) * sum;
}

double NumericalIntegrator::simpsons13Rule() {
    if ((n - 1) % 2 != 0)
        throw std::runtime_error("Simpson's 1/3 Rule requires an even number of intervals.");

    double sum = fx[0] + fx[n - 1];
    for (int i = 1; i < n - 1; i++)
        sum += (i % 2 == 0) ? 2 * fx[i] : 4 * fx[i];
    return (h / 3.0) * sum;
}

double NumericalIntegrator::simpsons38Rule() {
    if ((n - 1) % 3 != 0)
        throw std::runtime_error("Simpson's 3/8 Rule requires intervals divisible by 3.");

    double sum = fx[0] + fx[n - 1];
    for (int i = 1; i < n - 1; i++)
        sum += (i % 3 == 0) ? 2 * fx[i] : 3 * fx[i];
    return (3.0 * h / 8.0) * sum;
}

NumericalIntegrator::NumericalIntegrator() : a(0), b(0), h(0), n(0) {}
