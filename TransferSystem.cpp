#include "TransferSystem.h"
#include <sstream>
#include <iomanip>

TransferSystem::TransferSystem()	//기본생성자
{
	train_count = 0;
	bus_count = 0;
}

void TransferSystem::load_transfer(char* transfer_file)	// 파일 로드
{
	ifstream fin(transfer_file);
	string record;
	string type, route;
	int number, train_type;
	while (getline(fin, record))
	{
		stringstream inf(record);
		inf >> type >> number;

		if (type=="Bus")
		{
			bus_array[bus_count]= initialize(type, number);

			while( inf >> route)
				bus_array[bus_count] -> set_route_add( route );
			bus_array[bus_count] -> clear_current_position();
			bus_count++;
		}

		else if (type=="Train")
		{
			inf >> train_type;
			train_array[train_count] = initialize(type, number, train_type);

			while( inf >> route)
				train_array[train_count] -> set_route_add( route );
			train_array[train_count] -> clear_current_position();
			train_count++;
		}
	}
	fin.close();
}
Bus* TransferSystem::initialize(string _type, int _number)		// Bus 생성자 호출
{
	Bus* bus;
	bus = new Bus();
	bus ->set_transfer_number(_number);
	bus ->set_remain_route(0);
	return bus;
}

Train* TransferSystem::initialize(string _type, int _number, int _train_type)	// Train 생성자 호출
{
	Train* train;
	train = new Train();
	train ->set_transfer_number(_number);
	train ->set_train_type(_train_type);
	train ->set_remain_route(0);
	return train;
}

void TransferSystem::ride_possible_vehicle(string _name)	//이용 가능한 트랜스퍼 Train* possible_train_array[10], Bus* possible_bus_array[10] 저장	
{															//Person person객체 안에 있는 current_location변수에 “여의도” 저장
	//person.initial_possible();
	Transfer* transfer = NULL;
	person.set_transfer(*transfer);
	person.set_current_location(_name);
	person.set_possible_bus_count(0);
	person.set_possible_train_count(0);

	for(int i=0; i<bus_count; i++)
	{
		list<string>::iterator start_bus = bus_array[i]->get_begin_route();
		list<string>::iterator end_bus = bus_array[i]->get_end_route();
		while(start_bus!=end_bus)
		{
			if(*start_bus == _name)
			{
				person.set_possible_bus_array(bus_array[i]);
				break;
			}
			start_bus++;
		}
	}

	for(int i=0; i<train_count; i++)
	{
		list<string>::iterator start_train = train_array[i]->get_begin_route();
		list<string>::iterator end_train = train_array[i]->get_end_route();
		while(start_train!=end_train)
		{	
			if(*start_train == _name)
			{
				person.set_possible_train_array(train_array[i]);
				break;
			}
			start_train++;
		}
	}

}

void TransferSystem::ride_possible_move_vehicle(string _name)
{
	person.set_current_location(_name);
	person.set_possible_bus_count(0);
	person.set_possible_train_count(0);
	for(int i=0; i<bus_count; i++)
	{
		list<string>::iterator start_bus = bus_array[i]->get_begin_route();
		list<string>::iterator end_bus = bus_array[i]->get_end_route();
		while(start_bus!=end_bus)
		{	
			if(*start_bus == _name)
			{
				person.set_possible_bus_array(bus_array[i]);
				break;
			}
			start_bus++;
		}
	}

	for(int i=0; i<train_count; i++)
	{
		list<string>::iterator start_train = train_array[i]->get_begin_route();
		list<string>::iterator end_train = train_array[i]->get_end_route();
		while(start_train!=end_train)
		{	
			if(*start_train == _name)
			{
				person.set_possible_train_array(train_array[i]);
				break;
			}
			start_train++;
		}
	}
}
void TransferSystem::transfer_move()		// Bus::bus_move() 호출, Train::train_move() 호출
{											// 한 정거장씩 이동
	if(person.get_transfer()==NULL)
	{
		for(int i=0; i<train_count; i++)
		{
			cout<<train_array[i]->get_transfer_number()<<" : "
				<<train_array[i]->get_train_type()<<" : "
				<<*train_array[i]->get_current_position()<<" -> ";
			
			train_array[i]->train_move();
			print_train_location(i);
		}

		for(int i=0; i<bus_count; i++)
		{
			cout<<bus_array[i]->get_transfer_number()<<" : " 
				<<*bus_array[i]->get_current_position()<<" -> ";
			bus_array[i]->bus_move();
			print_bus_location(i);
		}
	}
	
	else
	{
		for(int i=0; i<train_count; i++)
		{
			cout<<train_array[i]->get_transfer_number()<<" : "
				<<train_array[i]->get_train_type()<<" : "
				<<*train_array[i]->get_current_position()<<" -> ";
			train_array[i]->train_move();
			print_train_location(i);
		}

		for(int i=0; i<bus_count; i++)
		{
			cout<<bus_array[i]->get_transfer_number()<<" : " 
				<<*bus_array[i]->get_current_position()<<" -> ";
			bus_array[i]->bus_move();
			print_bus_location(i);
		}
		person.set_current_location(*person.get_transfer()->get_current_position());
		ride_possible_move_vehicle(*person.get_transfer()->get_current_position());
		price();
		//person.get_price().set_transfer_price(person.get_price().get_transfer_price()+10);
	}
}	

