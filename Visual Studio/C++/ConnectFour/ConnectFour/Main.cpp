#include <iostream>
#include <string>
#include <sstream>
#include "Board.cpp"
#include "Player.cpp"

using namespace std;

int main()
{
	string player1Name, player2Name;
	Board myGame;
	Player playerOne = Player("PlayerOne", "1");
	Player playerTwo= Player("PlayerTwo", "2");
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
	playerOne.setPlayerName(player1Name);


	/*
	Get Player Two Information
	*/
	do
	{
		cout << "What is Player Two's Name? \n";
		cin >> player2Name;
	} while (player2Name == "");
	playerOne.setPlayerName(player1Name);

	cout << myGame.getBoardSize();

	myGame.printBoard();

	myGame.placeChip(5, playerOne.getPlayerCharacter());

	myGame.printBoard();

	do 	{
		
	} while (gameOver = 0);
	
}

