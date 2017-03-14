#include <iostream>
#include "Piece.h"





int main()
{

	Board b = Board();
	b.view();
	bool t = b.in_check();

	if (t)
		std::cout << "you are in check! \n\n";
	else
		std::cout << "you are NOT in check \n\n";

	return 0;
}