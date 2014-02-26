#include <iostream>
#include <string>
#include <sstream>

class Board{
public:
	Board();
	Board(int width, int length);
	Board(int width, int length, int numberOfPlayers);
	Board(int width, int length, int numberOfPlayers, Board Character);


private:
	double chipRadius;
	std::string color;
};