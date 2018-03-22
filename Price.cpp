#include "Price.h"

Price::Price()
{
	transfer_price = 0;
	age = 0;
	card_change = 0;
}

void Price::set_age(int _age)		// �Է� : ����
{
	age = _age;
}

int Price::get_age()		// ���� : ����
{
	return age;
}

void Price::set_transfer_price(int price)//�Է� : Ʈ������ ����
{
	transfer_price = price;
}

int Price::get_transfer_price()//���� : Ʈ������ ����
{
	return transfer_price;
}

void Price::set_card_change(int _card_change)	//�Է� : ī�� �ܾ�
{
	card_change = _card_change;
}

int Price::get_card_change()	//���� : ī�� �ܾ�
{
	return card_change;
}

void Price::count_age()	// ���̺� �� ���
{
	if(get_age()<8)			//��̿��
		transfer_price = 500;

	else if(get_age()<20)	//û�ҳ���
		transfer_price = 700;

	else if(get_age()>60)	//���ο��
		transfer_price = 600;

	else
		transfer_price = 1000;//���ο��
}

void Price::print_age()
{
	if(get_age()<8)			//��̿��
		std::cout<<"��� �Դϴ�."<<std::endl;	

	else if(get_age()<20)	//û�ҳ���
		std::cout<<"û�ҳ� �Դϴ�."<<std::endl;

	else if(get_age()>60)	//���ο��
		std::cout<<"��� �Դϴ�."<<std::endl;

	else					//���ο��
		std::cout<<"�����մϴ�."<<std::endl;
}