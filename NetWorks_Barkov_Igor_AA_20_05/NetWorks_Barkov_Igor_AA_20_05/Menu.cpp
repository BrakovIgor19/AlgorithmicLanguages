#include "Menu.h"

short Menu::activeMenu = 0;

short Menu::ShowMenuCenter(const vector<string> &strMenu)
{
    system("cls");

    bool flag1 = false;
    int keyMenu;

    // Поиск первой строки меню 
    short firstLineMenu = Console::GetHeightWindow() / 2 - strMenu.size() / 2;
    short activeLineStr = firstLineMenu;

    // Работа с меню
    while (true)
    {
        if (flag1)
        {
            break;
        }

        // Отрисовать меню после события
        DrawMenu(strMenu, firstLineMenu ,activeLineStr);

        // Спрашиваем клавишу и считываем ее код
        keyMenu = _getch();
        if (keyMenu == -32)
        {
            keyMenu = _getch();
        }

        //Проверяем нажатую клавишу
        switch (keyMenu)
        {
        case ESC:
        {
            PlaySoundA("ui_menu_cancel.wav", NULL, SND_ASYNC);
            Sleep(1000);
            flag1 = true;
            system("cls");
            return -1;
        }
        case DOWN:
        {            
            if (activeLineStr < firstLineMenu + strMenu.size() - 1)
            {
                PlaySoundA("ui_menu_prevnext.wav", NULL, SND_ASYNC);
                ++activeLineStr;
            }
            break;
        }
        case UP:
        {
            if (activeLineStr > firstLineMenu)
            {
                PlaySoundA("ui_menu_prevnext.wav", NULL, SND_ASYNC);
                --activeLineStr;
            }
            break;
        }
        case ENTER:
            PlaySoundA("ui_pipboy_select.wav", NULL, SND_ASYNC);
            system("cls");
            return activeLineStr - firstLineMenu;            
        }
    }
}

short Menu::ActiveMenuAlignedRight(short x, short y, const vector<string>& strMenu)
{
    int keyMenu; bool flag1 = false;
    while (true)
    {
        if (flag1)
        {
            break;
        }
        for (int i = 0; i < strMenu.size(); ++i)
        {
            if (i + y != activeMenu + y)
            {
                Console::SetColor(Green, Black);
            }
            else
            {
                Console::SetColor(LightGreen, Black);
                Console::gotoxy(x - 2, y + i);
                cout << " ";
            }
            Console::gotoxy(x, y + i);
            cout << strMenu[i];
        }
        Console::SetColor(LightGreen, Black);

        // Спрашиваем клавишу и считываем ее код
        keyMenu = _getch();
        if (keyMenu == -32)
        {
            keyMenu = _getch();
        }

        //Проверяем нажатую клавишу
        switch (keyMenu)
        {
        case ESC:
        {
            PlaySoundA("ui_menu_cancel.wav", NULL, SND_ASYNC);
            Sleep(1000);
            flag1 = true;            
            return -1;
        }
        case DOWN:
        {
            if (activeMenu + y < y + strMenu.size() - 1)
            {
                PlaySoundA("ui_menu_prevnext.wav", NULL, SND_ASYNC);
                ++activeMenu;
            }
            break;
        }
        case UP:
        {
            if (activeMenu + y > y)
            {
                PlaySoundA("ui_menu_prevnext.wav", NULL, SND_ASYNC);
                --activeMenu;
            }
            break;
        }
        case ENTER:
            PlaySoundA("ui_pipboy_select.wav", NULL, SND_ASYNC);
            setlocale(LC_CTYPE, "C");
            Console::gotoxy(x - 2, y + activeMenu);
            cout << "\xFE";
            setlocale(LC_CTYPE, "rus");
            return activeMenu;
        }
    }
}

void Menu::DrawMenu(const vector<string> &strMenu, short firstLineMenu, short activeLineMenu)
{

    short xCenter = Console::GetWidthWindow() / 2; 
    for (short i = 0; i < strMenu.size(); ++i)
    {
        if (i + firstLineMenu != activeLineMenu)
        {
            Console::SetColor(Green, Black);
        }
        else
        {
            Console::SetColor(LightGreen, Black);
        }
        ConsoleFormatOutIn::WriteTextCenterThisCoord(xCenter, i + firstLineMenu, strMenu[i]);
    }
    Console::SetColor(LightGreen, Black);
}
