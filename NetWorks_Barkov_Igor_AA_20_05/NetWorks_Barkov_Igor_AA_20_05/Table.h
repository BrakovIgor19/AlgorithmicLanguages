#include <string>
#include "ConsoleColor.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <functional>
#include "Console.h"
#include "ConsoleFormatOutIn.h"
#include "ConsoleKey.h"
#include "Logger.h"

#ifndef Table_H
#define	Table_H

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::function;

enum Type {
    Int = 0,
    Real = 1,
    String = 2
};


class Table
{
public:
	vector<vector<string>> date;
    vector<int> filterDateIndex;
	Table(short left, short top, const vector<int> &heightLines, const vector<int> &widthColumns, char symbol, const vector<vector<string>> &date, vector<function<string (Logger&, bool, string&)>> inspections);
    void Draw(const vector<int> &filterDateIndex);
    void Add();
    void Delete();
    void Edit();
    short GetRightX();
    short GetRightY();
    void ConnectLogger(Logger &log);
private:
    vector<Type> columnsType;
    vector<vector<vector<int>>> cellCoords;
    vector<int> activeCell = {0, 1};
    vector<function<string(Logger&, bool, string&)>> inspections;
    const int left;
    const int top;
    vector<int> heightLines;
    vector<int> widthColumns;
    const char symbol;
	void DrawCell(int width, int height, char symbol) const;
    void RepaintActiveCell(ConsoleColor text, ConsoleColor background);
    bool SelectStr();
    bool SelectCell();
    void EditCell(bool flag);
    Logger *log;

};

#endif 
