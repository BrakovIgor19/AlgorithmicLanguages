#include "Map.h"


Map::Map()
{
	hWnd = GetForegroundWindow();
	hdc = GetDC(hWnd);
	GetClientRect(hWnd, &rectConsole);
	int width = Console::GetWidthWindow();
	ratio = (double)(rectConsole.right - rectConsole.left)/Console::GetWidthWindow();
	massivPoint.reserve(100);
	radius = 10;
	pens.emplace(Black, CreatePen(PS_SOLID, 3, RGB(0, 0, 0))); brushes.emplace(Black, CreateSolidBrush(RGB(0, 0, 0)));
	pens.emplace(Green, CreatePen(PS_SOLID, 3, RGB(11, 102, 46))); brushes.emplace(Green, CreateSolidBrush(RGB(11, 102, 46)));
	pens.emplace(LightGreen, CreatePen(PS_SOLID, 3, RGB(19, 246, 118))); brushes.emplace(LightGreen, CreateSolidBrush(RGB(19, 246, 118)));

}

void Map::Open()
{
	system("cls");
	// Отрисуем начальное МэйнМеню
	for (auto& [id, pair] : massivEdges)
	{
		graph.edgeWeights.emplace(id, netWork->pipes[id].lenght);
	}
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
			case 4:
			{
				TopSort();
				break;
			}
			case 5:
			{
				FindingShortestPath();
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
	int width = 170, height = 90, between = 10;
	vector<int> bufArray; bufArray.reserve(TextDate::mapMenu.size());
	for (int i = 0; i < TextDate::mapMenu.size(); ++i)
	{
		bufArray.push_back((left + between + width / 2 + i * (width + between))/ratio);
	}

	for (int i = 0; i < TextDate::mapMenu.size(); ++i)
	{
		ConsoleFormatOutIn::WriteTextCenterThisCoord(bufArray[i], 2, TextDate::mapMenu[i]);
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
	
	ChoosePen(width, frameColor);
	MoveToEx(hdc, left, top, NULL);
	LineTo(hdc, right, top);
	MoveToEx(hdc, left, top, NULL);
	LineTo(hdc, left, bottom);
	MoveToEx(hdc, right, bottom, NULL);
	LineTo(hdc, left, bottom);
	MoveToEx(hdc, right, bottom, NULL);
	LineTo(hdc, right, top);
}

void Map::DrawRectangle(int left, int top, int right, int bottom, int width, ConsoleColor frameColor, ConsoleColor fillColor)
{
	ChoosePen(4, frameColor);
	ChooseBrush(fillColor);
	Rectangle(hdc, left, top, right, bottom);

}

void Map::DrawCircle(int x0, int y0, int radius, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor)
{
	ChoosePen(4, frameColor);
	ChooseBrush(fillColor);
	Ellipse(hdc, x0 - radius, y0 - radius, x0 + radius, y0 + radius);
}

void Map::DrawArrow(pair<int, int> point1, pair<int, int> point2, ConsoleColor color)
{

	ChoosePen(2, color);
	ChooseBrush(color);
	int width = 10, side = 5;  double distance = sqrt(pow(abs(point1.first) - abs(point2.first), 2) + pow(abs(point1.second) - abs(point2.second), 2)), Cos = (double)((point2.first - point1.first) / distance), Sin = (double)((point1.second - point2.second) / distance);
	MoveToEx(hdc, point1.first, point1.second, NULL);
	LineTo(hdc, point2.first, point2.second);	
	POINT ptTriangle[3] = { {point2.first - radius * Cos, point2.second + radius * Sin},
		                  {point2.first - 3 * radius * Cos - Sin * side, point2.second + 3 * radius * Sin - Cos * side},
						  {point2.first - 3 * radius * Cos + Sin * side, point2.second + 3 * radius * Sin + Cos * side}};
	 // Полигональная область стрелки
	Polygon(hdc, ptTriangle, 3);
}

void Map::DrawTextOut(int x, int y, string str, ConsoleColor text, ConsoleColor background)
{
	SetTextColor(hdc, RGB(0, 0, 0));
	if (text == LightGreen)
	{
		SetTextColor(hdc, RGB(19, 246, 118));
	}
	else if (text == Black)
	{
		SetTextColor(hdc, RGB(0, 0, 0));
	}
	else if (text == Green)
	{
		SetTextColor(hdc, RGB(11, 102, 46));
	}

	SetBkColor(hdc, RGB(0, 0, 0));    
	if (background == LightGreen)
	{
		SetBkColor(hdc, RGB(19, 246, 118));
	}
	else if (background == Black)
	{
		SetBkColor(hdc, RGB(0, 0, 0));
	}
	else if (background == Green)
	{
		SetBkColor(hdc, RGB(11, 102, 46));
	}
	std::wstring stemp = std::wstring(str.begin(), str.end());
	LPCWSTR sw = stemp.c_str();
	TextOut(
		hdc,
		x - str.size() / 3 * ratio,    // x-координата начала вывода текста
		y,   // y-координата начала вывода текста
		sw,  // указатель на строку текста
		str.size());  // количество символов для вывода
}

void Map::Draw()
{
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		DrawArrow({ massivEdges[i].second.first.first.first, massivEdges[i].second.first.first.second }, { massivEdges[i].second.first.second.first, massivEdges[i].second.first.second.second }, massivEdges[i].second.second);
	}
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		DrawTextOut(massivPoint[i].second.first.first, massivPoint[i].second.first.second - 3.5 * radius, netWork->KCs[massivPoint[i].first].name, massivPoint[i].second.second.first, Black);
	}
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		DrawCircle(massivPoint[i].second.first.first, massivPoint[i].second.first.second, radius, 3, massivPoint[i].second.second.first, massivPoint[i].second.second.second);
	}
}

