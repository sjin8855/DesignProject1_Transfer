#pragma once
#include "Transfer.h"

class Bus : public Transfer
{
public:
	Bus();

public:
	void bus_move();	// 버스 한칸 이동
};

