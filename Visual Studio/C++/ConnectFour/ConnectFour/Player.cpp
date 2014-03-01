#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Player{
public:
	Player(string playerName)
	{
		setPlayerName(playerName);
	}
	
	/*
	=======================================
	PLAYER SETTINGS:
	=======================================
	*/
	void setPlayerName(string newName)
	{
		if (newName != "")
		{
			playerName = newName;
		}
	}

	string getPlayerName()
	{
		return playerName;
	}


	void setPlayerCharacter(string newCharacter)
	{
		if (newCharacter != "" && newCharacter.length = 1)
		{
			playerName = newCharacter;
		}
	}

	string getPlayerName()
	{
		return playerName;
	}


private:
	string playerName;
	string playerCharacter;


}