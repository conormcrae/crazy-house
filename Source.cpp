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

	//b.toggle_move_color();
	b.solver(4);

	b.view();

	

	return 0;
}