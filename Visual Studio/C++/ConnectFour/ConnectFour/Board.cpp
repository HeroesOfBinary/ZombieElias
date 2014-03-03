#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Board{
public:
	Board()
	{
		setWidth(7);
		setLength(6);
		setupBoard();
	}
	//Board(int width, int length);
//	Board(int width, int length, int numberOfPlayers);
//	Board(int width, int length, int numberOfPlayers, Board Character);
	
	string getBoardSize()
	{
		return "The size of the board is " + 
			static_cast<ostringstream*>(&(ostringstream() << getHeight()))->str() + 
			" X " + static_cast<ostringstream*>(&(ostringstream() << getWidth()))->str() + ".\n";
	}
	
	int getHeight()
	{
		return height;
	}

	int getWidth()
	{
		return width;
	}

	void placeChip(int column)
	{
		if (column > getWidth() && column >= 0)
		{

		}
	}

private:
	double chipRadius;
	string color;
	int height;
	int width;
	string board;

	void setupBoard()
	{
		board = string(getHeight(), getWidth());
	}

	void setLength(int lengthOfBoard)
	{
		if (lengthOfBoard >= 4 )
		{
			height = lengthOfBoard;
		}
		else
		{
			height = 7;
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