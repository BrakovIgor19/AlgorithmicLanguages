#include "Map.h"


Map::Map()
{
	RECT rectConsole;
	HWND hWnd = GetForegroundWindow();
	GetClientRect(hWnd, &rectConsole);
	int width = Console::GetWidthWindow();
	ratio = (double)(rectConsole.right - rectConsole.left)/Console::GetWidthWindow();
	massivPoint.reserve(100);
	radius = 10;
}

void Map::Open()
{
	system("cls");
	// Отрисуем начальное МэйнМеню
	Draw();
	while (true)
	{
		if (SetMainMenu())
		{
			switch (activeMainMenu)
			{
			case 0:
			{
				AddKC();
				break;
			}
			case 1:
			{
				AddPipe();
				break;
			}
			case 2:
			{
				DeleteKC();
				break;
			}
			case 3:
			{
				DeletePipe();
				break;
			}
			}
		}
		else
		{
			break;
		}
	}
}

void Map::ConnectTable(NetWorks& netWork)
{
	this->netWork = &netWork;
}

bool Map::SetMainMenu()
{
	int left = 15, top = 15;
	int width = 190, height = 90, between = 10;
	vector<int> bufArray; bufArray.reserve(TextDate::mapMenu.size());
	for (int i = 0; i < TextDate::mapMenu.size(); ++i)
	{
		bufArray.push_back((left + between + width / 2 + i * (width + between))/ratio);
	}

	for (int i = 0; i < TextDate::mapMenu.size(); ++i)
	{
		ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[i], 2,TextDate::mapMenu[i]);
	}

	for (int i = 0; i < TextDate::mapMenu.size(); ++i)
	{
		DrawFrame(left + i * (width + between) + between, top, left + (width + between) * (i + 1), height - top, 4, LightGreen);

	}
	Console::SetColor(LightGreen, Green);
	DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, Green);
	ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
	int key;
	while (true)
	{
		key = _getch();
		if (key == -32)
		{
			key = _getch();
		}
		switch (key)
		{
		case ENTER:
		{
			PlaySoundA("ui_menu_prevnext.wav", NULL, SND_ASYNC);
			DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, LightGreen);
			Console::SetColor(Black, LightGreen);
			ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
			for (int i = 0; i < TextDate::mapMenu.size(); ++i)
			{
				DrawFrame(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen);

			}
			Console::SetColor(LightGreen, Black);
			return true;
		}
		case ESC:
		{
			PlaySoundA("ui_menu_cancel.wav", NULL, SND_ASYNC);			
			Sleep(1000);
			Clear();
			Console::SetColor(LightGreen, Black);
			return false;
		}
		case LEFT:
		{
			if (activeMainMenu > 0)
			{
				DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, Black);
				Console::SetColor(LightGreen, Black);
				ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
				for (int i = 0; i < TextDate::mapMenu.size(); ++i)
				{
					DrawFrame(left + i * (width + between) + between, top, left + (width + between) * (i + 1), height - top, 4, LightGreen);

				}
				PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
				--activeMainMenu;
				DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, Green);
				Console::SetColor(LightGreen, Green);
				ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
				for (int i = 0; i < TextDate::mapMenu.size(); ++i)
				{
					DrawFrame(left + i * (width + between) + between, top, left + (width + between) * (i + 1), height - top, 4, LightGreen);

				}
			}
			break;
		}
		case RIGHT:
		{
			if (activeMainMenu < TextDate::mapMenu.size() - 1)
			{
				DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, Black);
				Console::SetColor(LightGreen, Black);
				ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
				for (int i = 0; i < TextDate::mapMenu.size(); ++i)
				{
					DrawFrame(left + i * (width + between) + between, top, left + (width + between) * (i + 1), height - top, 4, LightGreen);
				}
				PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
				++activeMainMenu;
				DrawRectangle(left + activeMainMenu * (width + between) + between, top, left + (width + between) * (activeMainMenu + 1), height - top, 4, LightGreen, Green);
				Console::SetColor(LightGreen, Green);
				ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[activeMainMenu], 2, TextDate::mapMenu[activeMainMenu]);
				for (int i = 0; i < TextDate::mapMenu.size(); ++i)
				{
					DrawFrame(left + i * (width + between) + between, top, left + (width + between) * (i + 1), height - top, 4, LightGreen);
				}
			}
			break;
		}
		}
	}
}

