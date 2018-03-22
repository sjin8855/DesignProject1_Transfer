#pragma once
#include "Transfer.h"

class Train : public Transfer
{	
private:
	int train_type;

public:
	Train();

public:
	void set_train_type(int _type);	// 리턴 : train_type
	int get_train_type();	// 리턴 : train_type
	void train_move();	// train_type에 따라 급행은 2칸 이동, 일반은 1칸 이동 
};