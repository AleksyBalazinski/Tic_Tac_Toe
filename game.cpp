#include <iostream>
#include <stdlib.h>     //srand, rand, system (for example system("cls"))
#include <time.h>       //time
#include <windows.h>    //Sleep
using namespace std;

void cls(char t[][4])
{
	for (int y = 1; y < 4; y++)
	{
		for (int x = 1; x < 4; x++)
		{
			t[y][x] = ' ';
		}
	}
}
void prtarr(char t[][4])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			cout << t[y][x];
		}
		cout << "\n";
	}
}
void bot_rd(char t[][4]) //possibly the stupidest one in the universe
{
	srand(time(NULL));
	int x_rand = 1;
	int y_rand = 1;
	while(t[y_rand][x_rand] != ' ')
	{
		x_rand = rand() % 3 + 1;
		y_rand = rand() % 3 + 1;
	}
	t[y_rand][x_rand] = 'o';
}
int check_col(char t[][4], int col)
{
	int col_v = 0;
	if (t[1][col] == 'x' && t[2][col] == 'x' && t[3][col] == 'x')
	{
		col_v = 1; //player wins
	}
	if (t[1][col] == 'o' && t[2][col] == 'o' && t[3][col] == 'o')
	{
		col_v = 2; //computer wins
	}
	return col_v;
}
int chceck_row(char t[][4], int row)
{
	int row_v = 0;
	if (t[row][1] == 'x' && t[row][2] == 'x' && t[row][3] == 'x')
	{
		row_v = 1; //player wins
	}
	if (t[row][1] == 'o' && t[row][2] == 'o' && t[row][3] == 'o')
	{
		row_v = 2; //computer wins
	}
	return row_v;
}
int diagonal_check(char t[][4])
{
	int diag_v = 0;
	if ((t[1][1] == 'x' && t[2][2] == 'x' && t[3][3] == 'x')
		|| (t[1][3] == 'x' && t[2][2] == 'x' && t[3][1] == 'x'))
	{
		diag_v = 1; //player wins
	}
	if ((t[1][1] == 'o' && t[2][2] == 'o' && t[3][3] == 'o')
		|| (t[1][3] == 'o' && t[2][2] == 'o' && t[3][1] == 'o'))
	{
		diag_v = 2; //computer wins
	}
	return diag_v;
}
int game_status(char t[][4])
{
	int win   = 0;
	if ((check_col(t, 1) == 1 || check_col(t, 2) == 1 || check_col(t, 3) == 1)
		|| (chceck_row(t, 1) == 1 || chceck_row(t, 2) == 1 || chceck_row(t, 3) == 1)
		|| diagonal_check(t)==1)
	{
		win = 1; //player wins 
	}
	if ((check_col(t, 1) == 2 || check_col(t, 2) == 2 || check_col(t, 3) == 2)
		|| (chceck_row(t, 1) == 2 || chceck_row(t, 2) == 2 || chceck_row(t, 3) == 2)
		|| diagonal_check(t)==2)
	{
		win = 2; //computer wins
	}
	return win;
}
int pos_l_to_pos(char pos)
{
	int pos_int = 0; //default value
	if (pos == 'a') pos_int = 1;
	if (pos == 'b') pos_int = 2;
	if (pos == 'c') pos_int = 3;
	return pos_int;
}

int main()
{
	//creating gameboard
	char gameboard[4][4];
	gameboard[0][0] = '*';
	gameboard[0][1] = '1';
	gameboard[0][2] = '2';
	gameboard[0][3] = '3';
	gameboard[1][0] = 'a';
	gameboard[2][0] = 'b';
	gameboard[3][0] = 'c';
	//initialize it with random stuff
	for (int y = 1; y < 4; y++)
	{
		for (int x = 1; x < 4; x++)
		{
			gameboard[y][x] = '?';
		}
	}
	cout << "*****Welcome to Tic-Tac-Toe!*****\n";
	cout << "Your turn is to place 'x' symbols and beat the computer!\n";
	Sleep(5000); // for cool effects sake
	cout << "Loading...";
	Sleep(2000);
	system("cls");
	cout << "This is the game board you'll be playing on\n";
	cout << "Gameboard filled with ? symbols\n";
	prtarr(gameboard); //print it
	cls(gameboard); //we have to fill it with spaces
	char y_pos_l;
	int x_pos, y_pos;
	//the proper game-servicing loop
	Sleep(2000);
	system("cls");
	do 
	{
		prtarr(gameboard);
		cout << "\n\nEnter x coordinate (numeral)\n";
		cin >> x_pos;
		cout << "Enter y coordinate (lower-case letter)\n";
		cin >> y_pos_l;
		y_pos = pos_l_to_pos(y_pos_l);
		gameboard[y_pos][x_pos] = 'x';
		if (game_status(gameboard) == 1)
		{
			cout << "Congratulations, you win!";
			break;
		}
		cout << "\nMy move...\n";
		Sleep(2000); 
		bot_rd(gameboard);
		system("cls");
		if (game_status(gameboard) == 2)
		{
			cout << "Unfortunately, this time I won!";
			break;
		}
	} while (game_status(gameboard) == 0);

}
