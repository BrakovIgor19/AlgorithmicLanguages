#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "ConsoleColor.h"
#include <clocale>


#ifndef Console_H
#define	Console_H

using std::string;

struct Console
{	
	static void gotoxy(short x, short y);
	static short getXcoord();
	static short getYcoord();
	static void SetColor(ConsoleColor text, ConsoleColor background);
	static void ShowCursor(bool showFlag);
	static void SetBufferScreenSize(short width, short height);
	static void SetCoordWindow(short left, short top, short right, short bottom);
	static short GetWidthWindow();
	static short GetHeightWindow();
	static void ReplaceColorRGB(ConsoleColor color, int R, int G, int B);
	static void SetFont(short size, const wchar_t* nameFont); // Во втором параместре писать префикс L перед стрингом
	static void SetTitle(const wchar_t* title); 
};

#endif 
