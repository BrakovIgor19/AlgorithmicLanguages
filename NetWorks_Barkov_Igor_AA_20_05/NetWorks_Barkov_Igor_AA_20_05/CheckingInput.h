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
    
    static const vector<string> arrayErrors;
   
    static void SkipSpacesStr(const string &str, int &i);

    template <class T>
    static int CheckError(const string& s)
    {
        return -1;
    }
    template<>
    static int CheckError<int>(const string& str)
    {
        //���������� ������ �������
        int i = 0;
        SkipSpacesStr(str, i);

        // ��� ������ 1 - ������ ����
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // ��� ������ 3 - ������ �����
        if (str[i] == '0')
        {
            return 3;
        }

        // ��� ������ 2 - ���������� ����������� ��������
        for (; i < str.size(); ++i)
        {
            // ���������� ������� ����� �����
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
        //���������� ������ �������
        int i = 0;
        SkipSpacesStr(str, i);

        // ��� ������ 1 - ������ ����
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // ��� ������ 3 - ������ �����
        if (((str[i] == '0') && (str[i + 1] == '0')) || (str[i] == ','))
        {
            return 3;
        }

        // ��� ������ 2 - ���������� ����������� ��������
        int k = 0;
        for (; i < str.size(); ++i)
        {
            // ���������� ������� ����� �����
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
        //���������� ������ �������
        int i = 0;
        SkipSpacesStr(str, i);

        // ��� ������ 1 - ������ ����
        if ((str.size() == 0) || (i == str.size()))
        {
            return 1;
        }

        // ���������� ������� ����� �����
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




