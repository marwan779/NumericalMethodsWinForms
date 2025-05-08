#include "Helper.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace stdext;

double Helper::TableHandler(System::String^ TableData, bool* flag)
{
	std::string tempx = msclr::interop::marshal_as<std::string>(TableData);

	for (int i = 0; i < tempx.length();i++)
	{
		if (tempx[i] == 'x' || tempx[i] == 'X' || tempx[i] == 'y' || tempx[i] == 'Y')
		{
			flag = false;
			return 0.0;
		}
	}

	EquationParser Parser;
	Parser.parseEquation(tempx);
	double x = Parser.evaluate(0);
	*flag = true;
	return x;
	
}
