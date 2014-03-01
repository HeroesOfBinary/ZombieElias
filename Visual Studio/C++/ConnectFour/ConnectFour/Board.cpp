#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Board{
public:
	Board()
	{
		setWidth(7);
		setLength(6);
	}
	//Board(int width, int length);
//	Board(int width, int length, int numberOfPlayers);
//	Board(int width, int length, int numberOfPlayers, Board Character);
	
	string getBoardSize()
	{
		return "The size of the board is " + 
			static_cast<ostringstream*>(&(ostringstream() << getLength()))->str() + 
			" X " + static_cast<ostringstream*>(&(ostringstream() << getWidth()))->str() + ".\n";
	}
	
	int getLength()
	{
		return length;
	}

	int getWidth()
	{
		return width;
	}

	void placeChip(string playerName)
	{

	}

private:
	double chipRadius;
	string color;
	int length;
	int width;

	void setupBoard()
	{
		
	}

	void addColumn()
	{

	}

	void setLength(int lengthOfBoard)
	{
		if (lengthOfBoard >= 4 )
		{
			length = lengthOfBoard;
		}
		else
		{
			length = 7;
		}
	}
	void setWidth(int widthOfBoard)
	{
		if (widthOfBoard >= 4)
		{
			width = widthOfBoard;
		}
		else
		{
			width = 6;
		}
	}
};