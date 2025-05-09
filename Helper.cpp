#include "Helper.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace stdext;

double Helper::TableHandler(System::String^ TableData, bool* flag)
{
	std::string tempx = msclr::interop::marshal_as<std::string>(TableData);

	EquationParser Parser;
	Parser.parseEquation(tempx);
	if (Parser.has_x || Parser.has_y)
	{
		*flag = false;
		return 0.0;
	}

	double x = Parser.evaluate(0);
	*flag = true;
	return x;
	
}
