#include<bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,column;
bool draw = false;
void display_board()
{
	int choice;
	system("cls");
	cout<<"\n\n   Tick Cross Game"<<endl;
	cout<<"\tPlayer1 [X] \n\tPlayer2 [O]\n\n";
	cout<<"\t\t    |    |    \n";
	cout<<"\t\t "<<board[0][0]<<"  |  "<<board[0][1]<<" |   "<<board[0][2]<<" \n";    
	cout<<"\t\t____|____|____\n";
	cout<<"\t\t    |    |    \n";
	cout<<"\t\t "<<board[1][0]<<"  |  "<<board[1][1]<<" |  "<<board[1][2]<<" \n";    
	cout<<"\t\t____|____|____\n";
	cout<<"\t\t    |    |    \n";
	cout<<"\t\t "<<board[2][0]<<"  |  "<<board[2][1]<<" | "<<board[2][2]<<" \n";    
	cout<<"\t\t____|____|____\n";
	cout<<"\t\t    |    |    \n";
	cout<<"\t\t    |    |    \n";
	

}
void player_turn()
{
	int choice;
	if(turn =='X')
	{
		cout<<"\n\tPlayer1 [X] turns ";
	}
	else
	{
		if(turn =='O')
		{
			cout<<"\n\tPlayer2 [O] turns ";
		}
	
	}
	cin>>choice;
	switch(choice)
	{
		case 1: row =0;column =0;break;
		case 2: row =0;column =1;break;
		case 3: row =0;column =2;break;
		case 4: row =1;column =0;break;
		case 5: row =1;column =1;break;
		case 6: row =1;column =2;break;
		case 7: row =2;column =0;break;
		case 8: row =2;column =1;break;
		case 9: row =2;column =2;break;
		
		default:
			cout<<"Invalid Choice\n";
			break;
	}
	
	if(turn == 'X' && board[row][column]!='X' && board[row][column]!='O')
	{
		board[row][column] = 'X';
		turn = 'O';
	}
	else
	{
		if(turn=='O' && board[row][column]!='X' && board[row][column]!='O')
		{
			board[row][column] = 'O';
			turn = 'X';
		}
		else
		{
			cout<<"Box already filled\n Please Try again\n";
			player_turn();
		}
	}
	display_board();
	
	
}
bool game_over()
{
	//For wining row wise,column wise,diagonal wise
	for(int i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
		{
			return false;
		}
		if(board[0][0]==board[1][1] && board[0][0] == board[2][2])
		{
			return false;
		}
		if(board[0][2]==board[1][1] && board[0][2] == board[2][0])
		{
			return false;
		}
	}
	
	//for checking any box unfilled
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X' && board[i][j]!='O')
			{
				return true;
			}
		}
	}
// if game draw	
draw = true;
	return false;
}

main()
{
	while(game_over())
	{
		display_board();
		player_turn();
		display_board();
		
	}
	if(turn =='X' && draw ==false)
	{
		cout<<"Player2 [O] wins! Congo\n";
	}
	else
	{
		if(turn=='O' && draw == false)
		{
			cout<<"Player1 [X] wins! Congo\n";
		}
		else
		{
			cout<<"Draw";
		}
	}
}
