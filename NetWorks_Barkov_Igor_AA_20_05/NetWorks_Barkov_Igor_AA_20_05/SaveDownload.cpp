#include "SaveDownload.h"

void SaveDownload::SaveNetWorks(const NetWorks &netWorks)
{
    ofstream fout;
    string nameFile = netWorks.name + ".txt";
    fout.open(nameFile, ios::out);
    Animation::Loading("Автосохранение", 2000);
    if (fout.is_open())
    {
        fout << netWorks.pipes.size() << endl;
        fout << netWorks.KCs.size() << endl;
        for (auto& [id, pipe]: netWorks.pipes)
        {
            fout << id << endl;
            fout << pipe.diameter << endl;
            fout << pipe.lenght << endl;
            fout << pipe.signRepair << endl;
        }
        for (auto& [id, KC] : netWorks.KCs)
        {
            fout << id << endl;
            fout << KC.name << endl;
            fout << KC.numberWorkshops << endl;
            fout << KC.numberWorkshopsOperation << endl;
            fout << KC.effectiveness << endl;
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
        int sizePipes = stoi(str);
        getline(fin, str);
        int sizeKCs = stoi(str);
        int id; Pipe pipe; KC kc;
        for (int i = 0; i < sizePipes; ++i)
        {
            getline(fin, str);
            id = stoi(str);
            getline(fin, str);
            pipe.diameter = stoi(str);
            getline(fin, str);
            pipe.lenght = stod(str);
            getline(fin, str);
            pipe.signRepair = str;
            netWorks.pipes.emplace(id, pipe);
        }
        for (int i = 0; i < sizeKCs; ++i)
        {
            getline(fin, str);
            id = stoi(str);
            getline(fin, str);
            kc.name = str;
            getline(fin, str);
            kc.numberWorkshops = stoi(str);
            getline(fin, str);
            kc.numberWorkshopsOperation = stoi(str);
            getline(fin, str);
            kc.effectiveness = stoi(str);
            netWorks.KCs.emplace(id, kc);
        }
    }
    fin.close();
}

void SaveDownload::SaveMap(const Map& map)
{
    ofstream fout;
    string nameFile = map.netWork->name + "Map" + ".txt";
    fout.open(nameFile, ios::out);
    Animation::Loading("Автосохранение", 2000);
    if (fout.is_open())
    {
        fout << map.massivPoint.size() << endl;
        fout << map.massivEdges.size() << endl;
        for (int i = 0; i < map.massivPoint.size(); ++i)
        {
            fout << map.massivPoint[i].first << endl;
            fout << map.massivPoint[i].second.first.first << endl;
            fout << map.massivPoint[i].second.first.second << endl;
            fout << map.massivPoint[i].second.second.first << endl;
            fout << map.massivPoint[i].second.second.second << endl;
        }
        for (int i = 0; i < map.massivEdges.size(); ++i)
        {
            fout << map.massivEdges[i].first << endl;
            fout << map.massivEdges[i].second.first.first.first << endl;
            fout << map.massivEdges[i].second.first.first.second << endl;
            fout << map.massivEdges[i].second.first.second.first << endl;
            fout << map.massivEdges[i].second.first.second.second << endl;
            fout << map.massivEdges[i].second.second << endl;
        }
        for (auto& [id, pair] : map.graph.edges)
        {
            fout << id << endl;
            fout << pair.first << endl;
            fout << pair.second << endl;
        }
        for (auto& [id, set]: map.graph.vertexes)
        {
            fout << id << endl;
            fout << set.size() << endl;
            for (auto& ids : set)
            {
                fout << ids << endl;
            }
        }
    }
    fout.close();
}

void SaveDownload::DownloadMap(Map& map)
{
    string str; int id; int sizeSet; pair<int, int> pair; set<int> Set;
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
            map.massivPoint[i].first = stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.first.first = stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.first.second = stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.second.first = (ConsoleColor)stoi(str);
            getline(fin, str);
            map.massivPoint[i].second.second.second = (ConsoleColor)stoi(str);
        }
        for (int i = 0; i < map.massivEdges.size(); ++i)
        {
            getline(fin, str);
            map.massivEdges[i].first = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second.first.first.first = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second.first.first.second = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second.first.second.first = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second.first.second.second = stoi(str);
            getline(fin, str);
            map.massivEdges[i].second.second = (ConsoleColor)stoi(str);
        }
        for (int i = 0; i < map.massivEdges.size(); ++i)
        {
            getline(fin, str);
            id = stoi(str);
            getline(fin, str);
            pair.first = stoi(str);
            getline(fin, str);
            pair.second = stoi(str);
            map.graph.edges.emplace(id, pair);
        }
        for (int i = 0; i < map.massivPoint.size(); ++i)
        {
            getline(fin, str);
            id = stoi(str);
            getline(fin, str);
            sizeSet = stoi(str);
            for (int i = 0; i < sizeSet; ++i)
            {
                getline(fin, str);
                Set.insert(stoi(str));
            }
            map.graph.vertexes.emplace(id, Set);
        }
    }
    fin.close();
}
