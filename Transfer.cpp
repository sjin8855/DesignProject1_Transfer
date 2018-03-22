#include "Transfer.h"

Transfer::Transfer()
{
	number = 0;
	remain_route_count = 0;
	direct = true;
}

void Transfer::set_route_add(string _name)	// 입력 : 노선도
{
	route.push_back(_name);
}

void Transfer::set_transfer_number(int _number)		// 입력 : 트랜스퍼 번호
{
	number = _number;
}

void Transfer::set_remain_route(int _count)			//입력 : 몇 정거장 남았는지
{
	remain_route_count = _count;
}

int Transfer::get_transfer_number()					// 리턴 : 트랜스퍼 번호
{
	return number;
}

list<string>& Transfer::get_route()					// 리턴 : 노선도 
{
	return route;
}

int Transfer::get_remain_route()					// 리턴 : 몇 정거장 남았는지
{
	return remain_route_count;
}


void Transfer::set_direction(bool _direction) // 입력 : 방향
{
	direct = _direction;
}

bool Transfer::get_direction()	// 리턴 : 방향
{
	return direct;
}