#include "LagrangeInterpolator.h"

LagrangeInterpolator::LagrangeInterpolator(const std::vector<double>& xData, const std::vector<double>& yData)
    : x(xData), y(yData) {
}

double LagrangeInterpolator::interpolateY(double xValue) const {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                // Build Lagrange basis polynomial L_i(x)
                term *= (xValue - x[j]) / (x[i] - x[j]);
            }
        }
        // Add contribution of the current term to the final result
        result += term;
    }

    return result;
}

double LagrangeInterpolator::interpolateInverse(double yValue) const {
    // Swap x and y to perform inverse interpolation (estimate X from Y)
    std::vector<double> reversedX = y;
    std::vector<double> reversedY = x;

    // Create a new interpolator with swapped data
    LagrangeInterpolator inverseInterpolator(reversedX, reversedY);

    // Use the regular interpolateY to find X
    return inverseInterpolator.interpolateY(yValue);
}
