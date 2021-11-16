#include <vector>
#include <string>

#ifndef TextDate_H
#define	TextDate_H

using std::vector;
using std::string;

struct TextDate
{
	static const vector<string> bootMenu; // ����������� ����
	static const vector<string> NetworkMenu; // ������� ����
	static const vector<vector<string>> pipeFields; // ��������� �����
	static const vector<vector<string>> KCFields; // ��������� ������������� �������
	static const vector<string> modeMenu;

};

#endif 
