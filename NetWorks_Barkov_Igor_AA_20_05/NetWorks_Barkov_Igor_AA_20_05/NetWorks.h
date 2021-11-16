#include <string>
#include <vector>
#include "Pipe.h"
#include "KC.h"

#ifndef NetWorks_H
#define	NetWorks_H

using std::string;
using std::vector;

struct NetWorks
{
	string name;
	vector<Pipe> pipes;
	vector<KC> KCs;
};

#endif 
