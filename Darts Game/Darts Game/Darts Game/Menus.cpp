#include "Menus.h"
#include <iostream>

Menus::Menus()
{
}

Menus::~Menus()
{
}

void Menus::mainMenu() {
	std::cout << "=========================================================" << std::endl;
	std::cout << "  ___  ___        _         ___  ___                    " << std::endl;
	std::cout << "  |  \\/  |       (_)        |  \\/  |                    " << std::endl;
	std::cout << "  | .  . |  __ _  _  _ __   | .  . |  ___  _ __   _   _ " << std::endl;
	std::cout << "  | |\\/| | / _` || || '_ \\  | |\\/| | / _ \\| '_ \\ | | | |" << std::endl;
	std::cout << "  | |  | || (_| || || | | | | |  | ||  __/| | | || |_| |" << std::endl;
	std::cout << "  \\_|  |_/ \\__,_||_||_| |_| \\_|  |_/ \\___||_| |_| \\__,_|" << std::endl;
	std::cout << "                                                        " << std::endl;
	std::cout << "=========================================================" << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Settings" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "=========================================================" << std::endl;
}

void Menus::playMenu() {
	std::cout << "==========================" << std::endl;
	std::cout << "  ______  _               " << std::endl;
	std::cout << "  | ___ \\| |              " << std::endl;
	std::cout << "  | |_/ /| |  __ _  _   _ " << std::endl;
	std::cout << "  |  __/ | | / _` || | | |" << std::endl;
	std::cout << "  | |    | || (_| || |_| |" << std::endl;
	std::cout << "  \\_|    |_| \\__,_| \\__, |" << std::endl;
	std::cout << "                     __/ |" << std::endl;
	std::cout << "                    |___/ " << std::endl;
	std::cout << "                          " << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "1. Play darts 301" << std::endl;
	std::cout << "2. Play darts 501" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "B. Back" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "==========================" << std::endl;
}

