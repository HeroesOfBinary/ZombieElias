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

	bool placeChip(int column, string chipType)
	{
		bool placedChip;
		placedChip = false;

		if (column < getWidth() && column >= 0)
		{
			for (int i = getHeight() - 1; i >= 0; i--)
			{
				cout << boardCharacter;
				//cout << vec[column][i];
				//cout << vec[i][column] + "  " + static_cast<ostringstream*>(&(ostringstream() << i))->str() + "  " + static_cast<ostringstream*>(&(ostringstream() << column))->str() + chipType + "\n";
				if ((vec[i][column] == boardCharacter) && (placedChip = false))
				{

					placedChip = true;
					vec.at(i).at(column) = " " + chipType + " ";
				}
			}
		}
		
		//cout << placedChip;
		if (placedChip = true)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

	void printBoard()
	{
		for (int header = 1; header < getWidth() + 1; header++)
		{
			cout << " " + static_cast<ostringstream*>(&(ostringstream() << header))->str() + " ";
		}

		cout << "\n";

		for (int i = 0; i < getHeight(); i++)
		{
			for (int j = 0; j < getWidth(); j++)
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

		cout << "\n";
	}

private:
	double chipRadius;
	string color;
	int height;
	int width;
	string boardCharacter = " X ";
	vector< vector<string> > vec;

	void setupBoard()
	{
		//Vector Is [ROW][COLUMN]
		for (int i = 0; i < getHeight(); i++)
		{
			vector<string> row;
			for (int j = 0; j < getWidth(); j++)
			{
				row.push_back(boardCharacter);
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