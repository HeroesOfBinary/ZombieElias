#include <iostream>
#include <string>
#include <sstream>
#include "Board.cpp"
#include "Player.cpp"

using namespace std;

int main()
{
	string player1Name, player2Name, player1Character, player2Character;
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
	

	do
	{
		cout << "What will be " + player1Name + "'s identifying character? \n";
		cin >> player1Character;
	} while (player1Character == "" || player1Character.length() != 1);
	Player playerOne = Player(player1Name, player1Character);


	/*
	Get Player Two Information
	*/
	do
	{
		cout << "What is Player Two's Name? \n";
		cin >> player2Name;
	} while (player2Name == "");

	do
	{
		cout << "What will be " + player2Name + "'s identifying character? \n";
		cin >> player2Character;
	} while (player2Character == "" || player2Character.length() != 1);
	Player playerTwo = Player(player2Name, player2Character);

	cout << myGame.getBoardSize();

	myGame.printBoard();


	myGame.placeChip(5, playerOne.getPlayerCharacter());

	myGame.printBoard();

	do 	{
		
	} while (gameOver = 0);
	
}

