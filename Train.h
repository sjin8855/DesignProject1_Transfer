#pragma once
#include "Transfer.h"

class Train : public Transfer
{	
private:
	int train_type;

public:
	Train();

public:
	void set_train_type(int _type);	// ���� : train_type
	int get_train_type();	// ���� : train_type
	void train_move();	// train_type�� ���� ������ 2ĭ �̵�, �Ϲ��� 1ĭ �̵� 
};