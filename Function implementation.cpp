#include <iostream>
#include "Header.h"

using namespace std;

Piece::Piece(){colour='U';type='P';}

Piece::Piece(char color1){
		colour=color1;
		type='P';
	}

bool bishop_rook_move(bool bishop,bool rook,int a_current, int b_current,int a, int b, Piece* board[][8]){
	bool possible_move=true;
	bool obstruction=false;
	int x_direction=a-a_current;
	int y_direction=b-b_current;
	if (x_direction==0 && y_direction==0)
		return false;
	if (rook==true){
		if (x_direction==0){
			if (y_direction>0)
				for (int temp=b_current+1;temp<b;temp++){
					if (board[a_current][temp]!=nullptr)
						obstruction=true;
				}
			else{
				for (int temp=b_current-1;temp>b;temp--){
					if (board[a_current][temp]!=nullptr)
						obstruction=true;}
			}
			if (!obstruction)
				return true;
		}
		else if (y_direction==0){
			if (x_direction>0)
				for (int temp=a_current+1;temp<a;temp++){
					if (board[temp][b_current]!=nullptr)
						obstruction=true;}
			else{
				for (int temp=a_current-1;temp>a;temp--){
					if (board[temp][b_current]!=nullptr)
						obstruction=true;}
			}
			if (!obstruction)
				return true;
		}
		else
			possible_move=false;
	}
	if (bishop==true){
		if (abs(y_direction)==abs(x_direction)){
			if (x_direction>0 && y_direction<0){
				for (int temp=1;temp<x_direction;temp++){
					if (board[temp+a_current][b_current-temp]!=nullptr){
						obstruction=true;}
				}
			}
			else if(x_direction>0 && y_direction>0){
				for (int temp=1;temp<x_direction;temp++){
					if (board[temp+a_current][b_current+temp]!=nullptr){
						obstruction=true;}
				}
			}
			else if(x_direction<0 && y_direction>0){
				for (int temp=1;temp<y_direction;temp++){
					if (board[a_current-temp][b_current+temp]!=nullptr){
							obstruction=true;}
				}
			}
			else{
				for (int temp=1;temp<abs(y_direction);temp++){
					if (board[a_current-temp][b_current-temp]!=nullptr){
						obstruction=true;
					}
				}
			}
			if (!obstruction)
				return true;
		}
		else
			possible_move=false;
	}
if (!possible_move || obstruction)
	return false;
}

char Piece::gettype(){
		return type;}

ostream& operator<<(ostream &os,Piece &rhs){
		os<<rhs.type<<rhs.colour<<" ";
		return os;
	}
bool Piece:: whitecolour(){
		if (colour=='W')
			return true;
		else
			return false;
}

King::King(char color1)
{	
	colour=color1;
	type='K';
}
bool King::move(int a_current, int b_current, int a, int b,Piece* board[][8]){
	bool move=false;
	if (abs(a-a_current)==1 && abs(b-b_current)==1)
		move=true;
	else if (abs(a-a_current)==1 && (b-b_current)==0)
		move=true;
	else if ((a-a_current)==0 && abs(b-b_current)==1)
		move=true;
	return move;
}

Queen::Queen(char color1)
{
	colour=color1;
	type='Q';
}
bool Queen::move(int a_current, int b_current,int a, int b, Piece* board[][8]){
	return bishop_rook_move(1,1,a_current,b_current,a,b,board);
}

Knight::Knight(char color1){
	colour=color1;
	type='N';
}
bool Knight::move(int a_current, int b_current, int a, int b,Piece* board[][8]){
	int x_direction=a-a_current;
	int y_direction=b-b_current;
	if ((abs(x_direction)==2 && abs(y_direction)==1) || ((abs(x_direction)==1 && abs(y_direction)==2)))
		return true;
	else
		return false;
}

Bishop::Bishop(char color1){
	colour=color1;
	type='B';
}
bool Bishop::move(int a_current, int b_current, int a, int b,Piece* board[][8]){
	return bishop_rook_move(1,0,a_current,b_current,a,b,board);}

Rook::Rook(char color1){
	colour=color1;
	type='R';
}
bool Rook::move(int a_current, int b_current,int a, int b, Piece* board[][8]){
	return bishop_rook_move(0,1,a_current,b_current,a,b,board);
}

Pawn::Pawn(char color1)	{	
	colour=color1;
	type='P';
}
bool Pawn::move(int a_current, int b_current, int a, int b,Piece* board[][8]){
	if ((b_current==1 && board[a_current][b_current]->whitecolour()==true)||
		(b_current==6 && board[a_current][b_current]->whitecolour()==false)){
		if((abs(b-b_current)==2 && (a==a_current)))
			if (board[a][b]==nullptr){
				return true;}
	}
	if (((b-b_current)==1 && (abs(a-a_current)==1) && board[a_current][b_current]->whitecolour()==true)
		|| ((b-b_current)==-1 && (abs(a-a_current)==1) && board[a_current][b_current]->whitecolour()==false )){
		if (board[a][b]!=nullptr){
			return true;}
	}
	else if(((b-b_current)==1 && (a==a_current) && board[a_current][b_current]->whitecolour()==true)
		|| ((b-b_current)==-1 && (a==a_current) && board[a_current][b_current]->whitecolour()==false))
		if (board[a][b]==nullptr){
			return true;
		}
	return false;
}

