#ifndef TRANSFER_H
#define TRANSFER_H
#include "Map.h"
#include <sstream>
#include <list>

class Transfer
{
protected:
	list<string> route;	// 노선도
	int number;	// 트랜스퍼 번호
	int remain_route_count;	// 몇 정거장 남았는지
	list<string>::iterator current_position;	// 현재 노선도 위치
	bool direct;	//정, 역방향 설정

public:
	Transfer();

public:
	void set_route_add(string _name);	// 입력 : 노선도
	void set_transfer_number(int _number);	// 입력 : 트랜스퍼 번호
	void set_remain_route(int _count);	// 입력 : 몇 정거장 남았는지
	int get_transfer_number();	// 리턴 : 트랜스퍼 번호
	list<string>& get_route();	// 리턴 : 노선도 
	int get_remain_route(); // 리턴 : 몇 정거장 남았는지
	void set_direction(bool _direction); // 입력 : 방향
	bool get_direction();	// 리턴 : 방향

public:	// STL 함수
	list<string>::iterator get_begin_route()	// 리턴 : 리스트 시작 위치
	{
		return route.begin();
	}

	list<string>::iterator get_end_route()	// 리턴 : 리스트 끝 위치
	{
		return route.end();
	}

	void clear_current_position()	// current_position 초기화
	{
		current_position = route.begin(); 
	}

	list<string>::iterator get_current_position()	// 리턴 : 현재 포지션 
	{
		return current_position;
	}
	void set_current_position(list<string>::iterator pos) // 입력 : 현재 포지션
	{
		current_position = pos;
	}
};

#endif