#include "Piece.h"



Board::Board()
{
	white2move = true;
	score = 0.0;

		// initialize white pieces
	board[0][0] = new std::pair<Piece, Color>();
	board[0][1] = new std::pair<Piece, Color>();
	board[0][2] = new std::pair<Piece, Color>();
	board[0][3] = new std::pair<Piece, Color>();
	board[0][4] = new std::pair<Piece, Color>();
	board[0][5] = new std::pair<Piece, Color>();
	board[0][6] = new std::pair<Piece, Color>();
	board[0][7] = new std::pair<Piece, Color>();
	board[1][0] = new std::pair<Piece, Color>(); // pawns
	board[1][1] = new std::pair<Piece, Color>();
	board[1][2] = new std::pair<Piece, Color>();
	board[1][3] = new std::pair<Piece, Color>();
	board[1][4] = new std::pair<Piece, Color>();
	board[1][5] = new std::pair<Piece, Color>();
	board[1][6] = new std::pair<Piece, Color>();
	board[1][7] = new std::pair<Piece, Color>();

	board[0][0]->first = Piece::ROOK;
	board[0][1]->first = Piece::KNIGHT;
	board[0][2]->first = Piece::BISHOP;
	board[0][3]->first = Piece::QUEEN;
	board[0][4]->first = Piece::KING;
	board[0][5]->first = Piece::BISHOP;
	board[0][6]->first = Piece::KNIGHT;
	board[0][7]->first = Piece::ROOK;
	board[1][0]->first = Piece::PAWN;
	board[1][1]->first = Piece::PAWN;
	board[1][2]->first = Piece::PAWN;
	board[1][3]->first = Piece::PAWN;
	board[1][4]->first = Piece::PAWN;
	board[1][5]->first = Piece::PAWN;
	board[1][6]->first = Piece::PAWN;
	board[1][7]->first = Piece::PAWN;

	board[0][0]->second = Color::WHITE;
	board[0][1]->second = Color::WHITE;
	board[0][2]->second = Color::WHITE;
	board[0][3]->second = Color::WHITE;
	board[0][4]->second = Color::WHITE;
	board[0][5]->second = Color::WHITE;
	board[0][6]->second = Color::WHITE;
	board[0][7]->second = Color::WHITE;
	board[1][0]->second = Color::WHITE;
	board[1][1]->second = Color::WHITE;
	board[1][2]->second = Color::WHITE;
	board[1][3]->second = Color::WHITE;
	board[1][4]->second = Color::WHITE;
	board[1][5]->second = Color::WHITE;
	board[1][6]->second = Color::WHITE;
	board[1][7]->second = Color::WHITE;


		// initialize black pieces
	board[7][0] = new std::pair<Piece, Color>();
	board[7][1] = new std::pair<Piece, Color>();
	board[7][2] = new std::pair<Piece, Color>();
	board[7][3] = new std::pair<Piece, Color>();
	board[7][4] = new std::pair<Piece, Color>();
	board[7][5] = new std::pair<Piece, Color>();
	board[7][6] = new std::pair<Piece, Color>();
	board[7][7] = new std::pair<Piece, Color>();
	board[6][0] = new std::pair<Piece, Color>(); // pawns
	board[6][1] = new std::pair<Piece, Color>();
	board[6][2] = new std::pair<Piece, Color>();
	board[6][3] = new std::pair<Piece, Color>();
	board[6][4] = new std::pair<Piece, Color>();
	board[6][5] = new std::pair<Piece, Color>();
	board[6][6] = new std::pair<Piece, Color>();
	board[6][7] = new std::pair<Piece, Color>();

	board[7][0]->first = Piece::ROOK;
	board[7][1]->first = Piece::KNIGHT;
	board[7][2]->first = Piece::BISHOP;
	board[7][3]->first = Piece::QUEEN;
	board[7][4]->first = Piece::KING;
	board[7][5]->first = Piece::BISHOP;
	board[7][6]->first = Piece::KNIGHT;
	board[7][7]->first = Piece::ROOK;
	board[6][0]->first = Piece::PAWN;
	board[6][1]->first = Piece::PAWN;
	board[6][2]->first = Piece::PAWN;
	board[6][3]->first = Piece::PAWN;
	board[6][4]->first = Piece::PAWN;
	board[6][5]->first = Piece::PAWN;
	board[6][6]->first = Piece::PAWN;
	board[6][7]->first = Piece::PAWN;

	board[7][0]->second = Color::BLACK;
	board[7][1]->second = Color::BLACK;
	board[7][2]->second = Color::BLACK;
	board[7][3]->second = Color::BLACK;
	board[7][4]->second = Color::BLACK;
	board[7][5]->second = Color::BLACK;
	board[7][6]->second = Color::BLACK;
	board[7][7]->second = Color::BLACK;
	board[6][0]->second = Color::BLACK;
	board[6][1]->second = Color::BLACK;
	board[6][2]->second = Color::BLACK;
	board[6][3]->second = Color::BLACK;
	board[6][4]->second = Color::BLACK;
	board[6][5]->second = Color::BLACK;
	board[6][6]->second = Color::BLACK;
	board[6][7]->second = Color::BLACK;

		// initialize empty squares
	for (int i = 2; i < 6; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = new std::pair<Piece, Color>();
			board[i][j]->first = Piece::EMPTY;
			board[i][j]->second = Color::NO_COLOR;
		}
	}

}

