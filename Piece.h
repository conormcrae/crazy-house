#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <utility>

enum class Piece { empty = 0, pawn = 1, knight = 3, bishop = 4, rook = 5, queen = 9, king = INT_MAX };
enum class Color { null = -1, white = 0, black = 1 };

class Board
{
public:
	Board();
	Board(const Board& b);
	Board& operator = (Board copy);
	//~Board();

	void set_score();
	double get_score();
	bool get_move_color();
	void solver();

	friend void swap(Board& left, Board& right);

private:
	std::pair<Piece, Color>*  board[8][8];
	double score;
	bool white2move;
};

#endif
