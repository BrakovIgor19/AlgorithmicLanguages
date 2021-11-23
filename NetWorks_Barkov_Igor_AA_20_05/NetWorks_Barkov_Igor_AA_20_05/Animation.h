#include <iostream>
#include <string>
#include "Console.h"

using std::string;
using std::cout;
using std::cin;

#ifndef Animation_H
#define	Animation_H

struct Animation
{
    static void Loading(const string& nameLoading, short time);
};

#endif 