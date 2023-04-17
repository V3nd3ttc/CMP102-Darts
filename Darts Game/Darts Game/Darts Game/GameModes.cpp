#include "GameModes.h"
#include <iostream>
#include <string>

GameModes::GameModes()
{
}

GameModes::~GameModes()
{
}


void GameModes::darts301(Players* p1, Players* p2)
{
	p1->setScore(301); //Sets score of both players to 301 for a game of 301
	p2->setScore(301);

	Players* playingPlayer = p1; //Declare a new variable equal to the pointer of p1
	
	std::cout << "Running automatic 301 darts" << std::endl;

	//Decide who goes first
	std::cout << "Type '1' if you want " << p1->getName() << " to go first or '2' if you want " << p2->getName() << " to go first" << std::endl;
	std::cin >> choice;

	if (choice == 1) { //Changes who goes first
		playingPlayer = p1;
		std::cout << p1->getName() << " will go first" << std::endl;
	}
	else if (choice == 2) {
		playingPlayer = p2;
		std::cout << p2->getName() << " will go first" << std::endl;
	}
	else {
		std::cout << "Invalid input" << std::endl;
	}

	std::cout << "Type how many games you want to simulate: ";
	std::cin >> numberOfGames;

	for (int i = 1; i <= numberOfGames; i++)
	{
		std::cout << "Has ran " << i << " times" << std::endl;
		
		while (p1->checkWinner() == false && p2->checkWinner() == false) { //Runs until 1 player wins
			
			int scoreNow = playingPlayer->getScore();
			int difference = scoreNow - 50;

			if (scoreNow > 70 || scoreNow == 50) { //Throws for bull until score gets 50 bull or when score is 50
				playingPlayer->throwDart(50, 301, 'b');
			}
			else if (scoreNow <= 70 && scoreNow > 50) {
				playingPlayer->throwDart(difference, 301, 's');
			}

			if (playingPlayer == p1) {
				playingPlayer = p2;
			}
			else if (playingPlayer == p2) {
				playingPlayer = p1;
			}
		}
		if (p1->checkWinner() == true) { //Checks who has won
			p1->wonRound();
		}
		else {
			p2->wonRound();
		}
		p1->setScore(301);
		p2->setScore(301);
	}
	std::cout << "=================================================" << std::endl;
	std::cout << "  ______  _____  _____  _   _  _    _____  _____ " << std::endl;
	std::cout << "  | ___ \\|  ___|/  ___|| | | || |  |_   _|/  ___|" << std::endl;
	std::cout << "  | |_/ /| |__  \\ `--. | | | || |    | |  \\ `--. " << std::endl;
	std::cout << "  |    / |  __|  `--. \\| | | || |    | |   `--. \\" << std::endl;
	std::cout << "  | |\\ \\ | |___ /\\__/ /| |_| || |____| |  /\\__/ /" << std::endl;
	std::cout << "  \\_| \\_|\\____/ \\____/  \\___/ \\_____/\\_/  \\____/ " << std::endl;
	std::cout << "                                                 " << std::endl;
	std::cout << "=================================================" << std::endl;
	float winPercent1 = (float(p1->getWinCount()) / float(numberOfGames)) * 100;
	std::cout << p1->getName() << " won in " << winPercent1 << "% of games" << std::endl;
	float winPercent2 = (float(p2->getWinCount()) / float(numberOfGames)) * 100;
	std::cout << p2->getName() << " won in " << winPercent2 << "% of games" << std::endl;
	std::cout << std::endl;
	p1->averageCalculate(301);
	p2->averageCalculate(301);
	std::cout << "=================================================" << std::endl;
	std::cout << "B. Go back to darts 301 menu" << std::endl;

}

