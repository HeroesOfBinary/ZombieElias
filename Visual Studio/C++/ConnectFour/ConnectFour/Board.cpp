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
		setHeight(6);
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

	bool placeChip(int column)
	{
		bool placedChip;
		placedChip = false;

		if (column < getWidth() && column >= 0)
		{
			
		}
	}

	void printBoard()
	{
		for (int header = 1; header < getWidth() + 1 ; header++)
		{
			cout << " " + static_cast<ostringstream*>(&(ostringstream() << header))->str() + " ";
		}

		cout << "\n";

		for (int i = 0; i < getWidth(); i++)
		{
			for (int j = 0; j < getHeight(); j++)
			{
				//if (j == getHeight()-1)
				//{
				//	cout << vec[i][j] + "\n";
				//}
				//else
				//{
					cout << vec[i][j];
				//}
				
			}
			cout << "\n";
		}
	}

private:
	double chipRadius;
	string color;
	int height;
	int width;
	vector< vector<string> > vec;

	void setupBoard()
	{
		for (int i = 0; i < getWidth(); i++)
		{
			vector<string> row;
			for (int j = 0; j < getHeight(); j++)
			{
				row.push_back(" X ");
			}
			vec.push_back(row);
		}
	}

	void setHeight(int heightOfBoard)
	{
		if (heightOfBoard >= 4)
		{
			height = heightOfBoard;
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