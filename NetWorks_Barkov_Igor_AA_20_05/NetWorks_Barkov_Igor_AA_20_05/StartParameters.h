#include "Console.h"

#ifndef StartParameters_H
#define	StartParameters_H

struct StartParameters
{
	static void SetStartParameters()
	{
		 Console::ReplaceColorRGB(Green, 11, 102, 46);
		 Console::ReplaceColorRGB(LightGreen, 19, 246, 118);
		 /*0 - значение цвета фона, A - значение цвета текста
		Расшифровка цветов:
		0 = Black 8 = Gray
		1 = Blue 9 = Light Blue
		2 = Green A = Light Green
		3 = Aqua B = Light Aqua
		4 = Red C = Light Red
		5 = Purple D = Light Purple
		6 = Yellow E = Light Yellow
		7 = White F = Bright White*/
		 system("color 0A");
		 Console::SetBufferScreenSize(135, 120);
		 Console::SetCoordWindow(0, 0, 134, 43);
		 Console::SetTitle(L"Терминал трубопроводой сети");
		 setlocale(LC_CTYPE, "rus");
		 Console::SetFont(10, L"Lucida Console");
		 Console::SetColor(LightGreen, Black);
		 Console::ShowCursor(false);
	}
};

#endif 
