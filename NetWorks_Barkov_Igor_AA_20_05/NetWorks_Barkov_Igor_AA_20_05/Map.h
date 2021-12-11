#ifndef Map_H
#define	Map_H

#include "Graph.h"
#include "Console.h"
#include "ConsoleColor.h"
#include "TextDate.h"
#include "ConsoleKey.h"
#include <conio.h>
#include "ConsoleFormatOutIn.h"
#include <cmath>
#include "NetWorks.h"

using std::pair;

struct Map
{
    friend class SaveDownload;
public:
    Map();
    void Open();
    void ConnectTable(NetWorks &netWork);

private:
    Graph graph;
    vector<pair<pair<int, int>, pair<ConsoleColor, ConsoleColor>>> massivPoint;
    vector<pair<pair<pair<int, int>, pair<int, int>>, ConsoleColor>> massivEdges;
    int activeMainMenu = 0;
    int activePoint = 0;
    bool SetMainMenu();
    void DrawFrame(int left, int top, int right, int bottom, int width, ConsoleColor frameColor);
    void DrawRectangle(int left, int top, int right, int bottom, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor);
    void DrawCircle(int x0, int y0, int radius, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor);
    void DrawArrow(pair<int, int> point1, pair<int, int> point2, ConsoleColor color);
    void Draw();
    void Clear();
    void AddKC();
    void AddPipe();
    void DeleteKC();
    void DeletePipe();
    void ChoosePen(HDC &descriptor, int width, ConsoleColor color);
    void ChooseBrush(HDC& descriptor, ConsoleColor color);
    bool SetActivePoint();
    int SearchNearestPoint(const pair <int, int> &point, ConsoleKey key);
    double ratio;
    int radius;
    HBRUSH Brush;
    HPEN Pen;
    NetWorks* netWork;

    
};

#endif 
