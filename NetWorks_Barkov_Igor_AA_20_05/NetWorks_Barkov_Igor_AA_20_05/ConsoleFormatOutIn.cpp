#include "ConsoleFormatOutIn.h"


string ConsoleFormatOutIn::ReadStringWithoutMovingCursor()
{
	short bufX, bufY;
	string str;
	bufX = Console::getXcoord(); bufY = Console::getYcoord();
	getline(cin, str);
	Console::gotoxy(bufX, bufY);
	return str;
}

void ConsoleFormatOutIn::WriteTextCenterThisCoord(short x, short y, const string& text)
{
	Console::gotoxy(x - (text.size() / 2), y);
	cout << text;
}

void ConsoleFormatOutIn::OutputVectorStringColumnAlignedRight(short left, short top, const vector <string>& vectorStr, const vector <string>& vectorDate)
{


	// Найдем строку максимально длины
	int maxLength = AuxiliaryFunctions::FindMaxLengthVectorStr(vectorStr);

	// Выводим массив строк
	for (int i = 0; i < vectorStr.size(); ++i)
	{
		// Переходим Переходим на новую строку и выводим 
		Console::gotoxy(left, top + i);
		cout << setw(maxLength) << vectorStr[i] << " " << vectorDate[i];
	}
}

void ConsoleFormatOutIn::PaintTextBackground(short x, short y, const string& str, ConsoleColor text, ConsoleColor background)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	GetConsoleScreenBufferInfo(descriptor, &screenBuffer);
	Console::gotoxy(x, y);
	Console::SetColor(text, background);
	cout << str;
	Console::gotoxy(x, y);
	SetConsoleTextAttribute(descriptor, screenBuffer.wAttributes);
}