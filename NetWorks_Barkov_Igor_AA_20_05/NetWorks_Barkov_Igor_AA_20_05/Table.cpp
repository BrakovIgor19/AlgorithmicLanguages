#include "Table.h"


using std::cout;
using std::endl;

void Table::DrawCell(int width, int height, char symbol) const
{
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
}

bool Table::SelectCell()
{
    RepaintActiveCell(Black, LightGreen);
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
                return true;
            }
            case ESC:
            {
                return false;
            }
            case UP:
            {
                if (activeCell[1] > 1)
                {
                    PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                    RepaintActiveCell(LightGreen, Black);
                    --activeCell[1];
                    RepaintActiveCell(Black, LightGreen);
                }
                break;
            }
            case DOWN:
            {
                if (activeCell[1] < heightLines.size() - 1)
                {
                    PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                    RepaintActiveCell(LightGreen, Black);
                    ++activeCell[1];
                    RepaintActiveCell(Black, LightGreen);
                }
                break;
            }
            case LEFT:
            {
                if (activeCell[0] > 0)
                {
                    PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                    RepaintActiveCell(LightGreen, Black);
                    --activeCell[0];
                    RepaintActiveCell(Black, LightGreen);
                }
                break;
            }
            case RIGHT:
            {
                if (activeCell[0] < widthColumns.size() - 1)
                {
                    PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                    RepaintActiveCell(LightGreen, Black);
                    ++activeCell[0];
                    RepaintActiveCell(Black, LightGreen);
                }
                break;
            }
        }
    }
}

void Table::EditCell(bool flag)
{   
    string bufStr;
    for (int i = 0; i < date[filterDateIndex[activeCell[1]]][activeCell[0]].size(); ++i)
    {
        bufStr += " ";
    }
    Console::SetColor(Black, LightGreen);
    ConsoleFormatOutIn::WriteTextCenterThisCoord(cellCoords[activeCell[1]][activeCell[0]][0] + widthColumns[activeCell[0]] / 2, cellCoords[activeCell[1]][activeCell[0]][1] + heightLines[activeCell[1]] / 2, bufStr);
    Console::gotoxy(cellCoords[activeCell[1]][activeCell[0]][0] + 2, cellCoords[activeCell[1]][activeCell[0]][1] + 2);
    do
    {
       if (activeCell[0] > 0)
       {
           bufStr = inspections[activeCell[0]](GetRightX() + 40, GetRightY() + 25, false, flag, date[filterDateIndex[activeCell[1]]][activeCell[0] - 1]);
       }
       else
       {
           bufStr = inspections[activeCell[0]](GetRightX() + 40, GetRightY() + 25, false, flag, date[filterDateIndex[activeCell[1]]][activeCell[0]]);
       }
       if ((bufStr != "-1") && (bufStr != "-1.000000"))
       {
           date[filterDateIndex[activeCell[1]]][activeCell[0]] = bufStr;
           break;
       }      
    } while (flag);
    ConsoleFormatOutIn::WriteTextCenterThisCoord(cellCoords[activeCell[1]][activeCell[0]][0] + widthColumns[activeCell[0]] / 2, cellCoords[activeCell[1]][activeCell[0]][1] + heightLines[activeCell[1]] / 2, date[filterDateIndex[activeCell[1]]][activeCell[0]]);
}

bool Table::SelectStr()
{
    for (int i = 0; i < widthColumns.size(); ++i)
    {
        activeCell[0] = i;
        RepaintActiveCell(Black, LightGreen);
    }
    
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
            return true;
        }
        case ESC:
        {
            return false;
        }
        case UP:
        {
            if (activeCell[1] > 1)
            {
                PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                for (int i = 0; i < widthColumns.size(); ++i)
                {
                    activeCell[0] = i;
                    RepaintActiveCell(LightGreen, Black);
                }
                --activeCell[1];
                for (int i = 0; i < widthColumns.size(); ++i)
                {
                    activeCell[0] = i;
                    RepaintActiveCell(Black, LightGreen);
                }
            }
            break;
        }
        case DOWN:
        {
            if (activeCell[1] < heightLines.size() - 1)
            {
                PlaySoundA("ui_pipboy_highlight.wav", NULL, SND_ASYNC);
                for (int i = 0; i < widthColumns.size(); ++i)
                {
                    activeCell[0] = i;
                    RepaintActiveCell(LightGreen, Black);
                }
                ++activeCell[1];
                for (int i = 0; i < widthColumns.size(); ++i)
                {
                    activeCell[0] = i;
                    RepaintActiveCell(Black, LightGreen);
                }
            }
            break;
        }
        }
    }
}

