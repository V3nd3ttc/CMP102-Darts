#include "DartBoard.h"
#include <iostream>
#include <string>

DartBoard::DartBoard()
{
}

DartBoard::~DartBoard()
{
}


int DartBoard::getLeftNeighbour(int target)
{
	return dartboardScores[0][target]; //Returns the left neighbour of target
}

int DartBoard::getRightNeighbour(int target)
{
	return dartboardScores[1][target]; //Returns the right neighbour of target
}