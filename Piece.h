#ifndef PIECE_H
#define PIECE_H

#include <string>

class piece
{
public:
	void toggle_color();
	std::string get_lettter();

private:
	bool is_white;
	std::string letter;
	double value;
};

class empty : public piece
{

};

class pawn : public piece
{

};

class bishop : public piece
{

};

class knight : public piece
{

};

class rook : public piece
{

};

class queen : public piece
{

};

class king : public piece
{

};

class square
{
public:


private:
	piece* piece;
	int rank;
	int file;
};


class board
{
public:


private:
	square array[8][8];
	double score;
	bool white2move;
};

#endif