Table::Table(short left, short top, const vector<int> &heightLines, const vector <int> &widthColumns, char symbol, const vector<vector<string>> &date, vector<function<string(short, short, bool, bool, string)>> inspections):

    // Инициализация полей таблицы
    left(left), top(top), heightLines(heightLines), widthColumns(widthColumns), symbol(symbol), date(date), inspections(inspections)
{
    // Инициализируем фильтр
    filterDateIndex.reserve(heightLines.size());
    for (int i = 0; i < heightLines.size(); ++i)
    {
        filterDateIndex.push_back(i);
    }

    // Инициализируем матрицу координат ячеек 
    cellCoords.reserve(heightLines.size());
    for (int i = 0; i < cellCoords.size(); ++i)
    {
        cellCoords[i].reserve(widthColumns.size());
    }
    for (int i = 0; i < cellCoords.size(); ++i)
    {
        for (int j = 0; j < widthColumns.size(); ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                cellCoords[i][j].reserve(2);
            }
        }
    }
    int bufX, bufY = top;
    vector<vector<int>> buf1Vector; vector<int> buf2Vector;
    buf1Vector.resize(widthColumns.size()); buf2Vector.resize(2);

    for (int i = 0; i < filterDateIndex.size(); ++i)
    {
        bufX = left;
        for (int j = 0; j < widthColumns.size(); ++j)
        {
            buf2Vector[0] = bufX;
            buf2Vector[1] = bufY;
            bufX += (widthColumns[j] - 1);
            buf1Vector[j] = buf2Vector;
        }
        cellCoords.push_back(buf1Vector);
        bufY += (heightLines[i] - 1);
    }
}
    
void Table::Draw(const vector<int> &filterDateIndex)
{
    // Рисуем таблицу
    for (int i = 0; i < filterDateIndex.size(); ++i)
    {
        for (int j = 0; j < widthColumns.size(); ++j)
        {
            Console::gotoxy(cellCoords[i][j][0], cellCoords[i][j][1]);
            DrawCell(widthColumns[j], heightLines[i], symbol);
        }
    }
    // Заполняем данными
    for (int i = 0; i < filterDateIndex.size(); ++i)
    {
        for (int j = 0; j < widthColumns.size(); ++j)
        {
            ConsoleFormatOutIn::WriteTextCenterThisCoord(cellCoords[i][j][0] + widthColumns[j] / 2, cellCoords[i][j][1] + heightLines[i] / 2, date[filterDateIndex[i]][j]);
        }
    }
}

void Table::Add()
{
    // Синхронизируем фильтр, вектор высот строк и матрицу координат ячеек и матрицу данных таблицы
    // Данные
    vector<string> bufStr; bufStr.reserve(widthColumns.size());
    for (int i = 0; i < widthColumns.size(); ++i)
    {
        bufStr.push_back("");
    }
    date.push_back(bufStr);
    // Матрица координат ячеек
    vector<vector<int>> buf1Vector; vector<int> buf2Vector;
    buf1Vector.resize(widthColumns.size()); buf2Vector.resize(2);    
    int bufY = cellCoords[heightLines.size() - 1][0][1] + heightLines[heightLines.size() - 1] - 1;
    int bufX = cellCoords[heightLines.size() - 1][0][0];
    for (int j = 0; j < widthColumns.size(); ++j)
    {        
        buf2Vector[0] = bufX;
        buf2Vector[1] = bufY;
        bufX += (widthColumns[j] - 1);
        buf1Vector[j] = buf2Vector;
    }
    cellCoords.push_back(buf1Vector);
    // Вектор строк высот
    heightLines.push_back(5);
    // Фильтр
    filterDateIndex.push_back(filterDateIndex.size());

    // Рисуем пустую строку    
    for (int i = 0; i < widthColumns.size(); ++i)
    {
        Console::gotoxy(cellCoords[heightLines.size() - 1][i][0], cellCoords[heightLines.size() - 1][i][1]);
        DrawCell(widthColumns[i], heightLines[heightLines.size() - 1], symbol);
    }

    // Запускаем ввод строки
    activeCell[0] = 0; activeCell[1] = heightLines.size() - 1;
    for (int i = 0; i < widthColumns.size(); ++i)
    {
        RepaintActiveCell(Black, LightGreen);
        EditCell(true);
        RepaintActiveCell(LightGreen, Black);
        ++activeCell[0];
    }
    --activeCell[0];
}