void TransferSystem::take_transfer(int number, bool& One)	 // person.take_transfer(int _number); 호출
{
	person.take_transfer(number, One);
}
void TransferSystem::stop_person()		//현재 위치에 하차 person.current_location에 위치 저장, current_transfer에 NULL값
{
	int money;
	if(person.get_transfer() != NULL)
	{
		/*string location = person.get_current_location();*/
		Transfer* transfer = NULL;
		person.set_transfer(*transfer);
		person.set_price(person.get_price().get_card_change()-person.get_price().get_transfer_price());
		
		while(true)
		{
			if(person.get_price().get_card_change()>=0)
			{
				//person.get_price().set_card_change(person.get_price().get_card_change()-(person.get_price().get_transfer_price()+100));
				person.set_price(person.get_price().get_card_change() - (person.get_price().get_transfer_price()+100));
				person.get_price().set_transfer_price(0);
				cout << "========= 하차하였습니다. =========" << endl;
				cout << "남은 카드 잔액 : "<<person.get_price().get_card_change()<<endl;
				break;
			}

			else
			{
				person.get_price().set_card_change(person.get_price().get_card_change());
				cout<<"잔액이 부족합니다. 충천해주세요."<<endl;
				cout<<"충전할 금액 : ";
				cin>>money;
				person.set_price(person.get_price().get_card_change()+money);
		
			}
		}
		person.get_price().set_transfer_price(0);
		/*person.set_current_location(location);*/
	}
	else
		cout << "========= 승차하지 않았습니다. =========" << endl;
}

void TransferSystem::remain_routes()	//호출 : Person.remain_route()
{
	person.remain_route();
}

void TransferSystem::print_map()
{
	map.print_map();
}

void TransferSystem::print_route()		// Train* train_array[10], Bus* bus_array[10] 출력
{
	for(int i=0; i<train_count; i++)	//기차
	{
		list<string>::iterator start_train = train_array[i]->get_begin_route();
		list<string>::iterator end_train = train_array[i]->get_end_route();
		cout<<train_array[i]->get_transfer_number()<<" : "<< train_array[i]->get_train_type()<<" : ";
		while(start_train!=end_train)
		{
			cout<<*start_train<<" ";
			start_train++;
		}
		cout<<endl;
	}
	for(int i=0; i<bus_count; i++)	//버스
	{
		list<string>::iterator start_bus = bus_array[i]->get_begin_route();
		list<string>::iterator end_bus = bus_array[i]->get_end_route();
		cout<<bus_array[i]->get_transfer_number()<<" : ";
		while(start_bus != end_bus)
		{
			cout<<*start_bus<<" ";
			start_bus++;
		}
		cout<<endl;
	}
}

void TransferSystem::print_possible_vehicle()	// 이용가능한 트랜스퍼 출력, 호출 : person.print_ride_possible_vehicle();
{
	person.print_possible_vehicle();
	// 이용가능한 트랜스퍼 출력
}

