#ifndef DIVIDED_DIFFERENCE_INTERPOLATOR_H
#define DIVIDED_DIFFERENCE_INTERPOLATOR_H


#include <vector>

#using <System.Windows.Forms.dll>

using namespace System::Windows::Forms;

class divide {
public:
    int n;
    double x[20], f[20][20], XX, P1;

    divide();
    void setData(std::vector<double> xVec, std::vector<double> yVec, double inputXX, RichTextBox^ outputBox);
    void diffTable(RichTextBox^ outputBox);
    void calcP(RichTextBox^ outputBox);
};


#endif // DIVIDED_DIFFERENCE_INTERPOLATOR_H