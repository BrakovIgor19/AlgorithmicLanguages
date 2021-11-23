#include <string>
#include <functional>
#include <vector>
#include <conio.h>
#include "CheckingInput.h"
#include "ConsoleFormatOutIn.h"
#include "ConsoleKey.h"
#include "Logger.h"

using std::string;
using std::function;
using std::vector;
using std::to_string;


#ifndef PipeInspections_H
#define	PipeInspections_H

struct PipeInspections
{
	static vector<function<string(Logger&, bool, string&)>> pipeInspections;
	static string CheckId(Logger &log, bool correctInput, string &str);
	static string CheckLenght(Logger &log, bool correctInput, string &str);
	static string CheckDiameter(Logger &log, bool correctInput, string &str);
	static string CheckSignRepair(Logger &log, bool correctInput, string &str);
};

#endif 