Board::Board(const Board& b)
{
	white2move = b.white2move;
	score = b.score;
	//std::copy(b.board, b.board + 64, board); /*error, see http://forums.codeguru.com/showthread.php?473053-RESOLVED-Trouble-with-std-fill */
}

Board& Board::operator = (Board copy)
{
	swap(*this, copy);
	return *this;
}

void swap(Board& left, Board& right)
{
	std::swap(left.board, right.board);
	std::swap(left.score, right.score);
	std::swap(left.white2move, right.white2move);
}

/**
Board::~Board()
{
	delete[] board;
}
*/

void Board::set_score()
{
	double score = 0.0;

		// the following nested for loop updates the score based strictly on material balance
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			switch (board[i][j]->first)
			{
			case Piece::PAWN:
				if (board[i][j]->second == Color::WHITE)
					score += 1.0;
				else
					score -= 1.0;
			case Piece::BISHOP:
				if (board[i][j]->second == Color::WHITE)
					score += 3.0;
				else
					score -= 3.0;
			case Piece::KNIGHT:
				if (board[i][j]->second == Color::WHITE)
					score += 3.0;
				else
					score -= 3.0;
			case Piece::ROOK:
				if (board[i][j]->second == Color::WHITE)
					score += 5.0;
				else
					score -= 5.0;
			case Piece::QUEEN:
				if (board[i][j]->second == Color::WHITE)
					score += 9.0;
				else
					score -= 9.0;
			default:
				break;
			}
		}
	}


	// add code here to update score based on king safety, piece mobility, etc.

	this->score = score;
}

double Board::get_score()
{
	return score;
}

bool Board::get_move_color()
{
	return white2move;
}

void Board::view()
{
	for (int rank = 7; rank >= 0; --rank)
	{
		for (int file = 0; file < 8; ++file)
		{
			switch (board[rank][file]->first)
			{
			case Piece::PAWN:
				std::cout << "P" << " ";
				break;
			case Piece::BISHOP:
				std::cout << "B" << " ";
				break;
			case Piece::KNIGHT:
				std::cout << "N" << " ";
				break;
			case Piece::ROOK:
				std::cout << "R" << " ";
				break;
			case Piece::QUEEN:
				std::cout << "Q" << " ";
				break;
			case Piece::KING:
				std::cout << "K" << " ";
				break;
			default:
				std::cout << "  ";
				break;
			}
		}

		std::cout << "\n\n";
	}
}

