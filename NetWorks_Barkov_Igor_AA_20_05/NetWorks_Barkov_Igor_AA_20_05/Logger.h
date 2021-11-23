#include <iostream>
#include <string>
#include <vector>
#include "ConsoleColor.h"
#include "Console.h"
#include "ConsoleFormatOutIn.h"

#ifndef Logger_H
#define	Logger_H

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Logger
{

public:
	Logger(short left, short top, short right, short bottom, char frameSymbol, ConsoleColor frameSymbolColor, ConsoleColor textColor, ConsoleColor backgroundColor);
	void Update(const string& str);
private:
	
	const short top;
	const short left;
	const short right;
	const short bottom;
	const short height;
	const short width;
	const char frameSymbol;
	const ConsoleColor frameSymbolColor;
	const ConsoleColor backgroundColor;
	const ConsoleColor textColor;
	vector<string> history;
	vector<string> displayedData;
	void DrawData();	
	void DrawFrame(short width, short height, char symbol) const;
};

#endif