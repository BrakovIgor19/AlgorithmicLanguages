#include "Logger.h"

Logger::Logger(short left, short top, short right, short bottom, char frameSymbol, ConsoleColor frameSymbolColor, ConsoleColor textColor, ConsoleColor backgroundColor) :

     left(left), top(top), right(right), bottom(bottom), frameSymbol(frameSymbol), frameSymbolColor(frameSymbolColor), textColor(textColor), backgroundColor(backgroundColor),  height(bottom - top - 1), width(right - left - 1)
{
    Console::SetColor(frameSymbolColor, Black);
    ConsoleFormatOutIn::WriteTextCenterThisCoord(left + (width + 2) / 2, top - 2, "История");
    Console::gotoxy(left, top);
    DrawFrame(width + 2, height + 2, frameSymbol);
    displayedData.reserve(height);
    for (int i = 0; i < height; ++i)
    {
        displayedData.push_back("");
    }
    history.reserve(150);
}

void Logger::DrawData()
{
    // Очистка истории
    string bufEmptyStr;
    Console::SetColor(LightGreen, Black);
    for (int i = 0; i < width; ++i)
    {
        bufEmptyStr += " ";
    }
    for (int i = 0; i < height; ++i)
    {
        Console::gotoxy(left + 1, top + 1 + i);
        cout << bufEmptyStr;
    }
    // Вывод дисплейдаты
    Console::SetColor(LightGreen, Black);
    for (int i = 0; i < height; ++i)
    {
        Console::gotoxy(left + 1, top + 1 + i);
        cout << displayedData[i];
    }
}

void Logger::Update(const string &str)
{
    history.push_back(str);
    if (history.size() < height)
    {
        for (int i = 0; i < history.size(); ++i)
        {
            displayedData[i] = history[i];
        }
    }
    else
    for (int i = history.size() - height,  j = 0; j < height; ++i, ++j)
    {
        displayedData[j] = history[i];
    }
    DrawData();
}

void Logger::DrawFrame(short width, short height, char symbol) const
{
    setlocale(LC_CTYPE, "C");
    int bufx, bufy;
    for (int i = 0; i < width; ++i)
    {
        cout << symbol;
    }
    bufx = Console::getXcoord() - 1; bufy = Console::getYcoord();
    for (int i = 0; i < height; ++i)
    {
        Console::gotoxy(bufx, bufy + i);
        cout << symbol << endl;
    }
    Console::gotoxy(bufx - (width - 1), bufy);
    bufx = Console::getXcoord(); bufy = Console::getYcoord();
    for (int i = 0; i < height; ++i)
    {
        Console::gotoxy(bufx, bufy + i);
        cout << symbol << endl;
    }
    Console::gotoxy(bufx, bufy + (height - 1));
    for (int i = 0; i < width; ++i)
    {
        cout << symbol;
    }
    setlocale(LC_CTYPE, ".1251");
}
