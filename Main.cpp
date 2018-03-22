#include "TransferSystem.h"
#include <iomanip>
#include <iostream>

int main()
{
	TransferSystem trans;
	trans.load_transfer("Transfer_DB.txt");
	trans.print_menu();
	return 0;
}



