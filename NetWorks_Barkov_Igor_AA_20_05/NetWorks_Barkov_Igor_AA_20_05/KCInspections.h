#include <string>
#include <functional>
#include <vector>
#include <conio.h>
#include "CheckingInput.h"
#include "ConsoleFormatOutIn.h"



using std::string;
using std::function;
using std::vector;
using std::to_string;


#ifndef KCInspections_H
#define	KCInspections_H

struct KCInspections
{
	static vector<function<string(short, short, bool, bool, string)>> kcInspections;
	static string CheckId(short xError, short yError, bool showError, bool flag, string str);
	static string CheckName(short xError, short yError, bool showError, bool flag, string str);
	static string CheckNumberWorkshops(short xError, short yError, bool showError, bool flag, string str);
	static string ChecknumberWorkshopsOperation(short xError, short yError, bool showError, bool flag, string str);
	static string CheckEffectiveness(short xError, short yError, bool showError, bool flag, string str);
};

#endif