bool Board::in_check()
{
	int krank;
	int kfile;

	Color color = Color::BLACK;
	if (white2move)
		color = Color::WHITE;

	for (int i = 0; i < 8; ++i) // get location of King
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j]->first == Piece::KING && board[i][j]->second == color)
			{
				krank = i;
				kfile = j;
			}
		}
	}

	// see if a pawn is checking the king
	if (color == Color::WHITE && krank < 6) // no way a pawn can check the white king on the 7th/8th ranks
	{

		if (kfile == 7)
		{
			if (board[krank + 1][kfile - 1]->first == Piece::PAWN && board[krank + 1][kfile - 1]->second == Color::BLACK)
				return true;
		}
		else if (kfile == 0)
		{
			if (board[krank + 1][kfile + 1]->first == Piece::PAWN && board[krank + 1][kfile + 1]->second == Color::BLACK)
				return true;
		}
		else if ((board[krank + 1][kfile + 1]->first == Piece::PAWN && board[krank + 1][kfile + 1]->second == Color::BLACK) || (board[krank + 1][kfile - 1]->first == Piece::PAWN && board[krank + 1][kfile - 1]->second == Color::BLACK))
			return true;

	}
	else if (color == Color::BLACK && krank > 1)
	{
		
		if (kfile == 7)
		{
			if (board[krank - 1][kfile - 1]->first == Piece::PAWN && board[krank - 1][kfile - 1]->second == Color::WHITE)
				return true;
		}
		else if (kfile == 0)
		{
			if (board[krank - 1][kfile + 1]->first == Piece::PAWN && board[krank - 1][kfile + 1]->second == Color::WHITE)
				return true;
		}
		else if ((board[krank - 1][kfile + 1]->first == Piece::PAWN && board[krank - 1][kfile + 1]->second == Color::WHITE) || (board[krank - 1][kfile - 1]->first == Piece::PAWN && board[krank - 1][kfile - 1]->second == Color::WHITE))
			return true;

	} 

	// see if a knight is checking the King
	if (krank + 2 < 8 && kfile + 1 < 8 && board[krank + 2][kfile + 1]->first == Piece::KNIGHT && board[krank + 2][kfile + 1]->second != color)
		return true;
	if (krank + 1 < 8 && kfile + 2 < 8 && board[krank + 1][kfile + 2]->first == Piece::KNIGHT && board[krank + 1][kfile + 2]->second != color)
		return true;
	if (krank - 1 >= 0 && kfile + 2 < 8 && board[krank - 1][kfile + 2]->first == Piece::KNIGHT && board[krank - 1][kfile + 2]->second != color)
		return true;
	if (krank - 2 >= 0 && kfile + 1 < 8 && board[krank - 2][kfile + 1]->first == Piece::KNIGHT && board[krank - 2][kfile + 1]->second != color)
		return true;
	if (krank - 2 >= 0 && kfile - 1 >= 0 && board[krank - 2][kfile - 1]->first == Piece::KNIGHT && board[krank - 2][kfile - 1]->second != color)
		return true;
	if (krank - 1 >= 0 && kfile - 2 >= 0 && board[krank - 1][kfile - 2]->first == Piece::KNIGHT && board[krank - 1][kfile - 2]->second != color)
		return true;
	if (krank + 1 < 8 && kfile - 2 >= 0 && board[krank + 1][kfile - 2]->first == Piece::KNIGHT && board[krank + 1][kfile - 2]->second != color)
		return true;
	if (krank + 2 < 8 && kfile - 1 >= 0 && board[krank + 2][kfile - 1]->first == Piece::KNIGHT && board[krank + 2][kfile - 1]->second != color)
		return true;

	//see if a bishop/queen is checking the king
	int r = krank + 1;
	int f = kfile + 1;
	while (r < 8 && f < 8 && board[r][f]->first == Piece::EMPTY) // assert we are within the board's dimensions and check squares along the upper-right diagonal
	{
		++r;
		++f;
	}
	if (r < 8 && f < 8 && board[r][f]->second != color && (board[r][f]->first == Piece::BISHOP || board[r][f]->first == Piece::QUEEN)) // if first nonempty sqare is 
		return true;

	r = krank - 1;
	f = kfile - 1;
	while (r >= 0 && f >= 0 && board[r][f]->first == Piece::EMPTY) // lower-left diagonal
	{
		--r;
		--f;
	}
	if (r >= 0 && f >= 0 && board[r][f]->second != color && (board[r][f]->first == Piece::BISHOP || board[r][f]->first == Piece::QUEEN)) // if first nonempty sqare is 
		return true;

	r = krank + 1;
	f = kfile - 1;
	while (r < 8 && f >= 0 && board[r][f]->first == Piece::EMPTY) // upper-left
	{
		++r;
		--f;
	}
	if (r < 8 && f >= 0 && board[r][f]->second != color && (board[r][f]->first == Piece::BISHOP || board[r][f]->first == Piece::QUEEN)) // if first nonempty sqare is 
		return true;

	r = krank - 1;
	f = kfile + 1;
	while (r >= 0 && f < 8 && board[r][f]->first == Piece::EMPTY) // lower right
	{
		--r;
		++f;
	}
	if (r >= 0 && f < 8 && board[r][f]->second != color && (board[r][f]->first == Piece::BISHOP || board[r][f]->first == Piece::QUEEN)) // if first nonempty sqare is 
		return true;

	// see if rook/queen is checking king
	r = krank + 1;
	f = kfile;
	while (r < 8 && board[r][f]->first == Piece::EMPTY) // assert we are within the board's dimensions and check squares above until we get one that is nonempty
	{
		++r;
	}
	if (r < 8 && board[r][f]->second != color && (board[r][f]->first != Piece::ROOK || board[r][f]->first != Piece::QUEEN)) // first nonempty square so check if it is rook.queen of opp color
		return true;

	r = krank - 1;
	while (r >= 0 && board[r][f]->first == Piece::EMPTY) // squares below
	{
		--r;
	}
	if (r >= 0 && board[r][f]->second != color && (board[r][f]->first != Piece::ROOK || board[r][f]->first != Piece::QUEEN)) // first nonempty square so check if it is rook.queen of opp color
		return true;

	r = krank;
	f = kfile - 1;
	while (f >= 0 && board[r][f]->first == Piece::EMPTY) // squares left
	{
		--f;
	}
	if (f <= 0 && board[r][f]->second != color && (board[r][f]->first != Piece::ROOK || board[r][f]->first != Piece::QUEEN))// first nonempty square so check if it is rook.queen of opp color
		return true;

	f = kfile + 1;
	while (f >= 0 && board[r][f]->first == Piece::EMPTY) // right
	{
		++f;
	}
	if (f < 8 && board[r][f]->second != color && (board[r][f]->first != Piece::ROOK || board[r][f]->first != Piece::QUEEN)) // first nonempty square so check if it is rook.queen of opp color
		return true;

	// king v. king. This is to prevent AI from being able to move king next to player's king.
	if (krank == 0 && kfile == 0)
	{
		if (board[krank + 1][kfile + 1]->first == Piece::KING || board[krank + 1][kfile]->first == Piece::KING || board[krank][kfile + 1]->first == Piece::KING)
			return true;
	}
	else if (krank == 0 && kfile == 7)
	{
		if (board[krank + 1][kfile]->first == Piece::KING || board[krank + 1][kfile - 1]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING)
			return true;
	}
	else if (krank == 7 && kfile == 0)
	{
		if (board[krank - 1][kfile]->first == Piece::KING || board[krank - 1][kfile - 1]->first == Piece::KING || board[krank][kfile + 1]->first == Piece::KING)
			return true;
	}
	else if (krank == 7 && kfile == 7)
	{
		if (board[krank - 1][kfile - 1]->first == Piece::KING || board[krank - 1][kfile]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING)
			return true;
	} // king isn't in a corner
	else if (krank == 0)
	{
		if (board[krank + 1][kfile + 1]->first == Piece::KING || board[krank + 1][kfile]->first == Piece::KING || board[krank + 1][kfile - 1]->first == Piece::KING
			|| board[krank][kfile + 1]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING)
			return true;
	}
	else if (krank == 7)
	{
		if (board[krank][kfile + 1]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING 
			|| board[krank - 1][kfile + 1]->first == Piece::KING || board[krank - 1][kfile]->first == Piece::KING || board[krank - 1][kfile - 1]->first == Piece::KING)
			return true;
	}
	else if (kfile == 0)
	{
		if (board[krank + 1][kfile]->first == Piece::KING || board[krank + 1][kfile + 1]->first == Piece::KING || board[krank][kfile + 1]->first == Piece::KING
			|| board[krank - 1][kfile + 1]->first == Piece::KING || board[krank - 1][kfile]->first == Piece::KING)
			return true;
	}
	else if (kfile == 7)
	{
		if (board[krank + 1][kfile]->first == Piece::KING || board[krank + 1][kfile - 1]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING
			|| board[krank - 1][kfile - 1]->first == Piece::KING || board[krank - 1][kfile]->first == Piece::KING)
			return true;
	} // king isn't on the rim
	else if (board[krank + 1][kfile + 1]->first == Piece::KING || board[krank + 1][kfile]->first == Piece::KING || board[krank + 1][kfile - 1]->first == Piece::KING
		|| board[krank][kfile + 1]->first == Piece::KING || board[krank][kfile - 1]->first == Piece::KING
		|| board[krank - 1][kfile + 1]->first == Piece::KING || board[krank - 1][kfile]->first == Piece::KING || board[krank - 1][kfile - 1]->first == Piece::KING)
	{
		return true;
	}


	return false; // after all that, we aren't in check. 
}