void Table::Delete()
{
    while (heightLines.size() > 1)
    {
        if (SelectStr())
        {
            // Затираем данные
            int bufX = activeCell[0]; int bufY = activeCell[1];
            activeCell[0] = 0; activeCell[1] = 1;
            for (int i = 0; i < heightLines.size() - 1; ++i)
            {
                for (int j = 0; j < widthColumns.size(); ++j)
                {                                                            
                    RepaintActiveCell(Black, Black);
                    ++activeCell[0];
                }
                activeCell[0] = 0;
                ++activeCell[1];
            }
            Console::SetColor(LightGreen, Black);
            activeCell[0] = bufX; activeCell[1] = bufY;

            // Затираем последнюю строку
            bufX = activeCell[0]; activeCell[0] = 0;
            for (int i = 0; i < widthColumns.size(); ++i)
            {
                Console::gotoxy(cellCoords[heightLines.size() - 1][i][0], cellCoords[heightLines.size() - 1][i][1]);
                DrawCell(widthColumns[i], heightLines[heightLines.size() - 1], ' ');                    
                RepaintActiveCell(Black, Black);
                ++activeCell[0];
            }
            activeCell[0] = bufX; Console::SetColor(LightGreen, Black);
            // Удаляем из данных таблицы
            date.erase(date.begin() + filterDateIndex[activeCell[1]]);
    
            // Удаляем из фильтра
            filterDateIndex.erase(filterDateIndex.begin());
            if (filterDateIndex.size() != 0)
            {
                for (int i = 0; i < filterDateIndex.size(); ++i)
                {
                    --filterDateIndex[i];
                }
            }
    
            // Удаляем последний элемент из матрицы координат ячеек
            cellCoords.pop_back();
    
            // Удаляем элемент из вектора строк высот
            heightLines.erase(heightLines.begin() + activeCell[1]);
            
            // Переносим активную строку
            if (activeCell[1] > 1)
            {
                --activeCell[1];
            }
            
            // Отрисовываем таблицу
            Draw(filterDateIndex);
        }
        else
        {
            for (int i = 0; i < widthColumns.size(); ++i)
            {
                activeCell[0] = i;
                RepaintActiveCell(LightGreen, Black);
            }
            return;
        }
    }
}

void Table::Edit()
{    
    if (heightLines.size() > 1)
    {
        while (true)
        {
            if (SelectCell())
            {
                EditCell(false);
                RepaintActiveCell(Black, LightGreen);
            }
            else
            {
                RepaintActiveCell(LightGreen, Black);
                return;
            }
        }
    }   
}

short Table::GetRightX()
{
    return cellCoords[0][widthColumns.size() - 1][0] + widthColumns[widthColumns.size() - 1] - 1;
}

short Table::GetRightY()
{
    return top;
}

void Table::RepaintActiveCell(ConsoleColor text, ConsoleColor background)
{
    string bufStr;
    for (int i = 0; i < widthColumns[activeCell[0]] - 2; ++i)
    {
        bufStr += " ";
    }
    Console::SetColor(text, background);
    for (int i = 0; i < heightLines[activeCell[1]] - 2; ++i)
    {
        Console::gotoxy(cellCoords[activeCell[1]][activeCell[0]][0] + 1, cellCoords[activeCell[1]][activeCell[0]][1] + 1 + i);
        cout << bufStr;
    }
    ConsoleFormatOutIn::WriteTextCenterThisCoord(cellCoords[activeCell[1]][activeCell[0]][0] + widthColumns[activeCell[0]] / 2, cellCoords[activeCell[1]][activeCell[0]][1] + heightLines[activeCell[1]] / 2, date[filterDateIndex[activeCell[1]]][activeCell[0]]);
    Console::SetColor(background, text);
}
