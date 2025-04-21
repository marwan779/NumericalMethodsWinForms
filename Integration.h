#ifndef INTEGRATION_H  
#define INTEGRATION_H  

#include <vector>  
#include <string>  
#include "parser.h"  

class NumericalIntegrator {  
public:  
   std::vector<double> x, fx;  
   double a, b, h;  
   int n;  

   EquationParser parser;  

   NumericalIntegrator();  
   void setEquation(const std::string& Equation);  
   void setBoundsFromText(const std::string& lowerText, const std::string& upperText);  
   void setPoints(int numPoints);  
   void generateTable();  
   void loadTable(const std::vector<std::pair<double, double>>& table);  
   double trapezoidalRule();  
   double simpsons13Rule();  
   double simpsons38Rule();  
};  

#endif
