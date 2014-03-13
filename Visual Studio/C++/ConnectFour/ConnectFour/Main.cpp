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
	bool gameOver, turnIsOver;
	int column;
	gameOver = false;
	turnIsOver = false;
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

	//cout << myGame.getBoardSize();

	myGame.printBoard();
	
	do 	{
		
		//RESET COLUMN SELECTION
		column = 0;
		//Player One;
		if (gameOver == false)
		{
			do {
				do {
					cout << "Where will " + playerOne.getPlayerName() + " place the chip? (1-" + static_cast<ostringstream*>(&(ostringstream() << myGame.getWidth()))->str() + ")\n";
					cin >> column;

				} while (column > myGame.getWidth() || column < 1);
			} while (myGame.placeChip(column, playerOne.getPlayerCharacter()) == false);
			myGame.printBoard();
		gameOver=myGame.connectFour(playerOne.getPlayerCharacter());
		}

		//RESET COLUMN SELECTION
		column = 0;

		//Player Two;
		if (gameOver == false)
		{
			do {
				do {
					cout << "Where will " + playerTwo.getPlayerName() + " place the chip? (1-" + static_cast<ostringstream*>(&(ostringstream() << myGame.getWidth()))->str() + ")\n";
					cin >> column;
				} while (column > myGame.getWidth() && column < 1);
			} while (myGame.placeChip(column, playerTwo.getPlayerCharacter()) == false);		
			myGame.printBoard();
		gameOver = myGame.connectFour(playerTwo.getPlayerCharacter());
		//} while (turnIsOver == false);
		}


	} while (gameOver == false);
	
}

