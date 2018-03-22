#include "Person.h"
#include <iomanip>
Person::Person()
{
	possible_train_count = 0;
	possible_bus_count = 0;
}

void Person::set_current_location(string _name)	// �Է� : location
{
	current_location = _name;
}

void Person::set_transfer(Transfer& transfer)	// �Է� : current_transfer
{
	current_transfer = &transfer;	
}

void Person::set_transfer_number(int _number) // �Է� : Ʈ������ ��ȣ
{
	current_transfer->set_transfer_number(_number);
}

string Person::get_current_location()	// ���� : ���� ��ġ location
{
	return current_location;
}

int Person::get_remain_route()	// ���� : �� ������ ���Ҵ��� remain_route_count
{
	return current_transfer->get_remain_route();
}

Transfer* Person::get_transfer()	// ���� : current_transfer�� ���� Ÿ�� �ִ� Transfer
{
	return current_transfer;
}

void Person::remain_route()		// �� ������ ���Ҵ��� ����
{
	int count;
	bool check = false;
	for(int i=0; i< possible_train_count; i++)
	{
		count = 0;
		list<string>::iterator possible_train_start = possible_train_array[i]->get_begin_route();
		list<string>::iterator possible_train_end = possible_train_array[i]->get_end_route();
		string _position = *possible_train_array[i]->get_current_position();
		while(possible_train_start != possible_train_end)
		{
			if(*possible_train_start == current_location)
			{
				count++;
				break;
			}

			if(check == true)
				count++;

			if(*possible_train_start == _position)
			{
				count++;
				check = true;
			}
			possible_train_start++;
		}
		possible_train_array[i]->set_remain_route(count);
	}

	for(int i=0; i< possible_bus_count; i++)
	{
		count = 0;
		check = false;
		list<string>::iterator possible_bus_start = possible_bus_array[i]->get_begin_route();
		list<string>::iterator possible_bus_end = possible_bus_array[i]->get_end_route();
		string _position = *possible_bus_array[i]->get_current_position();
		while(possible_bus_start != possible_bus_end)
		{
			if(*possible_bus_start == current_location)
			{
				count++;
				break;
			}

			if(check == true)
				count++;

			if(*possible_bus_start == _position)
			{
				count++;
				check = true;
			}
			possible_bus_start++;
		}

		possible_bus_array[i]->set_remain_route(count);
	}

}

void Person::set_remain_route(int _count)	//�Է� : �� ������ ���Ҵ��� remain_route_count ����
{
	current_transfer->set_remain_route(_count);
}

