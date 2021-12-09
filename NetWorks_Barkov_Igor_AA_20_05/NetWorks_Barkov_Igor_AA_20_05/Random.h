#include <windows.h> 
#include <ctime> 
#include <vector>

#ifndef Random_H
#define	Random_H

using std::vector;

struct Random
{
public:
    static int RandomUniquenessInt(int left, int right)
    {
        srand(time(NULL));
        int ID;
        while (true)
        {
            ID = left + (rand() % (right - left) + 1);
            if (CheckingUniquenessID(ID))
            {
                return ID;
            }
        }
    }

    static vector<int> uniquenessID;
private:
    static bool CheckingUniquenessID(int ID)
    {
        for (int i = 0; i < uniquenessID.size(); ++i)
        {
            if (ID == uniquenessID[i])
            {
                return false;
            }
        }
        uniquenessID.push_back(ID);
        return true;
    }
};

#endif 
