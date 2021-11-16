#include <string>
#include <sstream>
#include <fstream>
#include "NetWorks.h"

using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;

#ifndef SaveDownload_H
#define	SaveDownload_H

struct SaveDownload
{
	static void SaveNetWorks(const NetWorks &netWorks);
	static void DownloadNetWorks(NetWorks &netWorks);
};

#endif
