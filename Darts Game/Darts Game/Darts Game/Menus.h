#pragma once
#include "Players.h"

class Menus
{
private:

public:

	Menus();
	~Menus();

	static void mainMenu();
	static void playMenu();
	static void settingsMenu(int, Players*, Players*);
	static void advSettingsMenu(int, Players*, Players*);
	static void darts301Menu(bool, bool);
	static void darts501Menu(bool, bool);
};

