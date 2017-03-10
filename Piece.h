#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece
{
public:
	Piece();
	Piece(std::string name, double val);
	void toggle_color();
	std::string get_lettter();

private:
	bool is_white;
	std::string letter;
	double value;
};

class Empty : public Piece
{

};

class Pawn : public Piece
{

public:
	Pawn();
};

class Bishop : public Piece
{

public:
	Bishop();
};

class Knight : public Piece
{

public:
	Knight();
};

class Rook : public Piece
{

public:
	Rook();
};

class Queen : public Piece
{

public:
	Queen();

};

class King : public Piece
{

public:
	King();
};

class Board
{
public:
	Board();
	Board(const Board& b);
	Board& operator = (Board copy);
	//~Board();

	friend void swap(Board& left, Board& right);

private:
	Piece* board[8][8];
	double score;
	bool white2move;
};

#endif
