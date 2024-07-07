/* BC200403287.
  Abdul Rehman. */

// Start to code TicTacToe Game.
#include<iostream>
#include<conio.h>

using namespace std;

// creating TicTacToe class.
class TicTacToe{
	 private:
	  char board[3][3];
	  char player; int a,b; bool draw;
	
	public:
	  TicTacToe(){
		for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
		 board[i][j] = 0;
		 player = 'c';
		 draw = false;
		}

// Creating a board / pattern to display.	
void printBoard()
		{
		 cout<<"_____ TicTacToe Solving Game _____\n\n";
		 cout<<"\t    0     1     2\n\n";
		 cout<<"\t       |     |     \n\t0   "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n\t       |     |     \n";
		 cout<<"\t  _____|_____|_____\n";
		 cout<<"\t       |     |     \n\t1  "<<board[1][0]<<"   |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n\t       |     |     \n";
		 cout<<"\t  _____|_____|_____\n";
		 cout<<"\t       |     |     \n\t2   "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n\t       |     |     \n";
		}

// Creating game function to declare rules of the game.	
bool game(){
	for(int i=0;i<3;i++)
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0 || board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
			return false;
		
		if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0  || board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
			return false;
	
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
		if(board[i][j] != 'X' && board[i][j] != 'O')
			return true;
			draw = true;
			return false;
		}

// Creating makeMove function for inputs of the game.
void makeMove(){
		if(player == 'c'){
			cout<<"\n___Player X enter move: ";
			cout<<endl;
			cin>>a;
			cin>>b;
			}
		else{
			 cout<<"\n___Player O enter move: ";
			 cout<<endl;
			 cin>>a;
			 cin>>b;
			}
		
		  validMove();
		}

// Creating validMove function.
void validMove(){
		if(player == 'c' && board[a][b] != 'X' && board[a][b] != 'O'){
			board[a][b] = 'X';
			player = 'd';
			}
   else if(player == 'd' && board[a][b] != 'X' && board[a][b] != 'O'){
			board[a][b] = 'O';
			player = 'c';
			}
		else{
			  cout<<"\n\n___Filled, please try again \n";
			
			}
		}

// Creating gameStatus function to check and display the result.	
void gameStatus(){
		if(player == 'c' && draw == false)
			cout<<"\n\n___Player O is winner___";
		
		else if(player == 'd' && draw == false)
			cout<<"\n\n___Player X is winner___";
		
		else
			cout<<"\n\n___Game is draw___";
		}
};

// Starting main function.
main(){
	TicTacToe obj;
	while(obj.game()){
	  obj.printBoard();
	  obj.makeMove();	
	}
	  obj.gameStatus();
	
	return 0;
}

// Completed the TicTacToe game.
