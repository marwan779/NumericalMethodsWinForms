#pragma once
#include <vector>

class LagrangeInterpolator {
private:
    std::vector<double> x;
    std::vector<double> y;

public:
    LagrangeInterpolator(const std::vector<double>& xData, const std::vector<double>& yData);

    // Interpolates to find Y given X
    double interpolateY(double xValue) const;

    // Interpolates to find X given Y (inverse interpolation)
    double interpolateInverse(double yValue) const;
};
