#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <utility>

enum class Piece { pawn = 1, knight = 3, bishop = 3, rook = 5, queen = 9, king = INT_MAX };
enum class Color { null = -1, white = 0, black = 1 };

class Board
{
public:
	Board();
	Board(const Board& b);
	Board& operator = (Board copy);
	//~Board();

	friend void swap(Board& left, Board& right);

private:
	std::pair<Piece, Color>*  board[8][8];
	double score;
	bool white2move;
};

#endif
