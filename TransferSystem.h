#include "Train.h"
#include "Bus.h"
#include "Person.h"
#include <Windows.h>
class TransferSystem
{
protected:
	Bus* bus_array[10];	// �ε�� bus
	Train* train_array[10];	// �ε�� train 
	int train_count;	// �ε�� train ����
	int bus_count;	// �ε�� bus ����
	Person person;	// Person ��ü ����
	Map map;	// Map ��ü ����
	bool check;
	

public:
	TransferSystem();
	
public:	// �ε忡 �ʿ��� �Լ�
	void load_transfer(char* transfer_file);	// ���� �ε�
	Bus* initialize(string _type, int _number);	// Bus ������ ȣ��
	Train* initialize (string _type, int _number, int _train_type); // Train ������ ȣ��

public:
	//�̿� ������ Ʈ������ Train* possible_train_array[10], Bus* possible_bus_array[10] ����
	//Person person��ü �ȿ� �ִ� current_location������ �����ǵ��� ����
	void ride_possible_vehicle(string _name); // �̿� ������ Ʈ������ Train* possible_train_array[10], Bus* possible_bus_array[10] ����
											  //Person person��ü �ȿ� �ִ� current_location������ �����ǵ��� ����
	void ride_possible_move_vehicle(string _name);
	void transfer_move(); // Bus::bus_move() ȣ��, Train::train_move() ȣ��
	void take_transfer(int number, bool& One); // person.take_transfer(int _number); ȣ��
	void stop_person();	//���� ��ġ�� ���� person.current_location�� ��ġ ����, current_transfer�� NULL��
	void remain_routes();
	void price();
	
public:
	void print_map();	// �� ���
	void print_route();	// �뼱�� ���
	void print_possible_vehicle();	// �̿밡���� Ʈ������ ���, ȣ�� : person.print_ride_possible_vehicle();
	void print_remain_route();	// �������� ���Ҵ��� ���, ȣ�� : person.remain_route()
	void print_person_info();	// current_transfer ���� ���
	void print_train_location(int count);	// Train* train_array[10], Bus* bus_array[10] ���� ��ġ ���
	void print_bus_location(int count);
	void print_menu();		//�޴� ����� ���� �Լ�(�߰�)
};