void Person::take_transfer(int _transfer_name, bool& One)	// Ʈ�����ۿ� Ÿ��, current_transfer�� �����ͷ� ����
{	
	int money;
	if( One == true)
	{	
		cout<<"======= ����� ���̸� �Է����ּ��� ========="<<endl;
		cin >> age;
		cout<<"======= ����� ����ī�忡 �󸶰� ����ֽ��ϱ�?"<<endl;
		cin >> card_change;
		One=false;
		
		
		
		price.set_card_change(card_change);
		price.set_age(age);
		price.count_age();
		int get_price = price.get_transfer_price();
		int get_card = price.get_card_change();
		price.set_card_change(get_card-(get_price+50));
	}

	for(int i=0;i<possible_bus_count;i++)
	{
		int move_count = 0;
		int get_count = possible_bus_array[i]->get_remain_route();
		if(possible_bus_array[i]->get_transfer_number() == _transfer_name)
		{
			if(possible_bus_array[i]->get_remain_route() == 1)
			{
				set_transfer(*possible_bus_array[i]);
				price.set_age(age);
				price.count_age();
				int get_price = price.get_transfer_price();
				int get_card = price.get_card_change();
				price.set_card_change(get_card);
				price.set_transfer_price(get_price+50);
				price.set_card_change(get_card-50);
				while(true)
				{
					if(price.get_card_change()>0)
					{
						price.set_transfer_price(0);
						cout<<possible_bus_array[i]->get_transfer_number()<<"ž���߽��ϴ�."<<endl;
						price.print_age();
						break;
					}
					else
					{
						price.set_card_change(card_change);
						cout<<"�ܾ��� �����մϴ�. ��õ���ּ���."<<endl;
						cout<<"������ �ݾ� : ";
						cin>>money;
						price.set_card_change(price.get_card_change()+money);
					}
				}
				break;
			}

			else
			{
				while(get_count!=1)
				{
					move_count++;
					get_count--;
				}
				cout<<"������ġ�� : "<<possible_bus_array[i]->get_transfer_number()<<" �����ϴ�."<<endl;
				cout<<"�ʿ��� move Ƚ�� : "<<move_count<<endl;
			}
		}
	}


	for(int i=0;i<possible_train_count;i++)
	{
		if( One == true)
		{	
			cout<<"======= ����� ���̸� �Է����ּ��� ========="<<endl;
			cin >> age;
			cout<<"======= ����� ����ī�忡 �󸶰� ����ֽ��ϱ�?"<<endl;
			cin >> card_change;

			price.set_card_change(card_change);
			price.set_age(age);
			price.count_age();
			int get_price = price.get_transfer_price();
			int get_card = price.get_card_change();
			price.set_card_change(card_change-(get_price+50));
			One=false;
		}
		int get_count = possible_train_array[i]->get_remain_route();
		int move_count = 0;
		if(possible_train_array[i]->get_transfer_number() == _transfer_name)
		{
			if(possible_train_array[i]->get_remain_route() == 1)
			{
				int get_price = price.get_transfer_price();
				int get_card = price.get_card_change();
				set_transfer(*possible_train_array[i]);
				price.set_age(age);
				price.count_age();
				price.set_card_change(get_card);
				price.set_transfer_price(get_price+50);
				price.set_card_change(card_change-50);
				while(true)
				{
					if(price.get_card_change()>=0)
					{
						price.set_transfer_price(0);
						cout<<possible_train_array[i]->get_transfer_number()<<"ž���߽��ϴ�."<<endl;
						price.print_age();
						break;
					}
					else
					{
						price.set_card_change(card_change);
						cout<<"�ܾ��� �����մϴ�. ��õ���ּ���."<<endl;
						cout<<"������ �ݾ� : ";
						cin>>money;
						price.set_card_change(price.get_card_change()+money);
					}
				}
				break;
			}

			else
			{
				if(possible_train_array[i]->get_train_type()==1)
				{
					while(get_count!=1)
					{
						move_count++;
						get_count--;
						get_count--;
						if(get_count<1)
						{
							cout<<"�� Ʈ�����۴� ���������ϴ�."<<endl;
							break;
						}
					}
					if(get_count>=1)
					{
						cout<<"������ġ�� : "<<possible_train_array[i]->get_transfer_number()<<" �����ϴ�."<<endl;
						cout<<"�ʿ��� move Ƚ�� : "<<move_count<<endl;
					}
				}
				else if(possible_train_array[i]->get_train_type()==2)
				{
					while(get_count!=1)
					{
						move_count++;
						get_count--;
					}
					cout<<"������ġ�� : "<<possible_train_array[i]->get_transfer_number()<<" �����ϴ�."<<endl;
					cout<<"�ʿ��� move Ƚ�� : "<<move_count<<endl;
				}
			}
		}
	}
}

void Person::set_possible_train_array(Train* train)	// �Է� : possible_train_array
{
	possible_train_array[possible_train_count] = train;
	possible_train_count++;
}

void Person::set_possible_bus_array(Bus* bus)		// �Է� : possible_bus_array
{
	possible_bus_array[possible_bus_count] = bus;
	possible_bus_count++;
}

void Person::set_possible_train_count(int _count)	// �Է� : possible_train_count
{
	possible_train_count = _count;
}