void Map::Clear()
{
	system("cls");
	ChoosePen(1, Black);
	ChooseBrush(Black);
	// Очистка
	DrawRectangle(rectConsole.left, rectConsole.top, rectConsole.right, rectConsole.bottom, 1, Black, Black);	
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(hWnd, hdc);
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
	int id = InputId(netWork->KCs);
	if (id == -1)
	{
		return;
	}
	int x = 75, y = 150, speed = 10;
	int key;
	DrawCircle(x, y, radius, 1, LightGreen, LightGreen);
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		massivPoint[i].second.second.first = Green;
		massivPoint[i].second.second.second = Green;
	}
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		massivEdges[i].second.second = Green;
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
				massivPoint.push_back({id, { {x, y}, {LightGreen, LightGreen} } });
				graph.AddVertex(id);
				activePoint = massivPoint.size() - 1;
				for (int i = 0; i < massivPoint.size(); ++i)
				{
					massivPoint[i].second.second.first = LightGreen;
					massivPoint[i].second.second.second = LightGreen;
				}
				for (int i = 0; i < massivEdges.size(); ++i)
				{
					massivEdges[i].second.second = LightGreen;
				}
				Draw();
				return;
			}
			case ESC:
			{
				DrawCircle(x, y, radius, 1, Black, Black);
				for (int i = 0; i < massivPoint.size(); ++i)
				{
					massivPoint[i].second.second.first = LightGreen;
					massivPoint[i].second.second.second = LightGreen;
				}
				for (int i = 0; i < massivEdges.size(); ++i)
				{
					massivEdges[i].second.second = LightGreen;
				}
				Draw();
				return;
			}
			case LEFT:
			{				
				if (x > radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					x-=speed;
				}
				break;
			}
			case RIGHT:
			{
				if (x < rectConsole.right - radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					x+=speed;
				}
				break;
			}
			case UP:
			{
				if (y > 150)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					y -= speed;
				}
				break;
			}
			case DOWN:
			{
				if (y < rectConsole.bottom - radius)
				{
					DrawCircle(x, y, radius, 1, Black, Black);
					y += speed;
				}
				break;
			}			
		}		
		Draw();
	}
}

