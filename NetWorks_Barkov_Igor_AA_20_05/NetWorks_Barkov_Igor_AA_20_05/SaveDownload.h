#ifndef SaveDownload_H
#define	SaveDownload_H

#include <string>
#include <sstream>
#include <fstream>
#include "NetWorks.h"
#include "Animation.h"
#include "Map.h"

using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;



struct SaveDownload
{
	static void SaveNetWorks(const NetWorks &netWorks);
	static void DownloadNetWorks(NetWorks &netWorks);
	static void SaveMap(const Map& map);
	static void DownloadMap(Map& map);
};

#endif
