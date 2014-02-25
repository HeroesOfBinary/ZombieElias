#include <iostream>
#include <string>
#include <sstream>

using namespace std;
const string  boardCharacter = "@";

struct ConnectRows 
{	
	string cell[7];
} row1, row2, row3, row4, row5, row6, row7;

void printBoardRow(ConnectRows row);

void printGameBoard()
{
	string EdgeOfBoard;
	EdgeOfBoard = boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + boardCharacter + "/n";
	//Print Header
	cout << EdgeOfBoard;
	printBoardRow(row1);
	printBoardRow(row2);
	printBoardRow(row3);
	printBoardRow(row4);
	printBoardRow(row5);
	printBoardRow(row6);
	printBoardRow(row7);
	//Primt Footer
	cout << EdgeOfBoard;
}

void printBoardRow(ConnectRows row)
{
	cout << boardCharacter + row.cell[0] + boardCharacter + row.cell[1] + boardCharacter + row.cell[2] + boardCharacter + row.cell[3] + boardCharacter + row.cell[4] + boardCharacter + row.cell[5] + boardCharacter + row.cell[6] + boardCharacter + "\n";
}

int main()
{
	string player1Name, player2Name;
	int gameOver;

	gameOver = 0;
	cout << "Connect Four! \n";

	cout << "What is Player One's Name?";
	cin >> player1Name;
	cout << "What is Player Two's Name?";
	cin >> player2Name;

	do 	{
		printGameBoard();
	} while (gameOver = 0);
	
}

