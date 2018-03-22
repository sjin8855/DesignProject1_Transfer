#pragma once
#include "Transfer.h"
#include "Bus.h"
#include "Train.h"
#include "Price.h"

class Person : Price
{
protected:
	Transfer* current_transfer;		// 현재 타고 있는 Transfer
	string current_location;	// 현재 지역
	Train* possible_train_array[10];	// 현재 지역을 지나가는 Train 
	Bus* possible_bus_array[10];	// 현재 지역을 지나가는 Bus
	Price price;
	int possible_train_count;	// 현재 지역을 지나가는 Train 개수	
	int possible_bus_count;	// 현재 지역을 지나가는 Bus 개수
	int transfer_price;
	bool current_direction;	//현재 방향

public:
	Person();

public:
	void set_current_location(string _name);	// 입력 : location
	void set_remain_route(int _count);	// 입력 : 몇 정거장 남았는지 remain_route_count 
	void set_transfer(Transfer& trnasfer);	// 입력 : current_transfer
	void set_transfer_number(int _number);	// 입력 : 트랜스퍼 번호
	string get_current_location();	// 리턴 : 현재 위치 location
	int get_remain_route();	// 리턴 : 몇 정거장 남았는지 remain_route_count
	Transfer* get_transfer();	// 리턴 : current_transfer가 현재 타고 있는 Transfer

	void remain_route();	// 몇 정거장 남았는지 remain_route_count 저장
	void take_transfer(int _transfer_name, bool& One);	// 트랜스퍼에 타다, current_transfer에 포인터로 연결
	void initial_possible();
	void _price();

public: // 멤버변수 possible_train_array[10], possible_train_array[10]을 사용하는 함수
	void set_possible_train_array(Train* train);	// 입력 : possible_train_array
	void set_possible_bus_array(Bus* bus);		// 입력 : possible_bus_array
	void set_possible_train_count(int _count);	// 입력 : possible_train_count
	void set_possible_bus_count(int _count);	// 입력 : possible_bus_count
	int get_transfer_number();	// 리턴 : 트랜스퍼 번호
	int get_possible_train_count();	// 리턴 : possible_train_count
	int get_possible_bus_count();	// 리턴 : possible_bus_count
	Train* get_possible_train_array();	// 리턴 : possible_train_array
	Bus* get_possible_bus_array();	// 리턴 : possible_bus_array
	void set_price(int _price);
	Price get_price();
	void set_current_direction(bool _direction); // 입력 : direct
	bool get_current_direction();		// 리턴 : direct


public:
	void print_possible_vehicle();	// 이용가능한 트랜스퍼 출력
	void print_remain_route();	// 몇정거장 남았는지 출력
	void print_person_info();	// current_transfer 정보 출력

	list<string>::iterator get_current_position()	// 리턴 : 현재 포지션 
	{
		return current_transfer->get_current_position();
	}

	list<string>& get_route();
};

