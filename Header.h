#ifndef HEADER_H
#define HEADER_H

using namespace std;

class Piece{
protected:
	char colour;
	char type;
public:
	bool whitecolour();
	Piece();
	char gettype();
	virtual bool move(int current_cow,int current_column,int row, int col, Piece* board[][8])=0;
	friend ostream& operator<<(ostream &os,Piece &rhs);
	Piece(char color1);
	friend bool bishop_rook_move(bool bishop,bool rook,int a_current, int b_current,int a, int b, Piece* board[][8]);
};

class King : public Piece{
public:
	King(char color1);
	bool move(int a_current, int b_current, int a, int b,Piece* board[][8]);
};

class Queen : public Piece{
public:
	Queen(char color1);
	bool move(int a_current, int b_current,int a, int b, Piece* board[][8]);
};

class Knight : public Piece{
public:
	Knight(char color1);
	bool move(int a_current, int b_current, int a, int b,Piece* board[][8]);
};

class Bishop : public Piece{
public:
	Bishop(char color1);
	bool move(int a_current, int b_current, int a, int b,Piece* board[][8]);
};

class Rook : public Piece{
public:
	Rook(char color1);
	bool move(int a_current, int b_current,int a, int b, Piece* board[][8]);
};

class Pawn : public Piece{
public:
	Pawn(char color1);
	bool move(int a_current, int b_current, int a, int b,Piece* board[][8]);
};
class Board{
	friend class Piece;
private:
	King KW, KB;
	Queen QW, QB;
	Bishop BW1,BW2,BB1,BB2;
	Rook RW1,RW2,RB1,RB2;
	Knight NW1,NW2,NB1,NB2;
	Pawn PW0,PW1,PW2,PW3,PW4,PW5,PW6,PW7;
	Pawn PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7;
public:
	Piece * board[8][8];
	Board();
	void showBoard();
	bool makeamove(int a_current, int b_current, int a, int b, Piece * board[][8], bool &Player, bool &Check);
	void input(int &x,int &y,int &c,int &d);
	bool check_Check(bool Player, Piece * board[][8]);
};
#endif