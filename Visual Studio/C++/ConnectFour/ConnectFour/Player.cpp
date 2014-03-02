#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Player{
public:
	Player(string playerName, string playerCharacter)
	{
		setPlayerName(playerName);
		setPlayerCharacter(playerCharacter);
	}
	
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
		if (newCharacter != "" && newCharacter.length() == 0)
		{
			playerCharacter = newCharacter;
		}
	}

	string getPlayerCharacter()
	{
		return playerCharacter;
	}

private:
	string playerName;
	string playerCharacter;
};