void Person::set_possible_bus_count(int _count)	// �Է� : possible_bus_count
{
	possible_bus_count = _count;
}

int Person::get_transfer_number()	// ���� : Ʈ������ ��ȣ
{
	return current_transfer->get_transfer_number();
}

int Person::get_possible_train_count()	// ���� : possible_train_count
{
	return possible_train_count;
}

int Person::get_possible_bus_count()	// ���� : possible_bus_count
{
	return possible_bus_count;	
}

Train* Person::get_possible_train_array()	// ���� : possible_train_array
{
	return possible_train_array[possible_train_count];
}

Bus* Person::get_possible_bus_array()	// ���� : possible_bus_array
{
	return possible_bus_array[possible_bus_count];
}

void Person::print_possible_vehicle()	// �̿밡���� Ʈ������ ���
{
	cout<<"======== �̿밡���� Ʈ������ ��� =========="<<endl<<endl;
	for(int i=0; i<possible_bus_count; i++)
	{
		list<string>::iterator start_bus = possible_bus_array[i]->get_begin_route();
		list<string>::iterator end_bus = possible_bus_array[i]->get_end_route();

		cout<<possible_bus_array[i]->get_transfer_number()<<" : ";
		while(start_bus!=end_bus)
		{
			cout<<*start_bus<<" ";
			start_bus++;
		}
		cout<<endl;
	}

	for(int i=0; i<possible_train_count; i++)
	{
		list<string>::iterator start_train = possible_train_array[i]->get_begin_route();
		list<string>::iterator end_train = possible_train_array[i]->get_end_route();

		cout<<possible_train_array[i]->get_transfer_number()<<" : "
			<<possible_train_array[i]->get_train_type()<<" : ";
		while(start_train!=end_train)
		{
			cout<<*start_train<<" ";
			start_train++;
		}
		cout<<endl;
	}
	cout<<endl;
}	
void Person::print_remain_route()	// �������� ���Ҵ��� ���
{
	remain_route();
	for(int i=0; i<possible_bus_count; i++)
	{
		cout<<possible_bus_array[i]->get_transfer_number()<<" : "
			<<possible_bus_array[i]->get_remain_route()<<endl;
	}

	for(int i=0; i<possible_train_count; i++)
	{
		cout<<possible_train_array[i]->get_transfer_number()<<" : "
			<<possible_train_array[i]->get_train_type()<<" / "
			<<possible_train_array[i]->get_remain_route()<<endl;
	}
}


void Person::print_person_info() // current_transfer ���� ���
{
	if(current_transfer != 0)
	{
		cout<<"���� Ÿ�� �ִ� Ʈ������ : "<< current_transfer->get_transfer_number()<<endl;
		cout<<"���� ������ : "<< *current_transfer->get_current_position()<<endl;
		cout<<"���� ��� : "<<price.get_transfer_price()<<endl;
		cout<<"���� ī�� �ܾ� : "<<price.get_card_change()<<endl;
	}

	else
	{
		cout << "���� ��ġ�� " << current_location << "�Դϴ�. " << endl;
		cout << "���� Ÿ�� �ִ� Ʈ�����۰� �����ϴ�." << endl;
		cout <<"���� ī�� �ܾ� : "<<price.get_card_change()<<endl;
	}
}

list<string>& Person::get_route()
{
	return current_transfer->get_route();
}


void Person::initial_possible()
{
	for(int i=0; i<possible_bus_count; i++)
		possible_bus_array[i]=NULL;
	for(int i=0; i<possible_train_count; i++)
		possible_train_array[i]=NULL;
}

void Person::set_price(int _price)
{
	price.set_card_change(_price);
}

Price Person::get_price()
{
	return price;
}

void Person::_price()
{
	price.set_transfer_price(price.get_transfer_price()+10);
}

void Person::set_current_direction(bool _direction) // �Է� : direct
{
	current_direction = _direction;
}

bool Person::get_current_direction()		// ���� : direct
{
	return current_direction;
}