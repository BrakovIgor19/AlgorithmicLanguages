#include <string>
#include <functional>
#include <vector>
#include <conio.h>
#include "CheckingInput.h"
#include "ConsoleFormatOutIn.h"
#include "ConsoleKey.h"

using std::string;
using std::function;
using std::vector;
using std::to_string;


#ifndef PipeInspections_H
#define	PipeInspections_H

struct PipeInspections
{
	static vector<function<string(short, short, bool, bool, string)>> pipeInspections;
	static string CheckId(short xError, short yError, bool showError, bool flag, string str);
	static string CheckLenght(short xError, short yError, bool showError, bool flag, string str);
	static string CheckDiameter(short xError, short yError, bool showError, bool flag, string str);
	static string CheckSignRepair(short xError, short yError, bool showError, bool flag, string str);
};

#endif 
