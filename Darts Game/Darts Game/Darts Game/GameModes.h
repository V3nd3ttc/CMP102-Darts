#pragma once

#include "Players.h"

class GameModes
{
private:
	//Variable declarations
	int choice = 1;
	int numberOfGames = 0;
	bool play = true;
	int setsWonArray[2][7] = {};
	float setsWonTotal[2][7] = {};

public:
	GameModes();
	~GameModes();

	//Gamemode functions
	void darts301(Players*, Players*);
	void darts501(Players*, Players*);
	void interactiveDarts501(Players* player);
};

