#include <iostream>
#include <string>
#include <sstream>
#include "Board.cpp"

using namespace std;
const string  boardCharacter = "@";


int main()
{
	string player1Name, player2Name;
	Board myGame;
	int gameOver;
	gameOver = 0;
	cout << "Connect Four! \n";

	/*
	Get Player One Information
	*/
	do
	{
		cout << "What is Player One's Name? \n";
		cin >> player1Name;
	} while (player1Name == "");
	myGame.setPlayerTwo(player1Name);


	/*
	Get Player Two Information
	*/
	do
	{
		cout << "What is Player Two's Name? \n";
		cin >> player2Name;
	} while (player2Name == "");
	myGame.setPlayerTwo(player1Name);
	cout << myGame.getBoardSize();


	do 	{
		
	} while (gameOver = 0);
	
}

