#include "Bus.h"

Bus::Bus()
{

}

void Bus::bus_move()
{
	/**current_position++;
	if( current_position == route.end() )
	current_position = route.begin();
	*/

	list<string>::iterator I;

	if(direct == true)
	{ // direction 이 true 이면 순방향
		I = route.end();
		set_current_position(++current_position); // current_position 을 다음 장소로 이동
	}
	else 
	{ // false 이면 역방향
		I = route.begin();
		set_current_position(--current_position); // current_position 을 전 장소로 이동
	}

	if(direct == false && current_position == I) // 현재 위치가 종점이라면 방향을 바꿔주는 구문
		direct = true;
	else if(direct == true && current_position == --I)
		direct = false;
}