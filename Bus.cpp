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
	{ // direction �� true �̸� ������
		I = route.end();
		set_current_position(++current_position); // current_position �� ���� ��ҷ� �̵�
	}
	else 
	{ // false �̸� ������
		I = route.begin();
		set_current_position(--current_position); // current_position �� �� ��ҷ� �̵�
	}

	if(direct == false && current_position == I) // ���� ��ġ�� �����̶�� ������ �ٲ��ִ� ����
		direct = true;
	else if(direct == true && current_position == --I)
		direct = false;
}