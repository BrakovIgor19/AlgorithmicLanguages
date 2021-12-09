#include "SaveDownload.h"

void SaveDownload::SaveNetWorks(const NetWorks &netWorks)
{
    ofstream fout;
    setlocale(LC_CTYPE, "rus");
    string nameFile = netWorks.name + ".txt";
    fout.open(nameFile, ios::out);
    Animation::Loading("Автосохранение", 2000);
    if (fout.is_open())
    {
        fout << netWorks.pipes.size() << endl;
        fout << netWorks.KCs.size() << endl;
        for (int i = 0; i < netWorks.pipes.size(); ++i)
        {
            fout << netWorks.pipes[i].id << endl;
            fout << netWorks.pipes[i].diameter << endl;
            fout << netWorks.pipes[i].lenght << endl;
            fout << netWorks.pipes[i].signRepair << endl;
        }
        for (int i = 0; i < netWorks.KCs.size(); ++i)
        {
            fout << netWorks.KCs[i].id << endl;
            fout << netWorks.KCs[i].name << endl;
            fout << netWorks.KCs[i].numberWorkshops << endl;
            fout << netWorks.KCs[i].numberWorkshopsOperation << endl;
            fout << netWorks.KCs[i].effectiveness << endl;
        }
    }
    fout.close();
}

void SaveDownload::DownloadNetWorks(NetWorks &netWorks)
{
    string str;
    ifstream fin;
    string nameFile = netWorks.name + ".txt";
    fin.open(nameFile, ios::out);
    Animation::Loading("Загрузка: " + netWorks.name, 2000);
    if (fin.is_open())
    {
        getline(fin, str);
        netWorks.pipes.resize(stoi(str));
        getline(fin, str);
        netWorks.KCs.resize(stoi(str));
        for (int i = 0; i < netWorks.pipes.size(); ++i)
        {
            getline(fin, str);
            netWorks.pipes[i].id = stoi(str);
            getline(fin, str);
            netWorks.pipes[i].diameter = stoi(str);
            getline(fin, str);
            netWorks.pipes[i].lenght = stod(str);
            getline(fin, str);
            netWorks.pipes[i].signRepair = str;

        }
        for (int i = 0; i < netWorks.KCs.size(); ++i)
        {
            getline(fin, str);
            netWorks.KCs[i].id = stoi(str);
            getline(fin, str);
            netWorks.KCs[i].name = str;
            getline(fin, str);
            netWorks.KCs[i].numberWorkshops = stoi(str);
            getline(fin, str);
            netWorks.KCs[i].numberWorkshopsOperation = stoi(str);
            getline(fin, str);
            netWorks.KCs[i].effectiveness = stoi(str);
        }
    }
    fin.close();
}

void SaveDownload::SaveMap(const Map& map)
{
    ofstream fout;
    setlocale(LC_CTYPE, "rus");
    string nameFile = map.netWork->name + "Map" + ".txt";
    fout.open(nameFile, ios::out);
    Animation::Loading("Автосохранение", 2000);
    if (fout.is_open())
    {
        fout << map.massivPoint.size() << endl;
        fout << map.massivEdges.size() << endl;
        for (int i = 0; i < map.massivPoint.size(); ++i)
        {
            fout << map.massivPoint[i].first.first << endl;
            fout << map.massivPoint[i].first.second << endl;
            fout << map.massivPoint[i].second.first << endl;
            fout << map.massivPoint[i].second.second << endl;
        }
        for (int i = 0; i < map.massivEdges.size(); ++i)
        {
            fout << map.massivEdges[i].first.first.first << endl;
            fout << map.massivEdges[i].first.first.second << endl;
            fout << map.massivEdges[i].first.second.first << endl;
            fout << map.massivEdges[i].first.second.second << endl;
            fout << map.massivEdges[i].second << endl;
        }
    }
    fout.close();
}

void SaveDownload::DownloadMap(Map& map)
{
    string str;
    ifstream fin;
    string nameFile = map.netWork->name + "Map" + ".txt";
    fin.open(nameFile, ios::out);
    Animation::Loading("Загрузка: " + map.netWork->name, 2000);
    if (fin.is_open())
    {
        getline(fin, str);
        map.massivPoint.resize(stoi(str));
        getline(fin, str);
        map.massivEdges.resize(stoi(str));
        for (int i = 0; i < map.massivPoint.size(); ++i)
        {
            getline(fin, str);
            map.massivPoint[i].first.first = stoi(str);
            getline(fin, str);
            map.massivPoint[i].first.second = stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.first = (ConsoleColor)stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.second = (ConsoleColor)stoi(str);
        }
        for (int i = 0; i < map.massivEdges.size(); ++i)
        {
            getline(fin, str);
            map.massivEdges[i].first.first.first = stoi(str);
            getline(fin, str);
            map.massivEdges[i].first.first.second = stoi(str);
            getline(fin, str);
            map.massivEdges[i].first.second.first = stoi(str);
            getline(fin, str);
            map.massivEdges[i].first.second.second = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second = (ConsoleColor)stoi(str);
        }
    }
    fin.close();
}
