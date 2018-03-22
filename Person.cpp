#include "Person.h"
#include <iomanip>
Person::Person()
{
	possible_train_count = 0;
	possible_bus_count = 0;
}

void Person::set_current_location(string _name)	// 입력 : location
{
	current_location = _name;
}

void Person::set_transfer(Transfer& transfer)	// 입력 : current_transfer
{
	current_transfer = &transfer;	
}

void Person::set_transfer_number(int _number) // 입력 : 트랜스퍼 번호
{
	current_transfer->set_transfer_number(_number);
}

string Person::get_current_location()	// 리턴 : 현재 위치 location
{
	return current_location;
}

int Person::get_remain_route()	// 리턴 : 몇 정거장 남았는지 remain_route_count
{
	return current_transfer->get_remain_route();
}

Transfer* Person::get_transfer()	// 리턴 : current_transfer가 현재 타고 있는 Transfer
{
	return current_transfer;
}

void Person::remain_route()		// 몇 정거장 남았는지 저장
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

void Person::set_remain_route(int _count)	//입력 : 몇 정거장 남았는지 remain_route_count 저장
{
	current_transfer->set_remain_route(_count);
}

void Person::take_transfer(int _transfer_name, bool& One)	// 트랜스퍼에 타다, current_transfer에 포인터로 연결
{	
	int money;
	if( One == true)
	{	
		cout<<"======= 당신의 나이를 입력해주세요 ========="<<endl;
		cin >> age;
		cout<<"======= 당신의 교통카드에 얼마가 들어있습니까?"<<endl;
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
						cout<<possible_bus_array[i]->get_transfer_number()<<"탑승했습니다."<<endl;
						price.print_age();
						break;
					}
					else
					{
						price.set_card_change(card_change);
						cout<<"잔액이 부족합니다. 충천해주세요."<<endl;
						cout<<"충전할 금액 : ";
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
				cout<<"현재위치에 : "<<possible_bus_array[i]->get_transfer_number()<<" 없습니다."<<endl;
				cout<<"필요한 move 횟수 : "<<move_count<<endl;
			}
		}
	}


	for(int i=0;i<possible_train_count;i++)
	{
		if( One == true)
		{	
			cout<<"======= 당신의 나이를 입력해주세요 ========="<<endl;
			cin >> age;
			cout<<"======= 당신의 교통카드에 얼마가 들어있습니까?"<<endl;
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
						cout<<possible_train_array[i]->get_transfer_number()<<"탑승했습니다."<<endl;
						price.print_age();
						break;
					}
					else
					{
						price.set_card_change(card_change);
						cout<<"잔액이 부족합니다. 충천해주세요."<<endl;
						cout<<"충전할 금액 : ";
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
							cout<<"이 트랜스퍼는 지나갔습니다."<<endl;
							break;
						}
					}
					if(get_count>=1)
					{
						cout<<"현재위치에 : "<<possible_train_array[i]->get_transfer_number()<<" 없습니다."<<endl;
						cout<<"필요한 move 횟수 : "<<move_count<<endl;
					}
				}
				else if(possible_train_array[i]->get_train_type()==2)
				{
					while(get_count!=1)
					{
						move_count++;
						get_count--;
					}
					cout<<"현재위치에 : "<<possible_train_array[i]->get_transfer_number()<<" 없습니다."<<endl;
					cout<<"필요한 move 횟수 : "<<move_count<<endl;
				}
			}
		}
	}
}

void Person::set_possible_train_array(Train* train)	// 입력 : possible_train_array
{
	possible_train_array[possible_train_count] = train;
	possible_train_count++;
}

void Person::set_possible_bus_array(Bus* bus)		// 입력 : possible_bus_array
{
	possible_bus_array[possible_bus_count] = bus;
	possible_bus_count++;
}

void Person::set_possible_train_count(int _count)	// 입력 : possible_train_count
{
	possible_train_count = _count;
}

void Person::set_possible_bus_count(int _count)	// 입력 : possible_bus_count
{
	possible_bus_count = _count;
}

int Person::get_transfer_number()	// 리턴 : 트랜스퍼 번호
{
	return current_transfer->get_transfer_number();
}

int Person::get_possible_train_count()	// 리턴 : possible_train_count
{
	return possible_train_count;
}

int Person::get_possible_bus_count()	// 리턴 : possible_bus_count
{
	return possible_bus_count;	
}

Train* Person::get_possible_train_array()	// 리턴 : possible_train_array
{
	return possible_train_array[possible_train_count];
}

Bus* Person::get_possible_bus_array()	// 리턴 : possible_bus_array
{
	return possible_bus_array[possible_bus_count];
}

void Person::print_possible_vehicle()	// 이용가능한 트랜스퍼 출력
{
	cout<<"======== 이용가능한 트랜스퍼 출력 =========="<<endl<<endl;
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
void Person::print_remain_route()	// 몇정거장 남았는지 출력
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


void Person::print_person_info() // current_transfer 정보 출력
{
	if(current_transfer != 0)
	{
		cout<<"현재 타고 있는 트랜스퍼 : "<< current_transfer->get_transfer_number()<<endl;
		cout<<"현재 정류장 : "<< *current_transfer->get_current_position()<<endl;
		cout<<"현재 요금 : "<<price.get_transfer_price()<<endl;
		cout<<"남은 카드 잔액 : "<<price.get_card_change()<<endl;
	}

	else
	{
		cout << "현재 위치는 " << current_location << "입니다. " << endl;
		cout << "현재 타고 있는 트랜스퍼가 없습니다." << endl;
		cout <<"남은 카드 잔액 : "<<price.get_card_change()<<endl;
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

void Person::set_current_direction(bool _direction) // 입력 : direct
{
	current_direction = _direction;
}

bool Person::get_current_direction()		// 리턴 : direct
{
	return current_direction;
}