Board::Board():KW('W'),KB('B'),QW('W'),QB('B'),BW1('W'),BW2('W'),BB1('B'),BB2('B'),RW1('W'),RW2('W'),RB1('B'),RB2('B'),NW1('W'),NW2('W'),NB1('B'),NB2('B'),
		PW0('W'),PW1('W'),PW2('W'),PW3('W'),PW4('W'),PW5('W'),PW6('W'),PW7('W'),
		PB0('B'),PB1('B'),PB2('B'),PB3('B'),PB4('B'),PB5('B'),PB6('B'),PB7('B'){
for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
		board[i][j]=nullptr;
board[0][0]=&RW1;board[1][0]=&NW1;board[2][0]=&BW1;board[3][0]=&QW;board[4][0]=&KW;board[5][0]=&BW2;board[6][0]=&NW2;board[7][0]=&RW2;
board[0][1]=&PW0;board[1][1]=&PW1;board[2][1]=&PW2;board[3][1]=&PW3;board[4][1]=&PW4;board[5][1]=&PW5;board[6][1]=&PW6;board[7][1]=&PW7;
board[0][6]=&PB0;board[1][6]=&PB1;board[2][6]=&PB2;board[3][6]=&PB3;board[4][6]=&PB4;board[5][6]=&PB5;board[6][6]=&PB6;board[7][6]=&PB7;
board[0][7]=&RB1;board[1][7]=&NB1;board[2][7]=&BB1;board[3][7]=&QB;board[4][7]=&KB;board[5][7]=&BB2;board[6][7]=&NB2;board[7][7]=&RB2;
}

void Board::showBoard()
{
	cout<<endl;
	for (int x=7;x>=0;x--){
	cout<<" ____ ____ ____ ____ ____ ____ ____ ____ "<<endl;
		for (int y=0;y<8;y++){
			if (board[y][x]!=nullptr)
				cout<<"| "<<*(board[y][x]);
			else
				cout<<"|    ";
		}
		cout<<"| "<<x+1<<endl;
	}
	cout<<" ____ ____ ____ ____ ____ ____ ____ ____ "<<endl<<endl;
	cout<<"  "<<'a'<<"    "<<'b'<<"    "<<'c'<<"    "<<'d'<<"    "<<'e'<<"    "<<'f'<<"    "<<'g'<<"    "<<'h'<<endl<<endl;
}

bool Board::makeamove(int a_current, int b_current, int a, int b, Piece * board[][8], bool &Player, bool &Check){
	bool possible_move;
	bool move=false;
	bool white_player=board[a_current][b_current]->whitecolour();
	Piece * temp=nullptr;
	if (white_player==Player){
		possible_move=board[a_current][b_current]->move(a_current,b_current,a,b,board);
		if (possible_move){
			if (board[a][b]!=nullptr && (board[a][b]->whitecolour()==white_player)){
				cout<<endl<<"Invalid move. You cannot take your own piece"<<endl<<endl;
				return false;
			}
			if (board[a][b]!=nullptr && (board[a][b]->whitecolour()!=white_player)){
					temp=board[a][b];
					board[a][b]=nullptr;
					board[a][b]=board[a_current][b_current];
					board[a_current][b_current]=nullptr;
					Player=!Player;
					move=true;
			}
			else{
					board[a][b]=board[a_current][b_current];
					board[a_current][b_current]=nullptr;
					Player=!Player;
					move=true;
			}
			if (move && check_Check(!Player,board)==true){
				board[a_current][b_current]=board[a][b];
				board[a][b]=temp;
				Player=!Player;
				move=false;
				if (Check)
					cout<<endl<<"This move is not allowed as it puts your king in check"<<endl;
				return false;
			}
			else if (move){
				if(check_Check(Player,board))
					Check=true;
				else
					Check=false;
				return true;
			}
		}
		else{
			cout<<endl<<"This piece is not allowed to move like this"<<endl;
			return false;}
	}
	else{
		cout<<endl<<"It is not ";
		if (white_player==1)
			cout<<"White ";
		else
			cout<<"Black ";
		cout<<"Players move"<<endl;
	}
}

void Board:: input(int &x,int &y,int &c,int &d){
	char a[25];
	bool repeat=true;
	while (repeat){
	cout<<endl<<"Please select a square to move the piece: ";
	cin>>a;
	x=a[0]-'a';
	y=a[1]-'1';
	if ((x<8 && x>=0) && (y<8 && y>=0)){
		if (board[x][y]!=nullptr){
			cout<<endl<<"Please select a square to move the piece to: ";
			cin>>a;
			c=a[0]-'a';
			d=a[1]-'1';
			repeat=false;
			if ((c>7 || c<0) || (d>7 || d<0)){
				cout<<endl<<"No such position on this board exists. Please enter a letter from (a-h) and a number from (1-8) for example a2."<<endl;
				a[0]='\0';
				repeat=true;
			}
		}
		else{
			cout<<"Please select a piece to move ";
			}
		}
	else{
		cout<<endl<<"No such position on this board exists. Please enter a letter from (a-h) and a number from (1-8) for example a2."<<endl;
		a[0]='\0';
		}
	}
}
bool Board:: check_Check(bool Player, Piece * board[][8]){
	int a_current;
	int b_current;
	bool Check=false;
	for (int x=0;x<8;x++)
		for (int y=0;y<8;y++)
			if (board[x][y]!=nullptr)
				if (board[x][y]->gettype()=='K' && (board[x][y]->whitecolour()==Player)){

				a_current=x;
				b_current=y;
				}
	for (int x=0;x<8;x++)
		for (int y=0;y<8;y++)
			if (board[x][y]!=nullptr)
				if (board[x][y]->whitecolour()!=Player){
					if (board[x][y]->move(x,y,a_current,b_current,board)==true){
						Check=true;
					}
				}
	return Check;
}