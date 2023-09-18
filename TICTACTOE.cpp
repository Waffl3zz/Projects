#include <iostream>
#include <string>
using namespace std;

void setup(string grid[3][3]);
void display(string grid[3][3]);
bool validmove(string grid[3][3], int row, int col, bool player1);
bool checkwinner(string grid[3][3], bool player1);
void tictactoe();

int x = 0;

int main()
{
while(x<9){


tictactoe();
if(x=9){
    cout<<"No Winner"<<endl<<"Press ENTER to continue ";
    cin.ignore();
	cin.get();
	system("clear");

}
x=0;
}

return 0;
}

void tictactoe()
{
	string grid[3][3];
	bool player1 = true;
	bool winner = false;
	bool valid = false;
	int choice;

	setup(grid);


	while( winner == false && x < 9)
	{
		display(grid);
		if( player1 == true )
			cout << "Player 1 please enter a position: ";
		else
			cout << "Player 2 please enter a position: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				valid = validmove(grid,0,0,player1);
				break;
			case 2:
				valid = validmove(grid,0,1,player1);
				break;
			case 3:
				valid = validmove(grid,0,2,player1);
				break;
			case 4:
				valid = validmove(grid,1,0,player1);
				break;
			case 5:
				valid = validmove(grid,1,1,player1);
				break;
			case 6:
				valid = validmove(grid,1,2,player1);
				break;
			case 7:
				valid = validmove(grid,2,0,player1);
				break;
			case 8:
				valid = validmove(grid,2,1,player1);
				break;
			case 9:
				valid = validmove(grid,2,2,player1);
				break;
			default:
				cout << "Please enter number 1-9. " << endl;
				cin.get();
				break;
		}

		x++;

		if( valid == true )
		{
			winner = checkwinner(grid,player1);
			if( winner == true )
			{
				display(grid);
				string player = player1 ? "PLAYER 1" : "PLAYER 2";
				cout << player << " wins!!!!" << endl;
			}
			else
			{
				player1 = !player1;
			}
		}
		else
		{
			cout << "Enter a different position." << endl;
			cin.get(); cin.get();
		}



	}//game loop
}
void setup(string grid[3][3])
{
	int counter = 1;
	for( int row = 0; row < 3; row++ )
	{
		for( int col = 0; col < 3; col++ )
		{
			grid[row][col] = to_string( counter );
			counter++;
		}
	}
}
void display(string grid[3][3])
{
	system("CLS");
	for( int row = 0; row < 3; row++ )
	{
		cout << " | ";
		for( int col = 0; col < 3; col++ )
		{
			cout << grid[row][col] << " | ";
		}
		cout << endl;
	}
}
bool validmove(string grid[3][3], int row, int col, bool player1)
{
	string place = player1 ? "X" : "O";
	bool valid = false;
	if( grid[row][col] != "X" && grid[row][col] != "O" )
	{
		grid[row][col] = place;
		valid = true;
	}
	return valid;
}
bool checkwinner(string grid[3][3], bool player1)
{
	string place = player1 ? "X" : "O";
	bool winner = false;

	//rows
	if( grid[0][0] == place && grid[0][1] == place && grid[0][2] == place )
		winner = true;
	if( grid[1][0] == place && grid[1][1] == place && grid[1][2] == place )
		winner = true;
	if( grid[2][0] == place && grid[2][1] == place && grid[2][2] == place )
		winner = true;
	//columns
	if( grid[0][0] == place && grid[1][0] == place && grid[2][0] == place )
		winner = true;
	if( grid[0][1] == place && grid[1][1] == place && grid[2][1] == place )
		winner = true;
	if( grid[0][2] == place && grid[1][2] == place && grid[2][2] == place )
		winner = true;
	//diagonals
	if( grid[0][0] == place && grid[1][1] == place && grid[2][2] == place )
		winner = true;
	if( grid[0][2] == place && grid[1][1] == place && grid[2][0] == place )
		winner = true;

	return winner;
}
