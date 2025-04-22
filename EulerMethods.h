#ifndef EULER_METHODS_H
#define EULER_METHODS_H

#include <string>
#include <sstream>

class EulerMethod
{
public:
    virtual void solve(const std::string& equation, double x0, double y0, double h, int steps) = 0;
    virtual ~EulerMethod() {}
};

class BasicEuler : public EulerMethod
{
public:
    void solve(const std::string& equation, double x0, double y0, double h, int steps) override;
};

class ModifiedEuler : public EulerMethod
{
public:
    void solve(const std::string& equation, double x0, double y0, double h, int steps) override;
};

// Global buffer to access output
extern std::ostringstream output;
 std::string getEulerOutput();

#endif // EULER_METHODS_H
