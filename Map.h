#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Map
{
protected:
	string map_array[100];	// 맵 정보 저장
	int location_count;	// 로드된 맵 개수

public:
	Map();

public:
	void load_map(char* location_file);	// 맵 로드
	void print_map();	// 맵 출력
};