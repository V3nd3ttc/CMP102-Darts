#pragma once

class DartBoard
{
private:
	//array with the possible score on the dartboard
	static constexpr int dartboardScores[2][21] =
	{
		{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5}, //Row 1 left neighbour
		{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} //Row 2 right neighbour
	};
public:
	DartBoard();
	~DartBoard();

	//static void getLeftNeighbour(int, int&); //OLD SYSTEM
	//static void getRightNeighbour(int, int&); //OLD SYSTEM

	static int getLeftNeighbour(int);
	static int getRightNeighbour(int);

};