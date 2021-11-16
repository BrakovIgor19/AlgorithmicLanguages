#include "CheckingInput.h"



const vector<string> CheckingInput::arrayErrors =
{
        "�������!", // ��� ������ 0
        "������ ����!", // ��� ������ 1
        "������� ����������� �������!", // ��� ������ 2
        "������ �����!", // ��� ������ 3
        "���������� ������� ����� <= ���������� ���� �����!", // ��� ������ 4
        "������������� �� ����� � ���������� (0% - 100%)!", // ��� ������ 5
        "������� ����� �� ����������� ���������� ���� ��������!", // ��� ������ 6
        "������� Escape ��� ������!" //  ��� ������ 7
};

void CheckingInput::SkipSpacesStr(const string &str, int &i)
    {
        // ���������� ������� ���� ��� ���� (���� ������ ������ � �������� ���� ���������)
        while (true)
        {
            if ((str[i] == ' ') && (i < str.size()))
            {
                ++i;
            }
            else
            {
                break;
            }
        }
    }

