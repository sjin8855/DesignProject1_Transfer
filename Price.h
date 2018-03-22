#include <iostream>
#pragma once
class Price
{
protected:
	int transfer_price;
	int age;
	int card_change;

public:
	Price();
	void set_age(int _age);		// 입력 : 나이
	int get_age();		// 리턴 : 나이
	void count_age();	// 나이별 돈 계산
	void set_transfer_price(int price);//입력 : 트랜스퍼 가격
	int get_transfer_price();//리턴 : 트랜스퍼 가격
	void set_card_change(int _card_change);	//입력 : 카드 잔액
	int get_card_change();	//리턴 : 카드 잔액
	void print_age();
};