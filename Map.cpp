#include "Map.h"
#include <iomanip>
#include <sstream>
Map::Map()
{
	location_count = 0;
}

void Map::load_map(char* location_file)
{
	string Loca;
	ifstream ifs;
	ifs.open(location_file);
	while(getline(ifs, Loca))
	{
		stringstream inf(Loca);
		inf >> Loca;
		map_array[location_count] = Loca;
		location_count++;
	}
	ifs.close();
}

void Map::print_map()
{
	load_map("Map_DB.txt");
	for(int i=0; i<location_count; i++)
		cout<<map_array[i]<<setw(20);
	cout<<endl;
}