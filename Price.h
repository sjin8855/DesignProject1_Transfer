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
	void set_age(int _age);		// �Է� : ����
	int get_age();		// ���� : ����
	void count_age();	// ���̺� �� ���
	void set_transfer_price(int price);//�Է� : Ʈ������ ����
	int get_transfer_price();//���� : Ʈ������ ����
	void set_card_change(int _card_change);	//�Է� : ī�� �ܾ�
	int get_card_change();	//���� : ī�� �ܾ�
	void print_age();
};