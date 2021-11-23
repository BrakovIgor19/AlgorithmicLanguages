#include <vector>
#include <string>

#ifndef TextDate_H
#define	TextDate_H

using std::vector;
using std::string;

struct TextDate
{
	static const vector<string> bootMenu; // Загрузочное меню
	static const vector<string> NetworkMenu; // Сетевое меню
	static const vector<string> pipeFields; // Параметры трубы
	static const vector<string> KCFields; // Параметры компрессорной станции
	static const vector<string> modeMenu;

};

#endif 