void Map::AddPipe()
{
	pair<int, int> point1, point2;
	int id = InputId(netWork->pipes);
	int id1, id2;
	if (id == -1)
	{
		return;
	}
	if (SetActivePoint())
	{
		point1.first = massivPoint[activePoint].second.first.first;
		point1.second = massivPoint[activePoint].second.first.second;
		id1 = massivPoint[activePoint].first;
		if (SetActivePoint())
		{
			if ((massivPoint[activePoint].second.first.first != point1.first) || (massivPoint[activePoint].second.first.second != point1.second))
			{
				point2.first = massivPoint[activePoint].second.first.first;
				point2.second = massivPoint[activePoint].second.first.second;
				id2 = massivPoint[activePoint].first;
				massivEdges.push_back({ id, { { { point1.first, point1.second }, { point2.first, point2.second} }, LightGreen } });
				graph.AddEdge(id, { id1, id2 });
			}
		}
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.second.first = LightGreen;
			massivPoint[i].second.second.second = LightGreen;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second.second = LightGreen;
		}
		Draw();
	}
}

void Map::DeleteKC()
{
	pair<int, int> point;
	int id;
	if (SetActivePoint())
	{
		point.first = massivPoint[activePoint].second.first.first;
		point.second = massivPoint[activePoint].second.first.second;
		id = massivPoint[activePoint].first;
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			if ((massivEdges[i].second.first.first.first == point.first) && (massivEdges[i].second.first.first.second == point.second) ||
				(massivEdges[i].second.first.second.first == point.first) && (massivEdges[i].second.first.second.second == point.second))
			{
				massivEdges[i].second.second = Black;
				Draw();
				massivEdges.erase(massivEdges.begin() + i);
				--i;
			}
		}
		massivPoint[activePoint].second.second.first = Black;
		massivPoint[activePoint].second.second.second = Black;
		Draw();
		massivPoint.erase(massivPoint.begin() + activePoint);
		graph.RemoveVertex(id);
		if (activePoint >= massivPoint.size())
		{
			activePoint = massivPoint.size() - 1;
		}
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.second.first = LightGreen;
			massivPoint[i].second.second.second = LightGreen;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second.second = LightGreen;
		}
		Draw();
	}
}

void Map::DeletePipe()
{
	pair<int, int> point1, point2;
	int id;
	if (SetActivePoint())
	{
		point1.first = massivPoint[activePoint].second.first.first;
		point1.second = massivPoint[activePoint].second.first.second;
		if (SetActivePoint() && ((massivPoint[activePoint].second.first.first != point1.first) || (massivPoint[activePoint].second.first.second != point1.second)))
		{
	
			point2.first = massivPoint[activePoint].second.first.first;
			point2.second = massivPoint[activePoint].second.first.second;
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				if (((massivEdges[i].second.first.first.first == point1.first) &&
				   (massivEdges[i].second.first.first.second == point1.second) &&
				   (massivEdges[i].second.first.second.first == point2.first) &&
				   (massivEdges[i].second.first.second.second == point2.second)) ||
					((massivEdges[i].second.first.first.first == point2.first) &&
					(massivEdges[i].second.first.first.second == point2.second) &&
					(massivEdges[i].second.first.second.first == point1.first) &&
					(massivEdges[i].second.first.second.second == point1.second)))
				{
					id = massivEdges[i].first;
					massivEdges[i].second.second = Black;
					Draw();
					massivEdges.erase(massivEdges.begin() + i);
					graph.RemoveEdge(id);
					break;
				}
			}
		}
	}
	for (int i = 0; i < massivPoint.size(); ++i)
	{
		massivPoint[i].second.second.first = LightGreen;
		massivPoint[i].second.second.second = LightGreen;
	}
	for (int i = 0; i < massivEdges.size(); ++i)
	{
		massivEdges[i].second.second = LightGreen;
	}
	Draw();
}

void Map::ChoosePen(int width, ConsoleColor color)
{
	SelectObject(hdc, pens[color]);
	return;
}

