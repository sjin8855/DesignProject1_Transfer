#pragma once
#include "Transfer.h"
#include "Bus.h"
#include "Train.h"
#include "Price.h"

class Person : Price
{
protected:
	Transfer* current_transfer;		// ���� Ÿ�� �ִ� Transfer
	string current_location;	// ���� ����
	Train* possible_train_array[10];	// ���� ������ �������� Train 
	Bus* possible_bus_array[10];	// ���� ������ �������� Bus
	Price price;
	int possible_train_count;	// ���� ������ �������� Train ����	
	int possible_bus_count;	// ���� ������ �������� Bus ����
	int transfer_price;
	bool current_direction;	//���� ����

public:
	Person();

public:
	void set_current_location(string _name);	// �Է� : location
	void set_remain_route(int _count);	// �Է� : �� ������ ���Ҵ��� remain_route_count 
	void set_transfer(Transfer& trnasfer);	// �Է� : current_transfer
	void set_transfer_number(int _number);	// �Է� : Ʈ������ ��ȣ
	string get_current_location();	// ���� : ���� ��ġ location
	int get_remain_route();	// ���� : �� ������ ���Ҵ��� remain_route_count
	Transfer* get_transfer();	// ���� : current_transfer�� ���� Ÿ�� �ִ� Transfer

	void remain_route();	// �� ������ ���Ҵ��� remain_route_count ����
	void take_transfer(int _transfer_name, bool& One);	// Ʈ�����ۿ� Ÿ��, current_transfer�� �����ͷ� ����
	void initial_possible();
	void _price();

public: // ������� possible_train_array[10], possible_train_array[10]�� ����ϴ� �Լ�
	void set_possible_train_array(Train* train);	// �Է� : possible_train_array
	void set_possible_bus_array(Bus* bus);		// �Է� : possible_bus_array
	void set_possible_train_count(int _count);	// �Է� : possible_train_count
	void set_possible_bus_count(int _count);	// �Է� : possible_bus_count
	int get_transfer_number();	// ���� : Ʈ������ ��ȣ
	int get_possible_train_count();	// ���� : possible_train_count
	int get_possible_bus_count();	// ���� : possible_bus_count
	Train* get_possible_train_array();	// ���� : possible_train_array
	Bus* get_possible_bus_array();	// ���� : possible_bus_array
	void set_price(int _price);
	Price get_price();
	void set_current_direction(bool _direction); // �Է� : direct
	bool get_current_direction();		// ���� : direct


public:
	void print_possible_vehicle();	// �̿밡���� Ʈ������ ���
	void print_remain_route();	// �������� ���Ҵ��� ���
	void print_person_info();	// current_transfer ���� ���

	list<string>::iterator get_current_position()	// ���� : ���� ������ 
	{
		return current_transfer->get_current_position();
	}

	list<string>& get_route();
};

