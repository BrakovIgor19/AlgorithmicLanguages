#include "Animation.h"

void Animation::Loading(const string& nameLoading, short time)
{
	// Подготовка к рисованию
	system("cls");
	HDC descriptor = GetDC(GetConsoleWindow());	
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(19, 246, 118)), PenFrame = CreatePen(PS_SOLID, 5, RGB(19, 246, 118)), PenClear = CreatePen(PS_SOLID, 300, RGB(0, 0, 0));
	SelectObject(descriptor, Pen);
	//Console::SetFont(15, L"Lucida Console");
	int screenW = GetSystemMetrics(SM_CXSCREEN), screenH = GetSystemMetrics(SM_CYSCREEN);
	int width = 300, height = 60;
	Sleep(1000);

	// Рамочка
	SelectObject(descriptor, PenFrame);
	MoveToEx(descriptor, screenW / 2 - width / 2 - 10, screenH / 2 - height / 2 - 10, NULL);
	LineTo(descriptor, screenW / 2 + width / 2 + 10, screenH / 2 - height / 2 - 10);
	MoveToEx(descriptor, screenW / 2 - width / 2 - 10, screenH / 2 - height / 2 - 10, NULL);
	LineTo(descriptor, screenW / 2 - width / 2 - 10, screenH / 2 + height / 2 + 10);
	MoveToEx(descriptor, screenW / 2 + width / 2 + 10, screenH / 2 + height / 2 + 10, NULL);
	LineTo(descriptor, screenW / 2 + width / 2 + 10, screenH / 2 - height / 2 - 10);
	MoveToEx(descriptor, screenW / 2 + width / 2 + 10, screenH / 2 + height / 2 + 10, NULL);
	LineTo(descriptor, screenW / 2 - width / 2 - 10, screenH / 2 + height / 2 + 10);

	// Запуск загрузки
	Console::gotoxy(Console::GetWidthWindow() / 2 - nameLoading.size() / 2, Console::GetHeightWindow() / 2 );
	cout << nameLoading << " ";
	short bufX = Console::getXcoord(), bufY = Console::getYcoord();
	int persent = 0;
	for (int i = 0; i < width; ++i)
	{
		if (i * 100 / width >= persent)
		{
			Console::gotoxy(bufX, bufY);
			cout << persent<< " %";
			++persent;			
		}
		MoveToEx(descriptor, screenW / 2 - width / 2 + i, screenH / 2 - height / 2 , NULL);
		LineTo(descriptor, screenW / 2 - width / 2 + i, screenH / 2 + height / 2);
		Sleep(time / width);
	}
	Console::gotoxy(bufX, bufY);
	cout << 100 << " %";

	// Очистка
	SelectObject(descriptor, PenClear);
	MoveToEx(descriptor, 0, screenH / 2, NULL);
	LineTo(descriptor, screenW , screenH / 2);
	ReleaseDC(NULL, descriptor);
	system("cls");
}
