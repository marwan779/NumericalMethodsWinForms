#include "DividedDifferenceInterpolator.h"
#include <iomanip>
#include <sstream>

using namespace std;

divide::divide() {
    // Do nothing, setData will be used instead 
}

void divide::setData(vector<double> xVec, vector<double> yVec, double inputXX, RichTextBox^ outputBox) {
    n = xVec.size();

    for (int i = 0; i < n; i++) {
        x[i] = xVec[i];
        f[0][i] = yVec[i];
    }

    XX = inputXX;

    double minX = x[0], maxX = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < minX) minX = x[i];
        if (x[i] > maxX) maxX = x[i];
    }

    if (XX < minX || XX > maxX) {
        outputBox->AppendText("⚠️ Warning: X = " + XX.ToString("F2") + " is outside the interpolation range [" +
            minX.ToString("F2") + ", " + maxX.ToString("F2") + "].\n");
        outputBox->AppendText("The result might be less accurate (this is extrapolation).\n\n");
    }

    diffTable(outputBox);
    calcP(outputBox);
}

void divide::diffTable(RichTextBox^ outputBox) {
    std::ostringstream oss;

    if (abs(XX - x[0]) < abs(XX - x[n - 1])) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                f[i][j] = (f[i - 1][j + 1] - f[i - 1][j]) / (x[i + j] - x[j]);
            }
        }

        oss << "\nSn\tXi\tf(Xi)\t";
        for (int i = 0; i < n - 1; i++) oss << i + 1 << " diff\t";
        oss << "\n";

        for (int i = 0; i < n; i++) {
            oss << i + 1 << "\t" << x[i] << "\t";
            for (int j = 0; j < n - i; j++) {
                oss << fixed << setprecision(4) << f[j][i] << "\t";
            }
            oss << "\n";
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                f[i][j] = (f[i - 1][j] - f[i - 1][j - 1]) / (x[j] - x[j - i]);
            }
        }

        oss << "\nSn\tXi\tf(Xi)\t";
        for (int i = 0; i < n - 1; i++) oss << i + 1 << " diff\t";
        oss << "\n";

        for (int i = 0; i < n; i++) {
            oss << i + 1 << "\t" << x[i] << "\t";
            for (int j = 0; j <= i; j++) {
                oss << fixed << setprecision(4) << f[j][i] << "\t";
            }
            oss << "\n";
        }
    }

    outputBox->AppendText(gcnew System::String(oss.str().c_str()));
}

void divide::calcP(RichTextBox^ outputBox) {
    if (abs(XX - x[0]) < abs(XX - x[n - 1])) {
        P1 = 0;
        for (int i = 0; i < n; i++) {
            double k = 1;
            for (int j = 0; j < i; j++) {
                k *= (XX - x[j]);
            }
            P1 += k * f[i][0];
        }
    }
    else {
        P1 = 0;
        for (int i = 0; i < n; i++) {
            double k = 1;
            for (int j = 0; j < i; j++) {
                k *= (XX - x[n - 1 - j]);
            }
            P1 += k * f[i][n - 1];
        }
    }

    outputBox->AppendText("\nThe value of P" + (n - 1).ToString() + "(" + XX.ToString("F2") + ") = " + P1.ToString("F6") + "\n\n");
}
