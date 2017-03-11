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

	board[0][0]->first = Piece::rook;
	board[0][1]->first = Piece::knight;
	board[0][2]->first = Piece::bishop;
	board[0][3]->first = Piece::queen;
	board[0][4]->first = Piece::king;
	board[0][5]->first = Piece::bishop;
	board[0][6]->first = Piece::knight;
	board[0][7]->first = Piece::rook;
	board[0][0]->first = Piece::pawn;
	board[0][1]->first = Piece::pawn;
	board[0][2]->first = Piece::pawn;
	board[0][3]->first = Piece::pawn;
	board[0][4]->first = Piece::pawn;
	board[0][5]->first = Piece::pawn;
	board[0][6]->first = Piece::pawn;
	board[0][7]->first = Piece::pawn;

	board[0][0]->second = Color::white;
	board[0][1]->second = Color::white;
	board[0][2]->second = Color::white;
	board[0][3]->second = Color::white;
	board[0][4]->second = Color::white;
	board[0][5]->second = Color::white;
	board[0][6]->second = Color::white;
	board[0][7]->second = Color::white;
	board[1][0]->second = Color::white;
	board[1][1]->second = Color::white;
	board[1][2]->second = Color::white;
	board[1][3]->second = Color::white;
	board[1][4]->second = Color::white;
	board[1][5]->second = Color::white;
	board[1][6]->second = Color::white;
	board[1][7]->second = Color::white;


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

	board[7][0]->first = Piece::rook;
	board[7][1]->first = Piece::knight;
	board[7][2]->first = Piece::bishop;
	board[7][3]->first = Piece::queen;
	board[7][4]->first = Piece::king;
	board[7][5]->first = Piece::bishop;
	board[7][6]->first = Piece::knight;
	board[7][7]->first = Piece::rook;
	board[6][0]->first = Piece::pawn;
	board[6][1]->first = Piece::pawn;
	board[6][2]->first = Piece::pawn;
	board[6][3]->first = Piece::pawn;
	board[6][4]->first = Piece::pawn;
	board[6][5]->first = Piece::pawn;
	board[6][6]->first = Piece::pawn;
	board[6][7]->first = Piece::pawn;

	board[7][0]->second = Color::black;
	board[7][1]->second = Color::black;
	board[7][2]->second = Color::black;
	board[7][3]->second = Color::black;
	board[7][4]->second = Color::black;
	board[7][5]->second = Color::black;
	board[7][6]->second = Color::black;
	board[7][7]->second = Color::black;
	board[6][0]->second = Color::black;
	board[6][1]->second = Color::black;
	board[6][2]->second = Color::black;
	board[6][3]->second = Color::black;
	board[6][4]->second = Color::black;
	board[6][5]->second = Color::black;
	board[6][6]->second = Color::black;
	board[6][7]->second = Color::black;

}

Board::Board(const Board& b)
{
	white2move = b.white2move;
	score = b.score;
	std::copy(b.board, b.board + 64, board); /*error, see http://forums.codeguru.com/showthread.php?473053-RESOLVED-Trouble-with-std-fill */
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