#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <conio.h> //Used for input without enter

#include "Players.h"
#include "GameModes.h"
#include "Menus.h"


//Ponter reference to classes

int main() {
	srand(time(0)); //Initiate time for random number

	//Declare variables
	int choice = 0;
	int PlayerEdit = 0;
	int playerChoice = 0;
	int userInput = 0;
	char menuChoice = ' ';
	bool inMain = true;
	bool inPlay = false;
	bool inSettings = false;
	bool inAdvanced = false;
	bool inDarts301 = false;
	bool inDarts501 = false;
	bool darts301Throws = false;
	bool darts301Percentages = false;
	bool darts501Throws = false;
	bool darts501Percentages = false;
	std::string player1Name;
	std::string player2Name;
	int player1Accuracy;
	int player2Accuracy;

	std::cout << "Enter name of player 1: ";
	std::cin >> player1Name;
	std::cout << "Enter innerbull accuracy of player 1: ";
	std::cin >> player1Accuracy;
	std::cout << "Enter name of player 2: ";
	std::cin >> player2Name;
	std::cout << "Enter innerbull accuracy of player 2: ";
	std::cin >> player2Accuracy;

	Players* p1 = new Players(player1Name, player1Accuracy);
	Players* p2 = new Players(player2Name, player2Accuracy);
	GameModes game;


	Menus::mainMenu(); //Displays main menu

	while (menuChoice != 'Q' && menuChoice != 'q') { //Runs until user presses Q to quit
		menuChoice = _getch(); //Gets user input
		switch (menuChoice) {
			case '1':
				if (inMain == true && inPlay == false) { //Runs play menu if in main menu
					system("CLS"); //Clear console
					Menus::playMenu(); //Run play menu
					inMain = false;
					inPlay = true;
					break;
				}
				else if (inPlay == true) { //Run Darts 301 menu if in play menu
					system("CLS"); //Clear console
					Menus::darts301Menu(darts301Throws, darts301Percentages); //Run darts 301 menu
					inPlay = false;
					inDarts301 = true;
					break;
				}
				else if (inDarts301 == true) { //Run automatic darts 301 game if in darts 301 menu
					game.darts301(p1, p2); //Runs automatic 301 game
					break;
				}
				else if (inDarts501 == true) { //Run automatic darts 501 game if in darts 501 menu
					game.darts501(p1, p2); //Runs automatic 301 game
					break;
				}
				else if (inSettings == true) { //Change innerbull chance if in settings
					if (PlayerEdit == 0) { //Check which player is selected
						std::cout << "Enter new innerbull chance for " << p1->getName() << ": "; 
						std::cin >> userInput;
						p1->setInnerbullChance(userInput); //Change innerbull chance for player player 1 to user input
					}
					else {
						//Change innerbull chance for player 2
						std::cout << "Enter new innerbull chance for " << p2->getName() << ": ";
						std::cin >> userInput;
						p2->setInnerbullChance(userInput); //Change innerbull chance for player player 21 to user input
					}
					system("CLS"); //Clear screen to update
					Menus::settingsMenu(PlayerEdit, p1, p2); //Display settings menu again with updated chance
					break;
				} 
				else if (inAdvanced == true) { //Change outerbull chance if in advanced menu
					if (PlayerEdit == 0) { //Check which player is selected
						std::cout << "Enter new outerbull chance for " << p1->getName() << ": ";
						std::cin >> userInput;
						p1->setOuterbullChance(userInput); //Change outerbull chance for player player 1 to user input
					}
					else {
						//Change outerbull chance for player 2
						std::cout << "Enter new outerbull chance for " << p2->getName() << ": ";
						std::cin >> userInput;
						p2->setOuterbullChance(userInput); //Change outerbull chance for player player 1 to user input
					}
					system("CLS"); //Clear screen to update
					Menus::advSettingsMenu(PlayerEdit, p1, p2); //Display adv settings menu again with updated chance
					break;
				}
				break;
			case '2':
				if (inMain == true && inSettings == false) { //Runs settings menu if in main menu
					system("CLS");
					Menus::settingsMenu(PlayerEdit, p1, p2); //Displays settins menu
					inMain = false;
					inSettings = true;
					break;
				}
				else if (inPlay == true){ //Run darts 501 menu if in play menu
					system("CLS");
					Menus::darts501Menu(darts501Throws, darts501Percentages); //Displays darts 501 menu
					inPlay = false;
					inDarts501 = true;
					break;
				}
				else if (inDarts301 == true) { //If in darts391 menu changes the the variable darts301Throws which is used to change whether throw information should be displayed
					darts301Throws = !darts301Throws; //Sets darts301Throws to oposite value
					p1->setInfoThrows(darts301Throws); //Uses setter to change it for both players
					p2->setInfoThrows(darts301Throws);
					system("CLS"); //Clears screen
					Menus::darts301Menu(darts301Throws, darts301Percentages); //Loads darts 301 menu again this time with updated yes or no
					break;
				}
				else if (inDarts501 == true) { ////If in darts501 run interactive darts
					//RUN INTERACTIVE DARTS
					p1->setInfoThrows(true); //Sets information about throw to ON
					p2->setInfoThrows(true);
					std::cout << "Input 1 to play as " << p1->getName() << " or 2 to play as " << p2->getName() << std::endl;
					std::cin >> playerChoice;
					if (playerChoice == 1) { //Depending on player choice gives the function a different player
						game.interactiveDarts501(p1);
					}
					else if (playerChoice == 2) {
						game.interactiveDarts501(p2);
					}
					else {
						std::cout << "Invalid input" << std::endl;
					}
					break;
				}
				else if (inAdvanced == true) { //In in advanced settings menu changes single change
					if (PlayerEdit == 0) {
						//Change single chance player 1
						std::cout << "Enter new single chance " << p1->getName() << ": ";
						std::cin >> userInput;
						p1->setHitChance(userInput);
					}
					else {
						//Change single chance for player 2
						std::cout << "Enter new single chance for " << p2->getName() << ": ";
						std::cin >> userInput;
						p2->setHitChance(userInput);
					}
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
					break;
				}
				break;
			case '3':
				if(inDarts301 == true) { ////Change wheter to display DARTS301 DISPLAY PERCENTAGES or not
					darts301Percentages = !darts301Percentages;
					p1->setInfoPercentages(darts301Percentages);
					p2->setInfoPercentages(darts301Percentages);
					system("CLS");
					Menus::darts301Menu(darts301Throws, darts301Percentages);
					break;
				}
				else if (inDarts501 == true) { //Change wheter to display DARTS501 throws information or not
					darts501Throws = !darts501Throws;
					p1->setInfoThrows(darts501Throws);
					p2->setInfoThrows(darts501Throws);
					system("CLS");
					Menus::darts501Menu(darts501Throws, darts501Percentages);
					break;
				}
				else if (inAdvanced == true) { //Changes double chance if in advanced settings
					if (PlayerEdit == 0) {
						//Change double chance player 1
						std::cout << "Enter new double chance for " << p1->getName() << ": ";
						std::cin >> userInput;
						p1->setDoubleChance(userInput);
					}
					else {
						//Change double chance for player 2
						std::cout << "Enter new double chance for " << p2->getName() << ": ";
						std::cin >> userInput;
						p2->setDoubleChance(userInput);
					}
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
					break;
				}
				break;
			case '4': //Change wheter to display DARTS501 DISPLAY PERCENTAGES or not
				if (inDarts501 == true) {
					darts501Percentages = !darts501Percentages;
					p1->setInfoPercentages(darts501Percentages);
					p2->setInfoPercentages(darts501Percentages);
					system("CLS");
					Menus::darts501Menu(darts501Throws, darts501Percentages);
					break;
				}
				else if (inAdvanced == true) { //Changes treble chance if in advanced settings
					if (PlayerEdit == 0) {
						//Change treble chance player 1
						std::cout << "Enter new treble chance for " << p1->getName() << ": ";
						std::cin >> userInput;
						p1->setTrebleChance(userInput);
					}
					else {
						//Change double chance for player 2
						std::cout << "Enter new treble chance for " << p2->getName() << ": ";
						std::cin >> userInput;
						p2->setTrebleChance(userInput);
					}
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
					break;
				}
				break;
			case 'a':
				if (inSettings == true) { //Enters advanced setting menu if in settings menu
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
					inSettings = false;
					inAdvanced = true;
					break;
				}
				break;
			case 'b':
				if (inPlay == true) { //BACK FROM PLAY MENU
					system("CLS");
					Menus::mainMenu();
					inMain = true;
					inPlay = false;
					break;
				}
				else if (inSettings == true) { //BACK FROM SETTINGS MENU
					system("CLS");
					Menus::mainMenu();
					inMain = true;
					inSettings = false;
					break;
				}
				else if (inAdvanced == true) { //BACK FROM ADV SETTINGS MENU
					system("CLS");
					Menus::settingsMenu(PlayerEdit, p1, p2);
					inSettings = true;
					inAdvanced = false;
					break;
				}
				else if (inDarts301 == true) { //BACK FROM DARTS301 MENU
					system("CLS");
					Menus::playMenu();
					inPlay = true;
					inDarts301 = false;
					break;
				}
				else if (inDarts501 == true) { //BACK FROM DARTS501 MENU
					system("CLS");
					Menus::playMenu();
					inPlay = true;
					inDarts501 = false;
					break;
				}
				break;
			case 'r':
				if (inSettings == true) {
					//RESET BASIC SETTINS TO DEFAULT INPUTED BY USER AT START
					if (PlayerEdit == 0) {
						//Change treble chance player 1
						p1->setInnerbullChance(player1Accuracy);
					}
					else {
						p2->setInnerbullChance(player1Accuracy);
					}
					system("CLS");
					Menus::settingsMenu(PlayerEdit, p1, p2);
					break;
				}
				else if (inAdvanced == true) {
					//RESET TO ADVANCED SETTINS TO DEFAULT 80
					if (PlayerEdit == 0) {
						p1->setOuterbullChance(80);
						p1->setHitChance(80);
						p1->setDoubleChance(80);
						p1->setTrebleChance(80);
					}
					else {
						p2->setOuterbullChance(80);
						p2->setHitChance(80);
						p2->setDoubleChance(80);
						p2->setTrebleChance(80);
					}
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
					break;
				}
				break;

			case 'p':
				if (inSettings == true) { //Changes which player's settings get changed
					PlayerEdit = !PlayerEdit; //sets to oposite
					system("CLS");
					Menus::settingsMenu(PlayerEdit, p1, p2);
				}
				else if (inAdvanced == true) { //Changes which player's adv settings get changed
					PlayerEdit = !PlayerEdit; //sets to oposite
					system("CLS");
					Menus::advSettingsMenu(PlayerEdit, p1, p2);
				}
				break;
			case 'q':
				break;
			default:
				std::cout << "Wrong input" << std::endl;
				
		}
	}

	//Deletes objects
	delete p1; 
	delete p2;

	return 0;
}