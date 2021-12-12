#include <string>
#include <vector>
#include "Pipe.h"
#include "KC.h"
#include <unordered_map>

#ifndef NetWorks_H
#define	NetWorks_H

using std::string;
using std::unordered_map;

struct NetWorks
{
	string name;
	unordered_map<int, Pipe> pipes;
	unordered_map<int, KC> KCs;
};

#endif 