void Map::DrawFrame(int left, int top, int right, int bottom, int width, ConsoleColor frameColor)
{
	HWND hwnd = GetConsoleWindow();
	HDC descriptor = GetDC(hwnd);
	ChoosePen(descriptor, width, frameColor);
	MoveToEx(descriptor, left, top, NULL);
	LineTo(descriptor, right, top);
	MoveToEx(descriptor, left, top, NULL);
	LineTo(descriptor, left, bottom);
	MoveToEx(descriptor, right, bottom, NULL);
	LineTo(descriptor, left, bottom);
	MoveToEx(descriptor, right, bottom, NULL);
	LineTo(descriptor, right, top);
	DeleteObject(Pen);
	ReleaseDC(hwnd, descriptor);
}

void Map::DrawRectangle(int left, int top, int right, int bottom, int width, ConsoleColor frameColor, ConsoleColor fillColor)
{
	HWND hwnd = GetConsoleWindow();
	HDC descriptor = GetDC(hwnd);
	ChoosePen(descriptor, 4, frameColor);
	ChooseBrush(descriptor, fillColor);
	Rectangle(descriptor, left, top, right, bottom);
	DeleteObject(Pen);
	DeleteObject(Brush);
	ReleaseDC(hwnd, descriptor);
}

void Map::DrawCircle(int x0, int y0, int radius, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor)
{
	HWND hwnd = GetConsoleWindow();
	HDC descriptor = GetDC(hwnd);
	ChoosePen(descriptor, 4, frameColor);
	ChooseBrush(descriptor, fillColor);
	Ellipse(descriptor, x0 - radius, y0 - radius, x0 + radius, y0 + radius);
	DeleteObject(Pen);
	DeleteObject(Brush);
	ReleaseDC(hwnd, descriptor);
}

void Map::DrawArrow(pair<int, int> point1, pair<int, int> point2, ConsoleColor color)
{
	HWND hwnd = GetConsoleWindow();
	HDC descriptor = GetDC(hwnd);
	ChoosePen(descriptor, 2, color);
	ChooseBrush(descriptor, color);
	int width = 10, side = 5;  double distance = sqrt(pow(abs(point1.first) - abs(point2.first), 2) + pow(abs(point1.second) - abs(point2.second), 2)), Cos = (double)((point2.first - point1.first) / distance), Sin = (double)((point1.second - point2.second) / distance);
	MoveToEx(descriptor, point1.first, point1.second, NULL);
	LineTo(descriptor, point2.first, point2.second);
	
	POINT ptTriangle[3] = { {point2.first - radius * Cos, point2.second + radius * Sin},
		                  {point2.first - 3 * radius * Cos - Sin * side, point2.second + 3 * radius * Sin - Cos * side},
						  {point2.first - 3 * radius * Cos + Sin * side, point2.second + 3 * radius * Sin + Cos * side}};
	 // Полигональная область стрелки
	Polygon(descriptor, ptTriangle, 3);
	ReleaseDC(hwnd, descriptor);
}

void Map::Draw()
{
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		DrawArrow({ massivEdges[i].first.first.first, massivEdges[i].first.first.second }, { massivEdges[i].first.second.first, massivEdges[i].first.second.second }, massivEdges[i].second);
	}
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		DrawCircle(massivPoint[i].first.first, massivPoint[i].first.second, radius, 3, massivPoint[i].second.first, massivPoint[i].second.second);
	}
}

void Map::Clear()
{
	system("cls");
	RECT rectConsole;
	HWND hwnd = GetForegroundWindow();
	GetClientRect(hwnd, &rectConsole);
	HDC descriptor = GetDC(hwnd);
	ChoosePen(descriptor, 1, Black);
	ChooseBrush(descriptor, Black);
	// Очистка
	DrawRectangle(rectConsole.left, rectConsole.top, rectConsole.right, rectConsole.bottom, 1, Black, Black);
	ReleaseDC(hwnd, descriptor);
}

