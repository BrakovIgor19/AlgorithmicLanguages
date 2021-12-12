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
#include "CheckingInput.h"

using std::pair;

struct Map
{
    friend class SaveDownload;
public:
    Map();
    void Open();
    void ConnectTable(NetWorks& netWork);

private:
    HBRUSH brush;
    HPEN pen;
    HWND hWnd;
    HDC hdc;
    NetWorks* netWork;
    RECT rectConsole;
    Graph graph;
    vector<pair<int, pair<pair<int, int>, pair<ConsoleColor, ConsoleColor>>>> massivPoint;
    vector<pair<int, pair<pair<pair<int, int>, pair<int, int>>, ConsoleColor>>> massivEdges;
    int activeMainMenu = 0;
    int activePoint = 0;
    double ratio;
    int radius;
    bool SetMainMenu();
    void DrawFrame(int left, int top, int right, int bottom, int width, ConsoleColor frameColor);
    void DrawRectangle(int left, int top, int right, int bottom, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor);
    void DrawCircle(int x0, int y0, int radius, int widthFrame, ConsoleColor frameColor, ConsoleColor fillColor);
    void DrawArrow(pair<int, int> point1, pair<int, int> point2, ConsoleColor color);
    void DrawTextOut(int x, int y, string str, ConsoleColor text, ConsoleColor background);
    void Draw();
    void Clear();
    void AddKC();
    void AddPipe();
    void DeleteKC();
    void DeletePipe();
    void ChoosePen(int width, ConsoleColor color);
    void ChooseBrush(ConsoleColor color);
    bool SetActivePoint();
    int SearchNearestPoint(const pair <int, int>& point, ConsoleKey key);
    template<typename F, class T>
    int InputId(const unordered_map<F, T>& objects)
    {
        if (objects.size() != 0)
        {
            ConsoleFormatOutIn::WriteTextCenterThisCoord(Console::GetWidthWindow() / 2 - 5, 7, "¬ведите id: ");
            string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(), errorCode;
            while (true)
            {
                Console::SetColor(LightGreen, Black);
                Console::ShowCursor(true);
                getline(cin, strBuf);
                Console::ShowCursor(false);
                errorCode = CheckingInput::CheckError<int>(strBuf);
                if (errorCode == 0)
                {
                    for (auto& [id, obj]: objects)
                    {
                        if (id == stoi(strBuf)) 
                        {
                            bool flag = true;
                            for (auto& [id, obj] : massivEdges)
                            {
                                if (id == stoi(strBuf))
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            for (auto& [id, obj] : massivPoint)
                            {
                                if (id == stoi(strBuf))
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag == false)
                            {
                                break;
                            }
                            PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                            Console::SetColor(Black, Black);
                            Console::gotoxy(bufX, bufY);
                            for (int i = 0; i < strBuf.size(); ++i)
                            {
                                cout << " ";
                            }
                            Console::SetColor(LightGreen, Black);
                            Console::gotoxy(bufX, bufY);
                            cout << "id найден";
                            Console::gotoxy(bufX - 12, bufY);
                            Sleep(1000);
                            for (int i = 0; i < 22; ++i)
                            {
                                cout << " ";
                            }
                            return stoi(strBuf);
                        }
                    }
                    PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                    Console::SetColor(Black, Black);
                    Console::gotoxy(bufX, bufY);
                    for (int i = 0; i < strBuf.size(); ++i)
                    {
                        cout << " ";
                    }
                    Console::SetColor(LightGreen, Black);
                    Console::gotoxy(bufX, bufY);
                    cout << "id не найден или уже введЄн";
                    Console::gotoxy(bufX, bufY);
                    Sleep(1000);
                    for (int i = 0; i < 30; ++i)
                    {
                        cout << " ";
                    }
                    Console::gotoxy(bufX, bufY);
                }
                else
                {
                    PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                    Console::SetColor(Black, Black);
                    Console::gotoxy(bufX, bufY);
                    for (int i = 0; i < strBuf.size(); ++i)
                    {
                        cout << " ";
                    }
                    Console::SetColor(LightGreen, Black);
                    Console::gotoxy(bufX, bufY);
                    cout << CheckingInput::arrayErrors[errorCode];
                    Sleep(1000);
                    Console::gotoxy(bufX, bufY);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        cout << " ";
                    }
                    Console::gotoxy(bufX, bufY);
                }
            }
        }
        else
        {
            return -1;
        }
    }

};

#endif  
