#include "Console.h"

short Console::getXcoord()
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	GetConsoleScreenBufferInfo(descriptor, &screenBuffer);
	return screenBuffer.dwCursorPosition.X;
}

short Console::getYcoord()
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	GetConsoleScreenBufferInfo(descriptor, &screenBuffer);
	return screenBuffer.dwCursorPosition.Y;
}

void Console::gotoxy(short x, short y)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(descriptor, {x, y});
}

void Console::SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(descriptor, (WORD)((background << 4) | text));  
}

void Console::ShowCursor(bool showFlag)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorBuffer;
	GetConsoleCursorInfo(descriptor, &cursorBuffer);
	cursorBuffer.bVisible = showFlag; 
	SetConsoleCursorInfo(descriptor, &cursorBuffer);
}

void Console::SetBufferScreenSize(short width, short height)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = { width, height };
	SetConsoleScreenBufferSize(descriptor, size);
}

void Console::SetCoordWindow(short left, short top, short right, short bottom)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT coord = { left, top, right, bottom };
	SetConsoleWindowInfo(descriptor, TRUE, &coord);
}

short Console::GetWidthWindow()
{
	HANDLE desriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	GetConsoleScreenBufferInfo(desriptor, &screenBuffer);
	return screenBuffer.srWindow.Right - screenBuffer.srWindow.Left;

}

short Console::GetHeightWindow()
{
	HANDLE desriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	GetConsoleScreenBufferInfo(desriptor, &screenBuffer);
	return screenBuffer.srWindow.Bottom - screenBuffer.srWindow.Top;
}

void Console::ReplaceColorRGB(ConsoleColor color, int R, int G, int B)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferEx;
	screenBufferEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX); // Задать размер структуры
	GetConsoleScreenBufferInfoEx(descriptor, &screenBufferEx);
	screenBufferEx.ColorTable[color] = RGB(R, G, B);
	SetConsoleScreenBufferInfoEx(descriptor, &screenBufferEx);
}

void Console::SetFont(short size, const wchar_t* nameFont)
{
	HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	GetCurrentConsoleFontEx(descriptor, TRUE, &font);
	wcscpy(font.FaceName, nameFont);
	font.dwFontSize.X = size;
	font.dwFontSize.Y = (5 * size) / 3;
	// Установить новый шрифт консоли
	SetCurrentConsoleFontEx(descriptor, TRUE, &font); // Установить новый
}

void Console::SetTitle(const wchar_t *title)
{
	SetConsoleTitle(title);
}