void Map::ChooseBrush(ConsoleColor color)
{

	SelectObject(hdc, brushes[color]);
	return;
}

bool Map::SetActivePoint()
{
	int key;
	pair<int, int> point;
	while (true)
	{
	    point = { massivPoint[activePoint].second.first.first, massivPoint[activePoint].second.first.second };
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			massivPoint[i].second.second.first = Green;
			massivPoint[i].second.second.second = Green;
		}
		for (int i = 0; i < massivEdges.size(); ++i)
		{
			massivEdges[i].second.second = Green;
		}
		massivPoint[activePoint].second.second.first = LightGreen;
		massivPoint[activePoint].second.second.second = LightGreen;
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
				massivPoint[i].second.second.first = LightGreen;
				massivPoint[i].second.second.second = LightGreen;
			}
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				massivEdges[i].second.second = LightGreen;
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
			if ((massivPoint[i].second.first.first - point.first < min) && (massivPoint[i].second.first.first - point.first > 0))
			{
				min = massivPoint[i].second.first.first - point.first;
				index = i;
			}
		}
		return index;
	}
	if (key == LEFT)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((point.first - massivPoint[i].second.first.first < min) && (point.first - massivPoint[i].second.first.first > 0))
			{
				min = point.first - massivPoint[i].second.first.first;
				index = i;
			}
		}
		return index;
	}
	if (key == UP)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((point.second - massivPoint[i].second.first.second < min) && (point.second - massivPoint[i].second.first.second > 0))
			{
				min = point.second - massivPoint[i].second.first.second;
				index = i;
			}
		}
		return index;
	}
	if (key == DOWN)
	{
		for (int i = 0; i < massivPoint.size(); ++i)
		{
			if ((massivPoint[i].second.first.second - point.second < min) && (massivPoint[i].second.first.second - point.second > 0))
			{
				min = massivPoint[i].second.first.second - point.second;
				index = i;
			}
		}
		return index;
	}
	return index;
}

void Map::TopSort()
{	
	bool flag = true;
	unordered_map<int, int> graphTopSort = graph.TopologicalSorting();
	if (graphTopSort.size() != graph.vertexes.size())
	{
		flag = false;
	}	
	if (flag)
	{
		
		for (auto& [id, point]: massivPoint)
		{
			DrawTextOut(point.first.first - 4, point.first.second - 8, std::to_string(graphTopSort[id]), Black, LightGreen);
		}
		while (ESC != _getch())
		{
		}
		for (auto& [id, point] : massivPoint)
		{
			DrawTextOut(point.first.first - 4, point.first.second - 8, std::to_string(graphTopSort[id]), LightGreen, Black);
		}
		Draw();
	}
	else
	{
		PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
		string str = "В графе существует цикл, топологическая сортировка невозможна";
		Console::gotoxy(Console::GetWidthWindow() / 2 - str.size(), 8);
		int bufX = Console::getXcoord(), bufY = Console::getYcoord();
		cout << str;
		Console::gotoxy(bufX, bufY);
		Console::SetColor(Black, Black);
		Sleep(1000);
		for (int i = 0; i < str.size(); ++i)
		{
			cout << " ";
		}
		Console::gotoxy(bufX, bufY);
		Console::SetColor(LightGreen, Black);

	}
	
	
}

