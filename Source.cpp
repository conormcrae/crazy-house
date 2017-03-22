#include <iostream>
#include "Piece.h"

void welcome_message()
{
	std::cout << "Welcome to the ConMax 0.1 Chess Engine.\nYou play white (shown in capital letters) against ConMax (who plays black, shown in lowercase letters.)\n\nGood luck!\n\n\n";
}

int main()
{
	welcome_message();
	bool you_win = false;
	Board b = Board();

	b.view();

	while (!you_win){
		b.move();
		
		if (b.checkmate())
		{
			you_win = true;
			break;
		}
		
		b.solver(4);
		b.view();
		std::cout << "\n\n";
	}

	std::cout << "\n\n\n\Checkmate!\nCongratulations, you won!";

	return 0;
}