void GameModes::darts501(Players* p1, Players* p2) {
	p1->setScore(501);
	p2->setScore(501); //Sets score for both players to 501

	Players* playingPlayer = p1;

	std::cout << "Running automatic 501 darts" << std::endl;

	int random = rand() % 2 + 1; //50/50 who goes first
	if (random == 1) {
		playingPlayer = p1;
		std::cout << p1->getName() << " will go first" << std::endl;
	}
	else {
		playingPlayer = p2;
		std::cout << p2->getName() << " will go first" << std::endl;
	}


	std::cout << "Type how many games you want to simulate: ";
	std::cin >> numberOfGames;

	for (int i = 1; i <= numberOfGames; i++)
	{
		std::cout << "Has ran " << i << " times" << std::endl;
		while (p1->getSetsWon() != 7 && p2->getSetsWon() != 7) //Runs until one player gets to 7 set wins
		{
			while (p1->getWinCount() != 3 && p2->getWinCount() != 3) { //Runs until one player gets to 7 round wins
				while (p1->checkWinner() == false && p2->checkWinner() == false) { //Runs until one player wins round
					for (int i = 0; i < 3; i++) { //Runs three times to make 3 dart throws
						if (p1->getScore() > p2->getScore()) { //Checks who is ahead
							p2->setIsAhead(true);
							p1->setIsAhead(false);
						}
						else {
							p1->setIsAhead(true);
							p2->setIsAhead(false);
						}
						playingPlayer->strategy(); //Runs strategy
						if (playingPlayer->checkWinner() == true) { //Stops loop if player wins
							break;
						}
					}
					
					if (playingPlayer == p1) { //Switches players
						playingPlayer = p2;
					}
					else {
						playingPlayer = p1;
					}
					
				}
				if (p1->checkWinner() == true) { //Checks who has won round
					p1->wonRound();
					//std::cout << p1->getName() << " has won a round." << std::endl; //Commented out to increase speed in automatic
				}
				else {
					p2->wonRound();
					//std::cout << p2->getName() << " has won a round." << std::endl;
				}
	
				//std::cout << p1->getName() << " has: " << p1->getWinCount() << " round wins" << std::endl; //Commented out to increase speed in automatic
				//std::cout << p2->getName() << " has: " << p2->getWinCount() << " round wins" << std::endl; //Commented out to increase speed in automatic
				p1->setScore(501);
				p2->setScore(501);
			}

			if (p1->getWinCount() == 3 ) {
				p1->wonSet();
				//std::cout << p1->getName() << " has won a set." << std::endl; //Commented out to increase speed in automatic
			}
			else if (p2->getWinCount() == 3) {
				p2->wonSet();
				//std::cout << p2->getName() << " has won a set." << std::endl; //Commented out to increase speed in automatic
			}

			
			//std::cout << p1->getName() << " has: " << p1->getSetsWon() << " set wins" << std::endl; Commented out to increase speed in automatic
			//std::cout << p2->getName() << " has: " << p2->getSetsWon() << " set wins" << std::endl; Commented out to increase speed in automatic

			p1->setWinCount(0); //Resets win count for both players so it loops again
			p2->setWinCount(0);
		}
		if (p1->getSetsWon() == 7) { //Checks who won the championsip
			setsWonArray[0][p2->getSetsWon()]++; //Increments the array for player 1 in the collumn where the enemy finished. For example if enemy finish with 5 sets increment collumn number 5
			p1->wonChampionship(); //Increaments stats
		}
		else if (p2->getSetsWon() == 7) {
			setsWonArray[1][p1->getSetsWon()]++; //Increments the array for player 1 in the collumn where the enemy finished. For example if enemy finish with 5 sets increment collumn number 5
			p2->wonChampionship(); //Increaments stats
		}
		
		p1->setSetsWon(0);
		p2->setSetsWon(0);
		
	}
		
	std::cout << "=================================================" << std::endl;
	std::cout << "  ______  _____  _____  _   _  _    _____  _____ " << std::endl;
	std::cout << "  | ___ \\|  ___|/  ___|| | | || |  |_   _|/  ___|" << std::endl;
	std::cout << "  | |_/ /| |__  \\ `--. | | | || |    | |  \\ `--. " << std::endl;
	std::cout << "  |    / |  __|  `--. \\| | | || |    | |   `--. \\" << std::endl;
	std::cout << "  | |\\ \\ | |___ /\\__/ /| |_| || |____| |  /\\__/ /" << std::endl;
	std::cout << "  \\_| \\_|\\____/ \\____/  \\___/ \\_____/\\_/  \\____/ " << std::endl;
	std::cout << "                                                 " << std::endl;
	std::cout << "=================================================" << std::endl;

	if (p1->getChampionshipsWon() > p2->getChampionshipsWon()) { //Check who has won more championshops
		std::cout << p1->getName() << " has won more championships. He/she has: " << p1->getChampionshipsWon() << " championship wins" << std::endl;
		float winPercent1 = (float(p1->getChampionshipsWon()) / float(numberOfGames)) * 100;
		std::cout << p1->getName() << " won in " << winPercent1 << "% of championship games" << std::endl;
		std::cout << p2->getName() << " has: " << p2->getChampionshipsWon() << " championship wins" << std::endl;
	}
	else {
		std::cout << p2->getName() << " has won more championships. He/she has: " << p2->getChampionshipsWon() << " championship wins" << std::endl;
		float winPercent2 = (float(p2->getChampionshipsWon()) / float(numberOfGames)) * 100;
		std::cout << p2->getName() << " won in " << winPercent2 << "% of championship games" << std::endl;
		std::cout << p1->getName() << " has: " << p1->getChampionshipsWon() << " championship wins" << std::endl;

	}

	for (int a = 0; a < 2; a++) { //Loops through the array for both players
		if (a == 0) {
			std::cout << p1->getName() << ": " << p2->getName() << std::endl;
		}
		else {
			std::cout << p2->getName() << ": " << p1->getName() << std::endl;
		}
		for (int b = 6; b >= 0; b--) { //Loops through all collumnds in the array
			setsWonTotal[a][b] = (float(setsWonArray[a][b]) / float(numberOfGames)) * 100; //Gets the frequncies of a certain ending happening
			std::cout << "7:" << b << " with "<< setsWonTotal[a][b] << " % chance" << std::endl;
		}
		std::cout << "============================================" << std::endl;
	}

	p1->averageCalculate(501);
	p2->averageCalculate(501);
}

