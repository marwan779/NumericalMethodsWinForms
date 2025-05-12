# Numerical Methods WinForms Application

## Overview

This repository contains a C++/WinForms implementation of various numerical methods for mathematical computations. The application provides both a graphical interface and core numerical algorithms for solving equations, interpolation, integration, and differential equations. The system features a robust equation parser, multiple root-finding techniques, and support for handling both explicit and implicit functions.

![Application Interface]

![Screenshot (84)](https://github.com/user-attachments/assets/30da17aa-effc-4c09-8a86-0d6dcb9d59b7)
![Screenshot (85)](https://github.com/user-attachments/assets/10e605bd-d492-469d-a4c5-4cf7d9b80279)
![Screenshot (86)](https://github.com/user-attachments/assets/71b7823d-cf54-4bc9-9d4e-7f83d7df3801)
![Screenshot (87)](https://github.com/user-attachments/assets/d6f7f1e6-c092-4a4c-80a7-afc3387177a2)
![Screenshot (88)](https://github.com/user-attachments/assets/e6b01d01-da52-467c-8089-127fed453ca7)
![Screenshot (89)](https://github.com/user-attachments/assets/8134218b-200c-441c-aa65-aed82714fcfd)
![Screenshot (91)](https://github.com/user-attachments/assets/358c2bab-24f6-45ed-ad92-abf6c730acf8)
![Screenshot (92)](https://github.com/user-attachments/assets/fe046f20-e97a-47e4-9220-305d1c2e6ad0)

## Key Features

### 1. **Equation Parser Engine**
- Supports variables `x` and `y`
- Handles mathematical functions (`sin`, `cos`, `exp`, etc.)
- Recognizes constants (`pi`, `e`)
- Validates equation syntax and parentheses
- Uses shunting yard algorithm 
- Converts infix to postfix notation
- Error handling for invalid expressions

### 2. Root Finding Methods
| Method          | Features                              |
|-----------------|---------------------------------------|
| **Bisection**   | Guaranteed convergence, error bounds  |
| **Secant**      | Fast convergence, derivative-free    |

### 3. Numerical Integration
- Trapezoidal Rule
- Simpson's 1/3 Rule
- Simpson's 3/8 Rule
- Automatic table generation
- Custom point input support

### 4. Ordinary Differential Equations
- Basic Euler Method
- Modified Euler (Heun's) Method
- Step size control
- Tabular solution output

### 5. Interpolation
- Lagrange and Newton Polynomial Interpolation
- Inverse interpolation support
- Error estimation

## Installation

### Requirements
- Windows 10/11
- .NET Framework 4.8
- Visual Studio 2022 (for development)
- C++17 compatible compiler

### Quick Start
1. Download pre-built binary from [Releases](https://github.com/marwan779/NumericalMethodsWinForms/releases)
2. Run `NumericalMethods.exe`
3. Enter equation in supported format:
   - Example: `sin(x)*exp(-0.1*x)`
   - Example: `log(2*y) + sqrt(pi)`

### Build from Source
```bash
git clone https://github.com/marwan779/NumericalMethodsWinForms.git
cd NumericalMethodsWinForms
# Open NumericalMethods.sln in Visual Studio
# Build Solution (Ctrl+Shift+B)
```

## Usage Guide

### Root Finding Example
```cpp
// Using Bisection Method
bisection solver("exp(x) - x^2", 0, 1, 1e-6, 100);
cout << solver.GetResult();
```

### ODE Solving
```cpp
BasicEuler euler;
euler.solve("y - x^2 + 1", 0, 0.5, 0.1, 10);
cout << getEulerOutput();
```

### Equation Parsing
```cpp
EquationParser parser;
parser.parseEquation("sin(pi*x) + 0.5*y");
double result = parser.evaluate(0.5, 1.0);
```

## Error Handling

The system detects and reports:
- Mathematical errors (division by zero, sqrt of negatives)
- Syntax errors in equations
- Convergence failures
- Invalid input ranges
- Numerical instability issues

## Development Guidelines

### Coding Standards
- Follow RAII principles for resource management
- Use `const` correctness
- Exception safety guarantees
- Doxygen-style comments for public APIs
- 4-space indentation, Allman style braces

### Testing
```cpp
// Example test case for parser
TEST(EquationParserTest, HandlesBasicOperations) {
    EquationParser parser;
    parser.parseEquation("2+3*4");
    ASSERT_NEAR(parser.evaluate(0), 14.0, 1e-6);
}
```


**Contributors**:  
- Marwan ([@marwan779](https://github.com/marwan779))
- Abdelhamid ([@Abdelhamid108](https://github.com/Abdelhamid108))
- Yehia Hamdy ([@YHS003](https://github.com/YHS003))
- Fady Ahsraf ([fady1559](https://github.com/fady1559))
- Ahmed Kandil ([@Ahmed-Kandil11](https://github.com/Ahmed-Kandil11))

  