void Menus::settingsMenu(int player, Players* p1, Players* p2) {
	std::cout << "===============================================" << std::endl;
	std::cout << "   _____        _    _    _                    " << std::endl;
	std::cout << "  /  ___|      | |  | |  (_)                   " << std::endl;
	std::cout << "  \\ `--.   ___ | |_ | |_  _  _ __    __ _  ___ " << std::endl;
	std::cout << "   `--. \\ / _ \\| __|| __|| || '_ \\  / _` |/ __|" << std::endl;
	std::cout << "  /\\__/ /|  __/| |_ | |_ | || | | || (_| |\\__ \\" << std::endl;
	std::cout << "  \\____/  \\___| \\__| \\__||_||_| |_| \\__, ||___/" << std::endl;
	std::cout << "                                     __/ |     " << std::endl;
	std::cout << "                                    |___/      " << std::endl;
	std::cout << "                                               " << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "P. Change which player's stats get changed" << std::endl;
	std::cout << "===============================================" << std::endl;
	if (player == 0) {
		std::cout << "|| " << p1->getName() << " ||" << std::endl;
		std::cout << "1. Change innerbull chance: " << p1->getInnerbullChance() << "%" << std::endl;
	}
	else {
		std::cout << "|| " << p2->getName() << " ||" << std::endl;
		std::cout << "1. Change innerbull chance: " << p2->getInnerbullChance() << "%" << std::endl;
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "A. Advanced Settings" << std::endl;
	std::cout << "R. Reset to default" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "B. Back" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "===============================================" << std::endl;
}

void Menus::advSettingsMenu(int player, Players* p1, Players* p2) {
	std::cout << "======================================================" << std::endl;
	std::cout << "    ___       _                                     _ " << std::endl;
	std::cout << "   / _ \\     | |                                   | |" << std::endl;
	std::cout << "  / /_\\ \\  __| |__   __ __ _  _ __    ___  ___   __| |" << std::endl;
	std::cout << "  |  _  | / _` |\\ \\ / // _` || '_ \\  / __|/ _ \\ / _` |" << std::endl;
	std::cout << "  | | | || (_| | \\ V /| (_| || | | || (__|  __/| (_| |" << std::endl;
	std::cout << "  \\_| |_/ \\__,_|  \\_/  \\__,_||_| |_| \\___|\\___| \\__,_|" << std::endl;
	std::cout << "                                               " << std::endl;
	std::cout << "======================================================" << std::endl;
	std::cout << "P. Change which player's stats get changed" << std::endl;
	std::cout << "======================================================" << std::endl;
	if (player == 0) {
		std::cout << "|| " << p1->getName() << " ||" << std::endl;
		std::cout << "1. Change outerbull chance: " << p1->getOuterbullChance() << "%" << std::endl;
		std::cout << "2. Change single chance: " << p1->getHitChance() << "%" << std::endl;
		std::cout << "3. Change double chance: " << p1->getDoubleChance() << "%" << std::endl;
		std::cout << "4. Change treble chance: " << p1->getTrebleChance() << "%" << std::endl;
	}
	else {
		std::cout << "|| " << p2->getName() << " ||" << std::endl;
		std::cout << "1. Change outerbull chance: " << p2->getOuterbullChance() << "%" << std::endl;
		std::cout << "2. Change single chance: " << p2->getHitChance() << "%" << std::endl;
		std::cout << "3. Change double chance: " << p2->getDoubleChance() << "%" << std::endl;
		std::cout << "4. Change treble chance: " << p2->getTrebleChance() << "%" << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "R. Reset to default" << std::endl;
	std::cout << "B. Back" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "======================================================" << std::endl;
}

void Menus::darts301Menu(bool stats, bool percentages) {
	std::cout << "===================================================" << std::endl;
	std::cout << "  ______              _          _____  _____  __  " << std::endl;
	std::cout << "  |  _  \\            | |        |____ ||  _  |/  | " << std::endl;
	std::cout << "  | | | | __ _  _ __ | |_  ___      / /| |/' |`| | " << std::endl;
	std::cout << "  | | | |/ _` || '__|| __|/ __|     \\ \\|  /| | | | " << std::endl;
	std::cout << "  | |/ /| (_| || |   | |_ \\__ \\ .___/ /\\ |_/ /_| |_" << std::endl;
	std::cout << "  |___/  \\__,_||_|    \\__||___/ \\____/  \\___/ \\___/" << std::endl;
	std::cout << "                                                   " << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "1. Run automatic game" << std::endl;
	std::cout << "2. Display throws that players make during automatic game(It slows down simulation): ";
	if (stats == true) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	std::cout << "3. Display after game hit percentages: ";
	if (percentages == true) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "B. Back" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "===================================================" << std::endl;
}

void Menus::darts501Menu(bool stats, bool percentages) {
	std::cout << "===================================================" << std::endl;
	std::cout << "  ______              _          _____  _____  __  " << std::endl;
	std::cout << "  |  _  \\            | |        |  ___||  _  |/  | " << std::endl;
	std::cout << "  | | | | __ _  _ __ | |_  ___  |___ \\ | |/' |`| | " << std::endl;
	std::cout << "  | | | |/ _` || '__|| __|/ __|     \\ \\|  /| | | | " << std::endl;
	std::cout << "  | |/ /| (_| || |   | |_ \\__ \\ /\\__/ /\\ |_/ /_| |_" << std::endl;
	std::cout << "  |___/  \\__,_||_|    \\__||___/ \\____/  \\___/ \\___/" << std::endl;
	std::cout << "                                               " << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "1. Run automatic game" << std::endl;
	std::cout << "2. Play interactive game" << std::endl;
	std::cout << "3. Display throws that players make during automatic game (It slows down simulation): ";
	if (stats == true) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	std::cout << "4. Display after game hit percentages: ";
	if (percentages == true) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "B. Back" << std::endl;
	std::cout << "Q. Quit" << std::endl;
	std::cout << "===================================================" << std::endl;
}