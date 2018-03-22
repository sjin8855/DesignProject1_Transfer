#include "Train.h"

Train::Train()
{
	train_type = 0;
}

void Train::set_train_type(int _type)	// 리턴 : train_type
{
	train_type = _type;
}

int Train::get_train_type()	// 리턴 : train_type
{
	return train_type;
}

void Train::train_move()	// train_type에 따라 급행은 2칸 이동, 일반은 1칸 이동 
{   
	//switch(train_type)
	//{
	//case 1:	//급행
	//	current_position++;
	//	if( current_position == route.end() )
	//		current_position = route.begin();
	//	current_position++;
	//	if( current_position == route.end() )
	//	current_position = route.begin();
	//	break;

	//case 2:	//일반
	//	current_position++;
	//	if( current_position == route.end() )
	//		current_position = route.begin();
	//	break;
	//}
	list<string>::iterator I;

	if(train_type == 1)
	{
		for(int i=0; i<2; i++) 
		{ // 급행은 2칸 이동이므로 for문 돌려주기
			if(direct == true) 
			{
				I = route.end();
				set_current_position(++current_position);
			}
			else 
			{
				I = route.begin();
				set_current_position(--current_position);
			}

			if(direct == false && current_position == I)
				direct = true;
			else if(direct == true && current_position == --I)
				direct = false;
		}
	}
	else
	{
		if(direct == true)
		{
			I = route.end();
			set_current_position(++current_position);
		}
		else
		{
			I = route.begin();
			set_current_position(--current_position);
		}

		if(direct == false && current_position == I)
			direct = true;
		else if(direct == true && current_position == --I)
			direct = false;
	}



}