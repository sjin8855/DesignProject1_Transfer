#include "Transfer.h"

Transfer::Transfer()
{
	number = 0;
	remain_route_count = 0;
	direct = true;
}

void Transfer::set_route_add(string _name)	// �Է� : �뼱��
{
	route.push_back(_name);
}

void Transfer::set_transfer_number(int _number)		// �Է� : Ʈ������ ��ȣ
{
	number = _number;
}

void Transfer::set_remain_route(int _count)			//�Է� : �� ������ ���Ҵ���
{
	remain_route_count = _count;
}

int Transfer::get_transfer_number()					// ���� : Ʈ������ ��ȣ
{
	return number;
}

list<string>& Transfer::get_route()					// ���� : �뼱�� 
{
	return route;
}

int Transfer::get_remain_route()					// ���� : �� ������ ���Ҵ���
{
	return remain_route_count;
}


void Transfer::set_direction(bool _direction) // �Է� : ����
{
	direct = _direction;
}

bool Transfer::get_direction()	// ���� : ����
{
	return direct;
}