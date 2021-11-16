#include <dos.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Console.h"
#include "ConsoleFormatOutIn.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::is_same;
#ifndef ChekingInput_H
#define	ChekingInput_H

class CheckingInput
{
public:
    template <class T>
    static T Input(short xError, short yError, bool showError, bool flag)
    {
        return -1;
    }
    template <>
    static int Input<int>(short xError, short yError, bool showError, bool flag)

    {
        int errorCode; string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(); string bufEmptyStr;
        do
        {
            Console::ShowCursor(true);
            getline(cin, strBuf);
            Console::ShowCursor(false);
            errorCode = CheckingInput::CheckError<int>(strBuf);
            bufEmptyStr = "";
            if (errorCode == 0)
            {
                PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, CheckingInput::arrayErrors[errorCode]);
               
                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }
                return stoi(strBuf);
            }
            else
            {
                PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, arrayErrors[errorCode]);

                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }

                Console::gotoxy(bufX, bufY);
                for (int i = 0; i < strBuf.size(); ++i)
                {
                    cout << " ";
                }
                Console::gotoxy(bufX, bufY);

                strBuf = "-1";
            }
        } while (flag);
        return stoi(strBuf);
    }
    template <>
    static float Input<float>(short xError, short yError, bool showError, bool flag)

    {
        int errorCode; string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(); string bufEmptyStr;
        do
        {
            Console::ShowCursor(true);
            getline(cin, strBuf);
            Console::ShowCursor(false);
            errorCode = CheckingInput::CheckError<float>(strBuf);
            bufEmptyStr = "";
            if (errorCode == 0)
            {
                PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, CheckingInput::arrayErrors[errorCode]);

                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }
                return stof(strBuf);
            }
            else
            {
                PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, arrayErrors[errorCode]);

                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }

                Console::gotoxy(bufX, bufY);
                for (int i = 0; i < strBuf.size(); ++i)
                {
                    cout << " ";
                }
                Console::gotoxy(bufX, bufY);

                strBuf = "-1";
            }
        } while (flag);
        return stof(strBuf);
    }
    template <>
    static string Input<string>(short xError, short yError, bool showError, bool flag)

    {
        int errorCode; string strBuf; int bufX = Console::getXcoord(), bufY = Console::getYcoord(); string bufEmptyStr;
        do
        {
            Console::ShowCursor(true);
            getline(cin, strBuf);
            Console::ShowCursor(false);
            errorCode = CheckingInput::CheckError<string>(strBuf);
            bufEmptyStr = "";
            if (errorCode == 0)
            {
                PlaySoundA("ui_hacking_passgood.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, CheckingInput::arrayErrors[errorCode]);

                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }
                break;
            }
            else
            {
                PlaySoundA("ui_hacking_passbad.wav", NULL, SND_ASYNC);
                ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, arrayErrors[errorCode]);

                if (showError == false)
                {
                    Sleep(1000);
                    for (int i = 0; i < CheckingInput::arrayErrors[errorCode].size(); ++i)
                    {
                        bufEmptyStr += " ";
                    }
                    ConsoleFormatOutIn::WriteTextCenterThisCoord(xError, yError, bufEmptyStr);
                }

                Console::gotoxy(bufX, bufY);
                for (int i = 0; i < strBuf.size(); ++i)
                {
                    cout << " ";
                }
                Console::gotoxy(bufX, bufY);
            }
        } while (flag);
        return strBuf;
    }
    static const vector<string> arrayErrors;
private:
    
    static void SkipSpacesStr(const string &str, int &i);

    template <class T>
    static int CheckError(const string& s)
    {
        return -1;
    }
    template<>
    static int CheckError<int>(const string& str)
    {
        //Пропускаем первые пробелы
        int i = 0;
        SkipSpacesStr(str, i);

        // Код ошибки 1 - пустой ввод
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // Код ошибки 3 - ошибка ввода
        if (str[i] == '0')
        {
            return 3;
        }

        // Код ошибки 2 - содержание посторонних символов
        for (; i < str.size(); ++i)
        {
            // Пропускаем пробелы после числа
            if (str[i] == ' ')
            {
                SkipSpacesStr(str, i);
                if (i == str.size())
                {
                    return 0;
                }
                else
                {
                    return 3;
                }
            }
            if (isdigit(str[i]))
            {
                continue;
            }
            else
            {
                return 2;
            }
        }
        return 0;
    }
    template<>
    static int CheckError<float>(const string& str)
    {
        //Пропускаем первые пробелы
        int i = 0;
        SkipSpacesStr(str, i);

        // Код ошибки 1 - пустой ввод
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // Код ошибки 3 - ошибка ввода
        if (((str[i] == '0') && (str[i + 1] == '0')) || (str[i] == ','))
        {
            return 3;
        }

        // Код ошибки 2 - содержание посторонних символов
        int k = 0;
        for (; i < str.size(); ++i)
        {
            // Пропускаем пробелы после числа
            if (str[i] == ' ')
            {
                SkipSpacesStr(str, i);
                if (i == str.size())
                {
                    return 0;
                }
                else
                {
                    return 3;
                }
            }

            if (str[i] == ',')
            {
                ++k;
                if (k > 1)
                {
                    return 3;
                }
                continue;
            }
            if (isdigit(str[i]))
            {
                continue;
            }
            else
            {
                return 2;
            }
        }
        return 0;
    }
    template<>
    static int CheckError<string>(const string& str)
    {
        //Пропускаем первые пробелы
        int i = 0;
        SkipSpacesStr(str, i);

        // Код ошибки 1 - пустой ввод
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // Пропускаем пробелы после имени
        if (str[i] == ' ')
        {
            SkipSpacesStr(str, i);
            if (i == str.size())
            {
                return 0;
            }
            else
            {
                return 3;
            }
        }

        return 0;
    }

};

#endif 