void Map::AddKC()
{
	//HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, L"C:\\LightGreenKC.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	//HWND hWnd = GetForegroundWindow();
	//HDC hdc = GetDC(hWnd);
	//HDC memBit = CreateCompatibleDC(hdc);
	//SelectObject(memBit, hBitmap);
	//BitBlt(hdc, 0, 0, 272, 259, memBit, 0, 0, SRCCOPY);
	//DeleteDC(memBit);
	//DeleteObject(hBitmap);
	RECT rectConsole;
	HWND hWnd = GetForegroundWindow();
	HDC descriptor = GetDC(hWnd);
	GetClientRect(hWnd, &rectConsole);
	int x = 75, y = 150, speed = 15;
	int key;
	DrawCircle(x, y, radius, 1, LightGreen, LightGreen);
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		massivPoint[i].second.first = Green;
		massivPoint[i].second.second = Green;
	}
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		massivEdges[i].second = Green;
	}
	Draw();
	while (true)
	{
		DrawCircle(x, y, radius, 1, LightGreen, LightGreen);
		key = _getch();
		if (key == -32)
		{
			key = _getch();
		}
		switch (key)
		{
			case ENTER:
			{ 

				massivPoint.push_back({ {x, y}, {LightGreen, LightGreen} });
				activePoint = massivPoint.size() - 1;
				for (int i = 0; i < massivPoint.size(); ++i)
				{
					massivPoint[i].second.first = LightGreen;
					massivPoint[i].second.second = LightGreen;
				}
				for (int i = 0; i < massivEdges.size(); ++i)
				{
					massivEdges[i].second = LightGreen;
				}
				Draw();
				ReleaseDC(hWnd, descriptor);
				return;
			}
			case ESC:
			{
				DrawCircle(x, y, radius, 1, Black, Black);
				for (int i = 0; i < massivPoint.size(); ++i)
				{
					massivPoint[i].second.first = LightGreen;
					massivPoint[i].second.second = LightGreen;
				}
				for (int i = 0; i < massivEdges.size(); ++i)
				{
					massivEdges[i].second = LightGreen;
				}
				Draw();
				ReleaseDC(hWnd, descriptor);
				return;
			}
			case LEFT:
			{				
				if (x > radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					x-=speed;
				}
				ReleaseDC(hWnd, descriptor);
				break;
			}
			case RIGHT:
			{
				if (x < rectConsole.right - radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					x+=speed;
				}
				ReleaseDC(hWnd, descriptor);
				break;
			}
			case UP:
			{
				if (y > 150)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					y -= speed;
				}
				ReleaseDC(hWnd, descriptor);
				break;
			}
			case DOWN:
			{
				if (y < rectConsole.bottom - radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					y += speed;
				}
				ReleaseDC(hWnd, descriptor);
				break;
			}			
		}		
		Draw();
	}
}

void Map::AddPipe()
{
	pair<int, int> point1, point2;
	if (SetActivePoint())
	{
		point1.first = massivPoint[activePoint].first.first;
		point1.second = massivPoint[activePoint].first.second;
		if (SetActivePoint() && (massivPoint[activePoint].first.first != point1.first) && (massivPoint[activePoint].first.second != point1.second))
		{

			point2.first = massivPoint[activePoint].first.first;
			point2.second = massivPoint[activePoint].first.second;
			massivEdges.push_back({ { { point1.first, point1.second }, { point2.first, point2.second} }, LightGreen });

		}
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.first = LightGreen;
			massivPoint[i].second.second = LightGreen;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second = LightGreen;
		}
		Draw();
	}
}

void Map::DeleteKC()
{
	pair<int, int> point;
	if (SetActivePoint())
	{
		point.first = massivPoint[activePoint].first.first;
		point.second = massivPoint[activePoint].first.second;
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			if ((massivEdges[i].first.first.first == point.first) && (massivEdges[i].first.first.second == point.second) ||
				(massivEdges[i].first.second.first == point.first) && (massivEdges[i].first.second.second == point.second))
			{
				massivEdges[i].second = Black;
				Draw();
				massivEdges.erase(massivEdges.begin() + i);
				--i;
			}
		}
		massivPoint[activePoint].second.first = Black;
		massivPoint[activePoint].second.second = Black;
		Draw();
		massivPoint.erase(massivPoint.begin() + activePoint);
		if (activePoint >= massivPoint.size())
		{
			activePoint = massivPoint.size() - 1;
		}
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.first = LightGreen;
			massivPoint[i].second.second = LightGreen;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second = LightGreen;
		}
		Draw();
	}

}

