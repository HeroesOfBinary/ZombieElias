#include <iostream>
#include <string>
#include <sstream>
#include "Board.cpp"
#include "Player.cpp"
#include "SDL.h" 

using namespace std;

int getInt()
{
	int x = 0;
	while (!( cin >> x))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Please input a proper 'whole' number: " << endl;
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return (x);
}

//int main(int argc, char *argv[])
int testStuff()
{
	string playerName, playerCharacter;
	Board myGame;
	bool gameOver, turnIsOver;
	int column, counter, numberOfPlayers;
	vector< Player > vec;

	//Start SDL 
	SDL_Init(SDL_INIT_EVERYTHING); //Quit SDL 
	SDL_Quit(); return 0;

	gameOver = false;
	turnIsOver = false;
	cout << "Welcome To Connect Four! \n";
	
	do
	{
		//do
		//{
			cout << "How many players are there? \n";
			numberOfPlayers = getInt();
		//} while (isdigit(numberOfPlayers) == false);
	} while (numberOfPlayers < 2);

	for (int i = 1; i <= numberOfPlayers; i++)
	{
		do
		{
			cout << "What is Player " + static_cast<ostringstream*>(&(ostringstream() << i))->str() + "'s Name? \n";
			getline(cin, playerName);
		} while (playerName == "");

		do
		{
			cout << "What will be " + playerName + "'s identifying character? \n";
			getline(cin, playerCharacter);
		} while (playerCharacter == "" || playerCharacter.length() != 1);
		vec.push_back(Player(playerName, playerCharacter));
		playerName = "";
		playerCharacter = "";
	}
	myGame.printBoard();
	counter = 0;

	do 	{

		if (counter == (numberOfPlayers))
		{
			counter = 0;
		}
		else
		{
			if (gameOver == false)
			{
				do {
					do {				
							cout << "Where will " + vec[counter].getPlayerName() + " place the chip? (1-" + static_cast<ostringstream*>(&(ostringstream() << myGame.getWidth()))->str() + ")\n";
							column = getInt();
					} while (column > myGame.getWidth() || column < 1);
				} while (myGame.placeChip(column, vec[counter].getPlayerCharacter()) == false);
				myGame.printBoard();
				gameOver = myGame.connectFour(vec[counter].getPlayerCharacter());

				if (gameOver == true)
				{
					cout << vec[counter].getPlayerName() + " wins! \n";
				}
			}
			counter = counter + 1;
		}
	} while (gameOver == false);

	/*
	Get Player One Information
	*/
/*	do
	{
		cout << "What is Player One's Name? \n";
		cin >> player1Name;
	} while (player1Name == "");
	


	do
	{
		cout << "What will be " + player1Name + "'s identifying character? \n";
		cin >> player1Character;
	} while (player1Character == "" || player1Character.length() != 1);
	


	/*
	Get Player Two Information
	*/
/*	do
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
*/
	//cout << myGame.getBoardSize();



/*	} while (gameOver == false);

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

			if (gameOver == true)
			{
				cout << playerOne.getPlayerName() + " wins! \n";
			}
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

			if (gameOver == true)
			{
				cout << playerTwo.getPlayerName() + " wins! \n";
			}
		//} while (turnIsOver == false);
		}

	} while (gameOver == false);
	*/
}

