#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class Piece { EMPTY = 0, PAWN = 1, KNIGHT = 3, BISHOP = 4, ROOK = 5, QUEEN = 9, KING = INT_MAX };
enum class Color { BLACK = -1, NO_COLOR = 0, WHITE = 1 };

class Board
{
public:
	Board();
	Board(const Board& b);
	Board& operator = (Board copy);
	~Board();

	double set_score();
	double get_score();
	bool get_move_color();
	void toggle_move_color();
	void move();
	bool in_check();
	bool checkmate();
	void solver(int);
	double w_solver(int);
	double b_solver(int);
	void view();
	std::vector<std::pair<int, int>> possible_moves(int rank, int file);

	friend void swap(Board& left, Board& right);

private:
	std::pair<Piece, Color>*  board[8][8];
	double score;
	bool white2move;
};

#endif
