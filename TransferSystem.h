#include "Train.h"
#include "Bus.h"
#include "Person.h"
#include <Windows.h>
class TransferSystem
{
protected:
	Bus* bus_array[10];	// 로드된 bus
	Train* train_array[10];	// 로드된 train 
	int train_count;	// 로드된 train 개수
	int bus_count;	// 로드된 bus 개수
	Person person;	// Person 객체 생성
	Map map;	// Map 객체 생성
	bool check;
	

public:
	TransferSystem();
	
public:	// 로드에 필요한 함수
	void load_transfer(char* transfer_file);	// 파일 로드
	Bus* initialize(string _type, int _number);	// Bus 생성자 호출
	Train* initialize (string _type, int _number, int _train_type); // Train 생성자 호출

public:
	//이용 가능한 트랜스퍼 Train* possible_train_array[10], Bus* possible_bus_array[10] 저장
	//Person person객체 안에 있는 current_location변수에 “여의도” 저장
	void ride_possible_vehicle(string _name); // 이용 가능한 트랜스퍼 Train* possible_train_array[10], Bus* possible_bus_array[10] 저장
											  //Person person객체 안에 있는 current_location변수에 “여의도” 저장
	void ride_possible_move_vehicle(string _name);
	void transfer_move(); // Bus::bus_move() 호출, Train::train_move() 호출
	void take_transfer(int number, bool& One); // person.take_transfer(int _number); 호출
	void stop_person();	//현재 위치에 하차 person.current_location에 위치 저장, current_transfer에 NULL값
	void remain_routes();
	void price();
	
public:
	void print_map();	// 맵 출력
	void print_route();	// 노선도 출력
	void print_possible_vehicle();	// 이용가능한 트랜스퍼 출력, 호출 : person.print_ride_possible_vehicle();
	void print_remain_route();	// 몇정거장 남았는지 출력, 호출 : person.remain_route()
	void print_person_info();	// current_transfer 정보 출력
	void print_train_location(int count);	// Train* train_array[10], Bus* bus_array[10] 현재 위치 출력
	void print_bus_location(int count);
	void print_menu();		//메뉴 출력을 위한 함수(추가)
};


