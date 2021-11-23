#include "SaveDownload.h"

void SaveDownload::SaveNetWorks(const NetWorks &netWorks)
{
    ofstream fout;
    setlocale(LC_CTYPE, "rus");
    string nameFile = netWorks.name + ".txt";
    fout.open(nameFile, ios::out);
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
