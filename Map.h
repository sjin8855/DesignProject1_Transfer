#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Map
{
protected:
	string map_array[100];	// �� ���� ����
	int location_count;	// �ε�� �� ����

public:
	Map();

public:
	void load_map(char* location_file);	// �� �ε�
	void print_map();	// �� ���
};