/**
@brief possible_moves recieves a rank and a file and returns the possible moves of the piece at that position
@param rank is the rank of the piece
@param file is the file the piece is on
@return is a vector of pairs. Each pair is of the form (x, y), where this coordinate represents a valid square for this piece to be moved to.
*/
std::vector<std::pair<int, int>> Board::possible_moves(int rank, int file)
{
	std::vector<std::pair<int, int>> moves;

	switch (board[rank][file]->first)
	{

	case Piece::PAWN:
	{
		if (board[rank][file]->second == Color::WHITE)
		{
			if (board[rank + 1][file]->second == Color::NO_COLOR) // checks if square in front of pawn is open
				moves.push_back(std::make_pair(rank + 1, file));

			if (rank == 1 && board[rank + 2][file]->second == Color::NO_COLOR && board[rank + 1][file]->second == Color::NO_COLOR) // pawn hasn't moved yet so we check for 2 space move
				moves.push_back(std::make_pair(rank + 2, file));

			if (file == 0) // pawn is on the "a file"
			{
				if (board[rank + 1][file + 1]->second == Color::BLACK)
					moves.push_back(std::make_pair(rank + 1, file + 1));
			}
			else if (file == 7) // pawn is on the "h file"
			{
				if (board[rank + 1][file - 1]->second == Color::BLACK)
					moves.push_back(std::make_pair(rank + 1, file - 1));
			}
			else // pawn is not at the edge of the board
			{
				if (board[rank + 1][file + 1]->second == Color::BLACK)
					moves.push_back(std::make_pair(rank + 1, file + 1));
				if (board[rank + 1][file - 1]->second == Color::BLACK)
					moves.push_back(std::make_pair(rank + 1, file - 1));
			}
		}
		else // pawn is black
		{
			if (board[rank - 1][file]->second == Color::NO_COLOR) // checks if square in front of pawn is open
				moves.push_back(std::make_pair(rank - 1, file));

			if (rank == 6 && board[rank - 2][file]->second == Color::NO_COLOR && board[rank - 1][file]->second == Color::NO_COLOR) // pawn hasn't moved yet so we check for 2 space move
				moves.push_back(std::make_pair(rank + 2, file));

			if (file == 0) // pawn is on the "a file"
			{
				if (board[rank - 1][file + 1]->second == Color::WHITE)
					moves.push_back(std::make_pair(rank - 1, file + 1));
			}
			else if (file == 7) // pawn is on the "h file"
			{
				if (board[rank - 1][file - 1]->second == Color::WHITE)
					moves.push_back(std::make_pair(rank - 1, file - 1));
			}
			else // pawn is not at the edge of the board
			{
				if (board[rank - 1][file + 1]->second == Color::WHITE)
					moves.push_back(std::make_pair(rank - 1, file + 1));
				if (board[rank - 1][file - 1]->second == Color::WHITE)
					moves.push_back(std::make_pair(rank - 1, file - 1));
			}
		}
	}
	case Piece::BISHOP:
	{
		int r = rank + 1;
		int f = file + 1;
		while (r < 8 && f < 8 && board[r][f]->second != board[rank][file]->second) // assert we are within the board's dimensions and check squares along the upper-right diagonal
		{
			moves.push_back(std::make_pair(r, f));
			++r;
			++f;
		}

		r = rank - 1;
		f = file - 1;
		while (r >= 0 && f >= 0 && board[r][f]->second != board[rank][file]->second) // lower-left diagonal
		{
			moves.push_back(std::make_pair(r, f));
			--r;
			--f;
		}

		r = rank + 1;
		f = file - 1;
		while (r < 8 && f >= 0 && board[r][f]->second != board[rank][file]->second) // upper-left
		{
			moves.push_back(std::make_pair(r, f));
			++r;
			--f;
		}

		r = rank - 1;
		f = file + 1;
		while (r >= 0 && f < 8 && board[r][f]->second != board[rank][file]->second) // lower right
		{
			moves.push_back(std::make_pair(r, f));
			--r;
			++f;
		}
	}
	case Piece::KNIGHT:
	{
		if (rank + 2 < 8 && file + 1 < 8 && board[rank][file]->second != board[rank + 2][file + 1]->second)
			moves.push_back(std::make_pair(rank + 2, file + 1));
		if (rank + 1 < 8 && file + 2 < 8 && board[rank][file]->second != board[rank + 1][file + 2]->second)
			moves.push_back(std::make_pair(rank + 1, file + 2));
		if (rank - 1 >= 0 && file + 2 < 8 && board[rank][file]->second != board[rank - 1][file + 2]->second)
			moves.push_back(std::make_pair(rank - 1, file + 2));
		if (rank - 2 >= 0 && file + 1 < 8 && board[rank][file]->second != board[rank - 2][file + 1]->second)
			moves.push_back(std::make_pair(rank - 2, file + 1));
		if (rank - 2 >= 0 && file - 1 >= 0 && board[rank][file]->second != board[rank - 2][file - 1]->second)
			moves.push_back(std::make_pair(rank - 2, file - 1));
		if (rank - 1 >= 0 && file - 2 >= 0 && board[rank][file]->second != board[rank - 1][file - 2]->second)
			moves.push_back(std::make_pair(rank - 1, file - 2));
		if (rank + 1 < 8 && file - 2 >= 0 && board[rank][file]->second != board[rank + 1][file - 2]->second)
			moves.push_back(std::make_pair(rank + 1, file - 2));
		if (rank + 2 < 8 && file - 1 >= 0 && board[rank][file]->second != board[rank + 2][file - 1]->second)
			moves.push_back(std::make_pair(rank + 2, file - 1));
	}
	case Piece::ROOK:
	{
		int r = rank + 1;
		int f = file;
		while (r < 8 && board[r][f]->second != board[rank][file]->second) // assert we are within the board's dimensions and check squares above
		{
			moves.push_back(std::make_pair(r, f));
			++r;
		}

		r = rank - 1;
		while (r >= 0 && board[r][f]->second != board[rank][file]->second) // squares below
		{
			moves.push_back(std::make_pair(r, f));
			--r;
		}

		r = rank;
		f = file - 1;
		while (f >= 0 && board[r][f]->second != board[rank][file]->second) // squares left
		{
			moves.push_back(std::make_pair(r, f));
			--f;
		}

		f = file + 1;
		while (f >= 0 && board[r][f]->second != board[rank][file]->second) // right
		{
			moves.push_back(std::make_pair(r, f));
			++f;
		}
	}
	case Piece::QUEEN:
	{
		// bishop-type moves
		int r = rank + 1;
		int f = file + 1;
		while (r < 8 && f < 8 && board[r][f]->second != board[rank][file]->second) // assert we are within the board's dimensions and check squares along the upper-right diagonal
		{
			moves.push_back(std::make_pair(r, f));
			++r;
			++f;
		}

		r = rank - 1;
		f = file - 1;
		while (r >= 0 && f >= 0 && board[r][f]->second != board[rank][file]->second) // lower-left diagonal
		{
			moves.push_back(std::make_pair(r, f));
			--r;
			--f;
		}

		r = rank + 1;
		f = file - 1;
		while (r < 8 && f >= 0 && board[r][f]->second != board[rank][file]->second) // upper-left
		{
			moves.push_back(std::make_pair(r, f));
			++r;
			--f;
		}

		r = rank - 1;
		f = file + 1;
		while (r < 8 && f >= 0 && board[r][f]->second != board[rank][file]->second) // lower right
		{
			moves.push_back(std::make_pair(r, f));
			--r;
			++f;
		}

		// rook-type moves
		r = rank + 1;
		f = file;
		while (r < 8 && board[r][f]->second != board[rank][file]->second) // assert we are within the board's dimensions and check squares above
		{
			moves.push_back(std::make_pair(r, f));
			++r;
		}

		r = rank - 1;
		while (r >= 0 && board[r][f]->second != board[rank][file]->second) // squares below
		{
			moves.push_back(std::make_pair(r, f));
			--r;
		}

		r = rank;
		f = file - 1;
		while (f >= 0 && board[r][f]->second != board[rank][file]->second) // squares left
		{
			moves.push_back(std::make_pair(r, f));
			--f;
		}

		f = file + 1;
		while (f >= 0 && board[r][f]->second != board[rank][file]->second) // right
		{
			moves.push_back(std::make_pair(r, f));
			++f;
		}
	}
	case Piece::KING:
	{
		if (rank + 1 < 8 && file + 1 < 8 && board[rank + 1][file + 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank + 1, file + 1));
		if (rank + 1 < 8 && board[rank + 1][file]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank + 1, file));
		if (file + 1 < 8 && board[rank][file + 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank, file + 1));

		if (rank - 1 >= 0 && file - 1 >= 0 && board[rank - 1][file - 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank - 1, file - 1));
		if (rank - 1 >= 0 && board[rank - 1][file]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank - 1, file));
		if (file - 1 >= 0 && board[rank][file - 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank, file - 1));

		if (rank + 1 < 8 && file - 1 >= 0 && board[rank + 1][file - 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank + 1, file - 1));
		if (rank - 1 >= 0 && file + 1 < 8 && board[rank - 1][file + 1]->second != board[rank][file]->second)
			moves.push_back(std::make_pair(rank - 1, file + 1));
	}
	default:
		break;
	
	}

	return moves;
}

void Board::solver()
{

}