void TransferSystem::print_remain_route()	// 몇정거장 남았는지 출력, 호출 : person.print_remain_route()
{
	person.print_remain_route();
}

void TransferSystem::print_person_info()	// 호출 : person.print_person_info(), current_transfer 정보 출력
{
	person.print_person_info();
}

void TransferSystem::print_train_location(int count)	//Train* train_array[10], Bus* bus_array[10] 현재 위치 출력
{
	list<string>::iterator current_train = train_array[count]->get_current_position();
	cout<<*current_train<<endl;
}

void TransferSystem::print_bus_location(int count)
{
	list<string>::iterator current_bus = bus_array[count]->get_current_position();
	cout<<*current_bus<<endl;
}

void TransferSystem::print_menu()
{
	bool One = true;
	while(true)
	{
		int sellect_num;
		string loca;
		int transfer_num;
		Transfer trans;
		bool direct;

		cout<<"┌───────────────────────┐"<<endl;
		cout<<"│      Menu                                    │"<<endl;
		cout<<"│                                              │"<<endl;
		cout<<"│1. Map print                                  │"<<endl;
		cout<<"│2. Transfer print                             │"<<endl;
		cout<<"│3. Location input                             │"<<endl;
		cout<<"│4. Location information                       │"<<endl;
		cout<<"│5. Transfer select                            │"<<endl;
		cout<<"│6. Transfer get off                           │"<<endl;
		cout<<"│7. Transfer move                              │"<<endl;
		cout<<"│8. Person information                         │"<<endl;
		cout<<"│0. END			                │"<<endl;
		cout<<"└───────────────────────┘"<<endl<<endl;

		cout<<"Menu number : ";
		cin >> sellect_num;
		switch(sellect_num)
		{
		case 1:
			map.print_map();
			system("pause");
			system("cls");
			break;

		case 2:
			print_route();
			system("pause");
			system("cls");
			break;

		case 3:
			while(true)
			{
				check = false;
				cout<<"현재 위치를 입력하세요 : ";
				cin >> loca;
				/*cout<<"방향을 입력해주세요 (0: 역방향, 1: 순방향) : ";
				cin >> direct;
				person.set_current_direction(direct);*/
				for(int i=0; i<bus_count; i++)
				{
					list<string>::iterator start_bus = bus_array[i]->get_begin_route();
					list<string>::iterator end_bus = bus_array[i]->get_end_route();

					while(start_bus!=end_bus)
					{
						if(*start_bus == loca)
						{
							check = true;
							break;
						}
						start_bus++;
					}
				}

				for(int i=0; i<train_count; i++)
				{
					list<string>::iterator start_train = train_array[i]->get_begin_route();
					list<string>::iterator end_train = train_array[i]->get_end_route();

					while(start_train!=end_train)
					{
						if(*start_train == loca)
						{
							check = true;
							break;
						}
						start_train++;
					}
				}

				if(check == true)
				{
					ride_possible_vehicle(loca);
					break;
				}
				else
					cout<<"없는 지역입니다. 다시입력해주세요."<<endl;
			}
			print_possible_vehicle();
			system("pause");
			system("cls");
			break;


		case 4:
			print_possible_vehicle();
			print_remain_route();
			system("pause");
			system("cls");
			break;

		case 5:
			person.print_remain_route();
			cout<<"======= 탑승할 트랜스퍼를 정하세요 ========="<<endl<<endl;
			cin>>transfer_num;			
			take_transfer(transfer_num, One);
			system("pause");
			system("cls");
			break;

		case 6:		
			stop_person();
			system("pause");
			system("cls");
			break;	
			/*current_location = 영통
			person.current_transfer = NULL*/ 
		case 7:
			transfer_move();
			move_count++;
			
			system("pause");
			system("cls");
			break;

		case 8:
			print_person_info();
			system("pause");
			system("cls");
			break;

		case 0:
			exit(100);

		default:
			cout<<"잘못 입력하셨습니다. 다시 입력해주세요."<<endl;
			break;
			
			
		}		
	}
}

void TransferSystem::price()
{
	person._price();
}
