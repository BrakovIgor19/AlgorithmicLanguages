#include <string>
#include <vector>
#include "Console.h"
#include "ConsoleFormatOutIn.h"
#include <conio.h>
#include "ConsoleKey.h"
#include <mmsystem.h> 
#include <dos.h>

using std::string;
using std::vector;

#ifndef Menu_H
#define	Menu_H

class Menu
{
public:
	static short ShowMenuCenter(const vector<string> &strMenu);
	static short ActiveMenuAlignedRight(short x, short y, const vector<string> &strMenu);
private:
	static void DrawMenu(const vector<string> &strMenu, short firstLineMenu, short activeMenu);
	static short activeMenu;

};

#endif 