void Map::FindingShortestPath()
{
	vector<int> vectorShortestPaths;
	pair<int, int> point1, point2;
	int vertex1, vertex2;
	if (SetActivePoint())
	{
		point1.first = massivPoint[activePoint].second.first.first;
		point1.second = massivPoint[activePoint].second.first.second;
		vertex1 = massivPoint[activePoint].first;
		if (SetActivePoint() && ((massivPoint[activePoint].second.first.first != point1.first) || (massivPoint[activePoint].second.first.second != point1.second)))
		{
			point2.first = massivPoint[activePoint].second.first.first;
			point2.second = massivPoint[activePoint].second.first.second;
			vertex2 = massivPoint[activePoint].first;
			vectorShortestPaths = graph.FindingShortestPathDijkstra(vertex1, vertex2);
			if ((vectorShortestPaths[0] + 1 >= 0) && (vectorShortestPaths[0] + 1 <= 0.001))
			{
				PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
				string str = "Нет пути!";
				Console::gotoxy(Console::GetWidthWindow() / 2 - str.size(), 8);
				int bufX = Console::getXcoord(), bufY = Console::getYcoord();
				cout << str;
				Console::gotoxy(bufX, bufY);
				Console::SetColor(Black, Black);
				Sleep(1000);
				for (int i = 0; i < str.size(); ++i)
				{
					cout << " ";
				}
				Console::gotoxy(bufX, bufY);
				Console::SetColor(LightGreen, Black);
				for (int i = 0; i < massivPoint.size(); ++i)
				{
					massivPoint[i].second.second.first = LightGreen;
					massivPoint[i].second.second.second = LightGreen;
				}
				for (int i = 0; i < massivEdges.size(); ++i)
				{
					massivEdges[i].second.second = LightGreen;
				}
				Draw();
				return;
			}
			for (int i = 0; i < massivPoint.size(); ++i)
			{
				massivPoint[i].second.second.first = Green;
				massivPoint[i].second.second.second = Green;
			}
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				massivEdges[i].second.second = Green;
			}
			int index;
			for (int i = 0; i < vectorShortestPaths.size(); ++i)
			{
				if (i + 1 != vectorShortestPaths.size())
				{
					
					for (int j = 0; j < massivEdges.size(); ++j)
					{
						if (graph.FindIdEdges(vectorShortestPaths[i], vectorShortestPaths[i + 1]) == massivEdges[j].first)
						{
							index = j;
							break;
						}
					}
					massivEdges[index].second.second = LightGreen;
				}
				for (int j = 0; j < massivPoint.size(); ++j)
				{
					if (vectorShortestPaths[i] == massivPoint[j].first)
					{
						index = j;
						break;
					}
				}
				massivPoint[index].second.second.first = LightGreen;
				massivPoint[index].second.second.second = LightGreen;
			}
			int index1, index2;
			for (auto& [id, pair] : graph.edges)
			{
				for (int j = 0; j < massivPoint.size(); ++j)
				{
					if (pair.first == massivPoint[j].first)
					{
						index1 = j;
						break;
					}
				}
				for (int j = 0; j < massivPoint.size(); ++j)
				{
					if (pair.second == massivPoint[j].first)
					{
						index2 = j;
						break;
					}
				}
				DrawTextOut((massivPoint[index1].second.first.first + 
					        massivPoint[index2].second.first.first) / 2,
					        (massivPoint[index1].second.first.second +
					        massivPoint[index2].second.first.second) / 2,
					std::to_string((int)graph.edgeWeights[id]), LightGreen, Black);
			}
			Draw();
			while (ESC != _getch())
			{
			}
			for (auto& [id, pair] : graph.edges)
			{
				for (int j = 0; j < massivPoint.size(); ++j)
				{
					if (pair.first == massivPoint[j].first)
					{
						index1 = j;
						break;
					}
				}
				for (int j = 0; j < massivPoint.size(); ++j)
				{
					if (pair.second == massivPoint[j].first)
					{
						index2 = j;
						break;
					}
				}
				DrawTextOut((massivPoint[index1].second.first.first +
					massivPoint[index2].second.first.first) / 2,
					(massivPoint[index1].second.first.second +
					massivPoint[index2].second.first.second) / 2,
					std::to_string((int)graph.edgeWeights[id]), Black, Black);
			}
			for (int i = 0; i < massivPoint.size(); ++i)
			{
				massivPoint[i].second.second.first = LightGreen;
				massivPoint[i].second.second.second = LightGreen;
			}
			for (int i = 0; i < massivEdges.size(); ++i)
			{
				massivEdges[i].second.second = LightGreen;
			}
			Draw();
		}
	}
}


