#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>
#include <unordered_set>

class EquationParser {
public:
    // Constructor
    EquationParser();

    // Configuration
    void setAllowXY(bool allow);

    // Core functionality
    void parseEquation(const std::string& equation);
    double evaluate(double x_value);
    double evaluate(double x_value, double y_value);
    void printPostfix();

    // Getters for variable detection
    bool hasX() const { return has_x; }
    bool hasY() const { return has_y; }

private:
    // Configuration flags
    bool allow_xy;
    bool has_x, has_y;

    // Token storage
    std::vector<std::string> tokens;
    std::vector<std::string> postfix;

    // Supported math functions
    const std::unordered_set<std::string> math_functions = {
        "sin", "cos", "tan", "asin", "acos", "atan",
        "sinh", "cosh", "tanh", "sqrt", "exp", "ln", "log"
    };

    // Mathematical constants
    const std::map<std::string, double> constants = {
        {"pi", 3.14159265358979323846},
        {"e", 2.71828182845904523536}
    };

    // Helper methods
    bool isOperator(char c);
    int precedence(char op);
    bool isFunction(const std::string& token);
    bool isConstant(const std::string& token);
    bool isValidCharacter(char c);
    void validateTokens();
    void convertToPostfix();
};

#endif // PARSER_H