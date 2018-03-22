#include "Price.h"

Price::Price()
{
	transfer_price = 0;
	age = 0;
	card_change = 0;
}

void Price::set_age(int _age)		// 입력 : 나이
{
	age = _age;
}

int Price::get_age()		// 리턴 : 나이
{
	return age;
}

void Price::set_transfer_price(int price)//입력 : 트랜스퍼 가격
{
	transfer_price = price;
}

int Price::get_transfer_price()//리턴 : 트랜스퍼 가격
{
	return transfer_price;
}

void Price::set_card_change(int _card_change)	//입력 : 카드 잔액
{
	card_change = _card_change;
}

int Price::get_card_change()	//리턴 : 카대 잔액
{
	return card_change;
}

void Price::count_age()	// 나이별 돈 계산
{
	if(get_age()<8)			//어린이요금
		transfer_price = 500;

	else if(get_age()<20)	//청소년요금
		transfer_price = 700;

	else if(get_age()>60)	//노인요금
		transfer_price = 600;

	else
		transfer_price = 1000;//성인요금
}

void Price::print_age()
{
	if(get_age()<8)			//어린이요금
		std::cout<<"어린이 입니다."<<std::endl;	

	else if(get_age()<20)	//청소년요금
		std::cout<<"청소년 입니다."<<std::endl;

	else if(get_age()>60)	//노인요금
		std::cout<<"어르신 입니다."<<std::endl;

	else					//성인요금
		std::cout<<"감사합니다."<<std::endl;
}