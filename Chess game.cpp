#include <iostream>
#include "Header.h"

using namespace std;

int main(){
	Board newgame;
	bool Player=1;
	bool Check=false;
	int x=0,y=0,a=0,b=0;
	newgame.showBoard();
	while (1){
		if (Check==true)
			cout<<endl<<"Check!"<<endl<<"Please play a move to prevent the check"<<endl;
		cout<<endl<<"It is ";
		if (Player==1)
			cout<<"White ";
		else
			cout<<"Black ";
		cout<<"Player's move"<<endl;
		newgame.input(x,y,a,b);
		if (newgame.makeamove(x,y,a,b,newgame.board,Player,Check)==false)
			cout<<endl<<"Please enter your move again"<<endl;
	newgame.showBoard();
	}
	return 0;
}