void GameModes::interactiveDarts501(Players* player) {
	player->setScore(501); //Sets the score of the player to 501 for darts 501

	Players* ai = new Players("Ai", 80);
	ai->setInfoThrows(true); //Turns the information about throws on
	ai->setScore(501); //Sets the score of the ai to 501 for darts 501

	Players* playingPlayer = player;
	int target = 0;
	char trowType = ' ';

	std::cout << "Running interactive 501 darts" << std::endl;

	int random = rand() % 2 + 1; //50/50 chance who goes first
	if (random == 1) {
		playingPlayer = player;
		std::cout << player->getName() << " will go first" << std::endl;
	}
	else {
		playingPlayer = ai;
		std::cout << ai->getName() << " will go first" << std::endl;
	}

	system("Pause"); //Pauses so user can read
	system("CLS");

	while (player->getSetsWon() != 7 && ai->getSetsWon() != 7) //Runs until one player gets to 7 set wins
	{
		while (player->getWinCount() != 3 && ai->getWinCount() != 3) { //Runs until one player gets to 7 round wins
			while (player->checkWinner() == false && ai->checkWinner() == false) { //Runs until one player wins round
				if (playingPlayer == player) { //Checks if it is the user's turn
					for (int i = 1; i <= 3; i++) { //Runs three times to make 3 dart throws
						std::cout << "=================================================================" << std::endl;
						std::cout << "Current dart throw " << i << "/3" << std::endl;
						std::cout << "You current score is " << player->getScore() << "                  AI current score is "  << ai->getScore() << std::endl; 
						std::cout << "You current game won is " << player->getWinCount() << "                  AI current game won is " << ai->getWinCount() << std::endl;
						std::cout << "You current sets won is " << player->getSetsWon() << "                  AI current sets won is " << ai->getSetsWon() << std::endl;
						std::cout << "=================================================================" << std::endl;
						std::cout << "Input 's' to make a single throw, 'd' to make a double throw, 't' to make a treble throw or 'b' to make a throw for bull ";
						std::cin >> trowType;
						if (trowType == 's' || trowType == 'd' || trowType == 't') { //Checks if the throw type is single, double or treble
							std::cout << "Input what target to aim for (1-20)" << std::endl; //Asks for target
							std::cin >> target;
							std::cout << "-----------------------------------" << std::endl;
							playingPlayer->throwDart(target, 501, trowType); //Throws dart
							system("Pause"); //Pauses so player can examine their throw and its result
							system("CLS");
							if (playingPlayer->checkWinner() == true) { //Check if the player has won in order to stop another throw from happening
								break;
							}
						}
						else if (trowType == 'b') { //Check if user wants to throw for bull
							std::cout << "Input 25 to aim for outer bull or 50 to aim for inner bull" << std::endl; 
							std::cin >> target;
							std::cout << "----------------------------------------------------------" << std::endl;
							playingPlayer->throwDart(target, 501, trowType);
							system("Pause"); //Pauses so player can examine their throw and its result
							system("CLS");
							if (playingPlayer->checkWinner() == true) { //Check if the player has won in order to stop another throw from happening
								break;
							}
						}
						else {
							std::cout << "Incorrect input" << std::endl;
							system("Pause");
							system("CLS");
							i--; //Runs loop again if input incorrect
						}
					}
					if (playingPlayer->checkWinner() != true) { //If player has not won switch to ai
						playingPlayer = ai;
					}
						
				}
				else {
					for (int i = 1; i <= 3; i++) { //Runs three times to make 3 dart throws
						std::cout << "Current dart throw " << i << "/3" << std::endl;
						if (player->getScore() > ai->getScore()) { //checks if ahead
							ai->setIsAhead(true);
							player->setIsAhead(false);
						}
						else {
							player->setIsAhead(true);
							ai->setIsAhead(false);
						}
						playingPlayer->strategy(); //Runs strategy
						if (playingPlayer->checkWinner() == true) { //Stops throwing if it wins
							break;
						}
					}
					system("Pause"); //Pauses so user can examine the results of the throws of the ai
					system("CLS");
					if (playingPlayer->checkWinner() != true) {
						playingPlayer = player;
					}
				}		
			}
			std::cout << playingPlayer->getName() << " has won a game" << std::endl;
			if (player->checkWinner() == true) { //Checks who won
				player->wonRound();
			}
			else {
				ai->wonRound();
			}
			std::cout << "Your current score is " << player->getScore() << "                  AI current score is " << ai->getScore() << std::endl;
			std::cout << "Your current game won is " << player->getWinCount() << "                  AI current game won is " << ai->getWinCount() << std::endl;
			std::cout << "Your current sets won is " << player->getSetsWon() << "                  AI current sets won is " << ai->getSetsWon() << std::endl;
			if (playingPlayer == player)
			{
				playingPlayer = ai;
			}
			else {
				playingPlayer = player;
			}
			system("Pause"); //Pauses so user can read
			system("CLS");

			player->setScore(501); //Resets scores to 501 so loops runs again with correct score
			ai->setScore(501); //Resets scores back to 501 so loops runs again with correct score
		}
		if (player->getWinCount() == 3) { //Checks who won set
			player->wonSet();
		}
		else if (ai->getWinCount() == 3) {
			ai->wonSet();
		}

		std::cout << playingPlayer->getName() << " has won a set" << std::endl;
		std::cout << "Your current score is " << player->getScore() << "                  AI current score is " << ai->getScore() << std::endl;
		std::cout << "Your current game won is " << player->getWinCount() << "                  AI current game won is " << ai->getWinCount() << std::endl;
		std::cout << "Your current sets won is " << player->getSetsWon() << "                  AI current sets won is " << ai->getSetsWon() << std::endl;
		system("Pause");
		system("CLS");

		player->setWinCount(0); //sets win count to 0 so loop runs again
		ai->setWinCount(0); //sets win count to 0 so loop runs again
	}
	if (player->getSetsWon() == 7) { //Checks who won championship
		setsWonArray[0][ai->getSetsWon()]++; //Increments the array for player in the collumn where the enemy finished. For example if enemy finish with 5 sets increment collumn number 5
		player->wonChampionship();
	}
	else if (ai->getSetsWon() == 7) {
		setsWonArray[1][player->getSetsWon()]++; //Increments the array for ai in the collumn where the enemy finished. For example if enemy finish with 5 sets increment collumn number 5
		ai->wonChampionship();
	}

	player->setSetsWon(0); //Resets amount of sets won
	ai->setSetsWon(0);

	std::cout << "=================================================" << std::endl;
	std::cout << "  ______  _____  _____  _   _  _    _____  _____ " << std::endl;
	std::cout << "  | ___ \\|  ___|/  ___|| | | || |  |_   _|/  ___|" << std::endl;
	std::cout << "  | |_/ /| |__  \\ `--. | | | || |    | |  \\ `--. " << std::endl;
	std::cout << "  |    / |  __|  `--. \\| | | || |    | |   `--. \\" << std::endl;
	std::cout << "  | |\\ \\ | |___ /\\__/ /| |_| || |____| |  /\\__/ /" << std::endl;
	std::cout << "  \\_| \\_|\\____/ \\____/  \\___/ \\_____/\\_/  \\____/ " << std::endl;
	std::cout << "                                                 " << std::endl;
	std::cout << "=================================================" << std::endl;

	if (player->getChampionshipsWon() > player->getChampionshipsWon()) {
		std::cout << player->getName() << " has won more championships. He/she has: " << player->getChampionshipsWon() << " championship wins" << std::endl;
		std::cout << ai->getName() << " has: " << ai->getChampionshipsWon() << " championship wins" << std::endl;
	}
	else {
		std::cout << ai->getName() << " has won more championships. He/she has: " << ai->getChampionshipsWon() << " championship wins" << std::endl;
		std::cout << player->getName() << " has: " << player->getChampionshipsWon() << " championship wins" << std::endl;
	}

	for (int a = 0; a < 2; a++) { //Loops through the array for both players
		if (a == 0) {
			std::cout << player->getName() << ": " << ai->getName() << std::endl;
		}
		else {
			std::cout << ai->getName() << ": " << player->getName() << std::endl;
		}
		for (int b = 6; b >= 0; b--) { //Loops through all collumnds in the array
			setsWonTotal[a][b] = (float(setsWonArray[a][b]) / float(numberOfGames)) * 100; //Gets the frequncies of a certain ending happening
			std::cout << "7:" << b << " with " << setsWonTotal[a][b] << " % chance" << std::endl;
		}
		std::cout << "============================================" << std::endl;
	}

	player->averageCalculate(501);
	ai->averageCalculate(501);

	delete ai; //Deletes object
}