#include <string>
#include <functional>
#include <vector>
#include <conio.h>
#include "CheckingInput.h"
#include "ConsoleFormatOutIn.h"
#include "Logger.h"


using std::string;
using std::function;
using std::vector;
using std::to_string;


#ifndef KCInspections_H
#define	KCInspections_H

struct KCInspections
{
	static vector<function<string(Logger&, bool, string&)>> kcInspections;
	static string CheckId(Logger& log, bool correctInput, string& str);
	static string CheckName(Logger& log, bool correctInput, string& str);
	static string CheckNumberWorkshops(Logger& log, bool correctInput, string& str);
	static string ChecknumberWorkshopsOperation(Logger& log, bool correctInput, string& str);
	static string CheckEffectiveness(Logger& log, bool correctInput, string& str);
};

#endif