void Map::DeletePipe()
{
	pair<int, int> point1, point2;
	if (SetActivePoint())
	{
		point1.first = massivPoint[activePoint].first.first;
		point1.second = massivPoint[activePoint].first.second;
		if (SetActivePoint() && (massivPoint[activePoint].first.first != point1.first) && (massivPoint[activePoint].first.second != point1.second))
		{
	
			point2.first = massivPoint[activePoint].first.first;
			point2.second = massivPoint[activePoint].first.second;
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				if ((massivEdges[i].first.first.first == point1.first) &&
				   (massivEdges[i].first.first.second == point1.second) &&
				   (massivEdges[i].first.second.first == point2.first) &&
				   (massivEdges[i].first.second.second == point2.second))
				{
					massivEdges[i].second = Black;
					Draw();
					massivEdges.erase(massivEdges.begin() + i);
					break;
				}
			}
		}
	}
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		massivPoint[i].second.first = LightGreen;
		massivPoint[i].second.second = LightGreen;
	}
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		massivEdges[i].second = LightGreen;
	}
	Draw();
}

void Map::ChoosePen(HDC &descriptor, int width, ConsoleColor color)
{
	Pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	if (color == LightGreen)
	{
		Pen = CreatePen(PS_SOLID, width, RGB(19, 246, 118));
	}
	else if (color == Black)
	{
		Pen = CreatePen(PS_SOLID, width, RGB(0, 0, 0));
	}
	else if (color == Green)
	{
		Pen = CreatePen(PS_SOLID, width, RGB(11, 102, 46));
	}
	SelectObject(descriptor, Pen);	
	return;
}

void Map::ChooseBrush(HDC &descriptor, ConsoleColor color)
{
	Brush = CreateSolidBrush(RGB(0, 0, 0));
	if (color == LightGreen)
	{
		Brush = CreateSolidBrush(RGB(19, 246, 118));
	}
	else if (color == Black)
	{
		Brush = CreateSolidBrush(RGB(0, 0, 0));
	}
	else if (color == Green)
	{
		Brush = CreateSolidBrush(RGB(11, 102, 46));
	}
	SelectObject(descriptor, Brush);	
	return;
}

bool Map::SetActivePoint()
{
	int key;
	pair<int, int> point;
	while (true)
	{
	    point = { massivPoint[activePoint].first.first, massivPoint[activePoint].first.second };
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.first = Green;
			massivPoint[i].second.second = Green;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second = Green;
		}
		massivPoint[activePoint].second.first = LightGreen;
		massivPoint[activePoint].second.second = LightGreen;
		Draw();
		key = _getch();
		if (key == -32)
		{
			key = _getch();
		}		
		switch (key)
		{
		case ESC:
		{
			for (int i = 0; i < massivPoint.size(); ++i)
			{
				massivPoint[i].second.first = LightGreen;
				massivPoint[i].second.second = LightGreen;				
			}
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				massivEdges[i].second = LightGreen;
			}
			Draw();
			return false;
		}
		case ENTER:
		{
			return true;
		}
		case UP:
		{
			activePoint = SearchNearestPoint(point, UP);
			break;
		}
		case LEFT:
		{
			activePoint = SearchNearestPoint(point, LEFT);
			break;
		}
		case RIGHT:
		{
			activePoint = SearchNearestPoint(point, RIGHT);
			break;
		}
		case DOWN:
		{
			activePoint = SearchNearestPoint(point, DOWN);
			break;
		}
		}
	}
}

int Map::SearchNearestPoint(const pair<int, int> &point, ConsoleKey key)
{
	int min = 99999;
	int index = activePoint;
	if (key == RIGHT)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((massivPoint[i].first.first - point.first < min) && (massivPoint[i].first.first - point.first > 0))
			{
				min = massivPoint[i].first.first - point.first;
				index = i;
			}
		}
		return index;
	}
	if (key == LEFT)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((point.first - massivPoint[i].first.first < min) && (point.first - massivPoint[i].first.first > 0))
			{
				min = point.first - massivPoint[i].first.first;
				index = i;
			}
		}
		return index;
	}
	if (key == UP)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((point.second - massivPoint[i].first.second < min) && (point.second - massivPoint[i].first.second > 0))
			{
				min = point.second - massivPoint[i].first.second;
				index = i;
			}
		}
		return index;
	}
	if (key == DOWN)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((massivPoint[i].first.second - point.second < min) && (massivPoint[i].first.second - point.second > 0))
			{
				min = massivPoint[i].first.second - point.second;
				index = i;
			}
		}
		return index;
	}
	return index;
}

