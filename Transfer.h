#ifndef TRANSFER_H
#define TRANSFER_H
#include "Map.h"
#include <sstream>
#include <list>

class Transfer
{
protected:
	list<string> route;	// �뼱��
	int number;	// Ʈ������ ��ȣ
	int remain_route_count;	// �� ������ ���Ҵ���
	list<string>::iterator current_position;	// ���� �뼱�� ��ġ
	bool direct;	//��, ������ ����

public:
	Transfer();

public:
	void set_route_add(string _name);	// �Է� : �뼱��
	void set_transfer_number(int _number);	// �Է� : Ʈ������ ��ȣ
	void set_remain_route(int _count);	// �Է� : �� ������ ���Ҵ���
	int get_transfer_number();	// ���� : Ʈ������ ��ȣ
	list<string>& get_route();	// ���� : �뼱�� 
	int get_remain_route(); // ���� : �� ������ ���Ҵ���
	void set_direction(bool _direction); // �Է� : ����
	bool get_direction();	// ���� : ����

public:	// STL �Լ�
	list<string>::iterator get_begin_route()	// ���� : ����Ʈ ���� ��ġ
	{
		return route.begin();
	}

	list<string>::iterator get_end_route()	// ���� : ����Ʈ �� ��ġ
	{
		return route.end();
	}

	void clear_current_position()	// current_position �ʱ�ȭ
	{
		current_position = route.begin(); 
	}

	list<string>::iterator get_current_position()	// ���� : ���� ������ 
	{
		return current_position;
	}
	void set_current_position(list<string>::iterator pos) // �Է� : ���� ������
	{
		current_position = pos;
	}
};

#endif