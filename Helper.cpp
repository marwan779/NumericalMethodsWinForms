#include "Helper.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;

double Helper::TableHandler(System::String^ TableData, bool* flag)
{
	std::string tempx = msclr::interop::marshal_as<std::string>(TableData);

	EquationParser Parser;
	Parser.parseEquation(tempx);
	if (Parser.hasX() || Parser.hasY())
	{
		*flag = false;
		return 0.0;
	}

	double x = Parser.evaluate(0);
	*flag = true;
	return x;
	
}
