#include "Players.h"
#include <iostream>
#include <string>


//Constructors and Destructors

Players::Players(std::string n, int b) {
	name = n;
	innerbull_chance = b;
}
Players::Players()
{
	//Delete heap memory
	//Delete heap memory
	name = "no name";
}
Players::~Players()
{
	//delete heap memory
	//delete heap memory
	std::cout << "Destroyed object" << std::endl;
}

////Getters

//Stats getters
std::string Players::getName()
{
	return name;
}

//Chance Getters
int Players::getInnerbullChance()
{
	return innerbull_chance;
}
int Players::getOuterbullChance()
{
	return outerbull_chance;
}
int Players::getHitChance()
{
	return hit_chance;
}
int Players::getDoubleChance()
{
	return double_chance;
}
int Players::getTrebleChance()
{
	return treble_chance;
}
int Players::getWinCount()
{
	return winCount;
}
int Players::getSetsWon() {
	return setsWon;
}
int Players::getChampionshipsWon() {
	return championshipsWon;
}

//Score Getters
int Players::getScore()
{
	return score;
}
int Players::getTempScore()
{
	return tempScore;
}

//Info Getters
bool Players::getInfoThrows()
{
	return infoThrows;
}
bool Players::getInfoPercentages()
{
	return infoPercentages;
}
bool Players::getIsAhead()
{
	return isAhead;
}





//Setters
void Players::setName(std::string newName)
{
	name = newName;
}

//Chance setters
void Players::setInnerbullChance(int newInnerbullChance)
{
	innerbull_chance = newInnerbullChance;
}
void Players::setOuterbullChance(int newOuterbullChance)
{
	outerbull_chance = newOuterbullChance;
}
void Players::setHitChance(int newHitChance)
{
	hit_chance = newHitChance;
}
void Players::setDoubleChance(int newDoubleChance)
{
	double_chance = newDoubleChance;
}
void Players::setTrebleChance(int newTrebleChance)
{
	treble_chance = newTrebleChance;
}

//Stats setters
void Players::setWinCount(int newWinCount)
{
	winCount = newWinCount;
}
void Players::setSetsWon(int newSetsWon) {
	setsWon = newSetsWon;
}
void Players::setChampionshipsWon(int newChampionshipsWon) {
	championshipsWon = newChampionshipsWon;
}

//Score setters
void Players::setScore(int newScore)
{
	score = newScore;
}
void Players::setTempScore(int newTempScore)
{
	tempScore = newTempScore;
}

//Info setters
void Players::setInfoThrows(bool newInfoThrows)
{
	infoThrows = newInfoThrows;
}
void Players::setInfoPercentages(bool newInfoPercentages) {
	infoPercentages = newInfoPercentages;
}
void Players::setIsAhead(bool newAhead) {
	isAhead = newAhead;
}


//Throw functions
void Players::throwDart(int target, int gamemode, char trowType) { //Functions which allow the throwing of the dart using target, gamemode and trowType as variables
	tempScore = score; //Sets current score to temporary
	if (infoThrows == false) { //If user does not want to see throws
		std::cout.setstate(std::ios_base::failbit); //Stops couts from displaying
	}
	if (target == 50 && trowType == 'b') {
		throwInnerBull(gamemode);
	}
	else if (target == 25 && gamemode != 301 && trowType == 'b') {
		throwOuterBull(gamemode);
	}
	else if (target <= 20) {
		switch (trowType) {
		case 's':
			throwSingle(target, gamemode);
			break;
		case 'd':
			throwDouble(target, gamemode);
			break;
		case 't':
			throwTreble(target, gamemode);
			break;
		default:
			std::cout << "Invalid throw type. ERROR!" << std::endl;
			break;
		}
	}
	else {
		std::cout << "Incorrect target. ERROR!" << target << std::endl;
	}
	if (infoThrows == false) { //If user does not want to see throws
		std::cout.clear(); //Allows couts to display again
	}
}

void Players::throwInnerBull(int gamemode) {
	int random = rand() % 100 + 1; //Generate a random number between 1 and 100 and puts it in variable random
	int randomSide = rand() % 2 + 1; //Generate a random number between 1 and 2 and puts it in variable randomSide
	std::cout << "Player now " << name << std::endl;
	std::cout << "Random is:" << random;
	std::cout << "		Score : " << score;
	std::cout << "		Random side is: " << randomSide << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Target was: 50 inner bull" << std::endl;

	if (random <= innerbull_chance) { //checks if generated number is smaller or equal to the innerbull chance. If it is hits. Otherwise if goes to next else if
		std::cout << name << " hit 50 inner bullseye" << std::endl; //Displays message
		if (validScore(50, gamemode, 'b')) { //Checks if the throw for 50 will be valid aka the score will not go below 0 if in darts301 and below 1 in darts501
			score -= 50; //Reduces the score
			std::cout << "Score now: " << score << std::endl;
		}
		else {
			std::cout << "Invalid score" << std::endl;
		}
		innerBullseyesIN++; //Adds 1 to count
	}
	else if (randomSide == 1 && gamemode != 301) { //If the innerbullseye missed and the gamemode is 501 hit with 50% chance outerbullseye or a random number from 1 to 20. Else if gamemode is 301 do not hit outerbullseye
		std::cout << name << " hit 25 outer bullseye" << std::endl; //Displays message
		if (validScore(25, gamemode, 'b')) { //Checks if the throw for 25 will be valid aka the score will not go below 0 if in darts301 and below 1 in darts501
			score -= 25; //Reduces score
			std::cout << "Score now: " << score << std::endl;
		}
		else {
			std::cout << "Invalid score" << std::endl;
		}
		outerBullseyesIN++; //Adds 1 to count
	}
	else if (randomSide == 2 || gamemode == 301) { //50% chance to hit a random number from 1 to 20 if the gamemode is 501. 100% chance to hit a random number if gamemode is 301
		int random_score = rand() % 20 + 1; //Generates a random number between 1 and 20
		std::cout << name << " hit " << random_score << ", missed inner bullseye" << std::endl; //Displays message
		if (validScore(random_score, gamemode, 's')) { //Checks if the throw for random number will be valid aka the score will not go below 0 if in darts301 and below 1 in dart
			score -= random_score;
			std::cout << "Score now: " << score << std::endl;
		}
		else {
			std::cout << "Invalid score" << std::endl;
		}

		missedBullseyesIN++; //Increments missed bullseyes
	}
	innerBullseyeThrows++; //Increments throws
	std::cout << "==================================================================" << std::endl;
	std::cout << std::endl;
	//return false; old system
}

void Players::throwOuterBull(int gamemode) {
	if (gamemode != 301) { //Checks if gamemode is 301 if it is does not allow function to run
		int random = rand() % 100 + 1; //Generate a random number between 1 and 100 and puts it in variable random
		int randomSide = rand() % 2 + 1; //Generate a random number between 1 and 2 and puts it in variable randomSide
		std::cout << "Player now " << name << std::endl;
		std::cout << "Random is:" << random;
		std::cout << "		Score : " << score;
		std::cout << "		Random side is: " << randomSide << std::endl << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "Target was: 25 outer bull" << std::endl;

		if (random <= outerbull_chance) { //checks if generated number is smaller or equal to the outerbull chance. If it is hits. Otherwise if goes to next else if
			std::cout << name << " hit 25 outer bullseye" << std::endl; //Displays message
			if (validScore(25, gamemode, 'b')) { //Checks if the throw for 25 will be valid aka the score will not go below 1 in darts 501
				score -= 25;
				std::cout << "Score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			outerBullseyesOUT++;
		}
		else if (randomSide == 1) { //If the outerbullseye missed hit with 50% chance innerbulleye or a random number from 1 to 20.
			std::cout << name << " hit 50 inner bullseye" << std::endl; //Displays message
			if (validScore(50, gamemode, 'b')) { //Checks if the throw for 50 will be valid aka the score will not go below 1 in darts 501
				score -= 50;
				std::cout << "Score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			innerBullseyesOUT++;
		}
		else  if (randomSide == 2) {
			int random_score = rand() % 20 + 1; //Generates a random number between 1 and 20
			std::cout << name << " hit " << random_score << ", missed outer bullseye" << std::endl; //Displays message
			if (validScore(random_score, gamemode, 's')) { 
				score -= random_score;
				std::cout << "Score now: " << score << std::endl; //Checks if the throw for random number will be valid aka the score will not go below 1 in darts 501
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}

			missedBullseyesOUT++;
			//return false; old system
		}
		outerBullseyeThrows++; //Increments throws
		std::cout << "==================================================================" << std::endl;
		std::cout << std::endl;
		/*std::cout.clear();*/
	}
	else {
		std::cout << "You cannot throw for an outer bull in 301 darts. Nice try!" << std::endl;
	}

}

void Players::throwSingle(int target, int gamemode) {
	int randomStraight = rand() % 100 + 1; //Generates  a random between 1 and 100
	int randomSide = rand() % 8 + 1; //Generates  a random between 1 and 8. Each number respresent one of the 8 surroundingg the target segments
	if (gamemode == 301) {
		randomSide = rand() % 2 + 1; //If gamemode is 301 generates  a random between 1 and 2. Because in 301 you cant hit double or treble
	}
	std::cout << "Player now " << name << std::endl;
	std::cout << "Random is:" << randomStraight;
	std::cout << "		Score : " << score;
	std::cout << "		Random side is: " << randomSide << std::endl;
	std::cout << "==================================================================" << std::endl;
	if (randomStraight <= hit_chance) { //checks if the randomstraight number is less then or equal to hit_chance. If it is it hits. If it is not it misses hits a surrounding target
		std::cout << "Target was: " << target << " single" << std::endl;
		if (validScore(target, gamemode, 's')) { //Checks if the target will be a valid score
			score -= target;
			std::cout << name << " hit target" << std::endl;
			std::cout << name << " score now: " << score << std::endl;
		}
		else {
			std::cout << name << " hit target" << std::endl;
			std::cout << "Invalid score" << std::endl;
		}
		hitTargetSIN++;
	}
	else {
		switch (randomSide) //Checks the randomSide number to know which one was hit.
		{
		case 1: //Hits left neighbour. 1/8 chance if gamemode is 501. 1/2 chance if gamemode is 301 
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << name << " missed single target, hit left single neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

			if (validScore(DartBoard::getLeftNeighbour(target), gamemode, 's')) { //Checks if score will be valid
				score -= DartBoard::getLeftNeighbour(target); //Reduces score using getLeftNeighbour function from dartboard
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			wentLeftTargetSIN++;
			break;
		case 2: //Hits right neighbour. 1/8 chance if gamemode is 501. 1/2 chance if gamemode is 301
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << name << " missed single target, hit right single neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

			if (validScore(DartBoard::getRightNeighbour(target), gamemode, 's')) {
				score -= DartBoard::getRightNeighbour(target); //Reduces score using getRighrNeighbour function from dartboard
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;

			}
			wentRightTargetSIN++;
			break;
		case 3: //Hits top left neighbour. 1/8 chance
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit left double neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

			if (validScore(2 * DartBoard::getLeftNeighbour(target), gamemode, 'd')) {
				score -= 2 * DartBoard::getLeftNeighbour(target);
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			wentLeftDoubleSIN++;
			break;
		case 4: //Hits neighbour on top. 1/8 chance
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit straight double neighbour " << target << std::endl;

			if (validScore(2 * target, gamemode, 'd')) {
				score -= 2 * target;
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;

			}
			wentStraightDoubleSIN++;
			break;
		case 5: //Hits neighbour on top right. 1/8 chance
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit right double neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

			if (validScore(2 * DartBoard::getRightNeighbour(target), gamemode, 'd')) {
				score -= 2 * DartBoard::getRightNeighbour(target);
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			wentRightDoubleSIN++;
			break;
		case 6: //Hits neighbour on bottom left. 1/8
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit left treble neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

			if (validScore(3 * DartBoard::getLeftNeighbour(target), gamemode, 't')) {
				score -= 3 * DartBoard::getLeftNeighbour(target);
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;

			}
			wentLeftTrebleSIN++;
			break;
		case 7: //Hits bottom neighbour. 1/8 chance
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit straight treble neighbour " << target << std::endl;

			if (validScore(3 * target, gamemode, 't')) {
				score -= 3 * target;
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;

			}
			wentStraightTrebleSIN++;
			break;
		case 8: //Hits bottom right neighbour
			std::cout << "Target was: " << target << " single" << std::endl;
			std::cout << "Missed single target, hit right treble neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

			if (validScore(3 * DartBoard::getRightNeighbour(target), gamemode, 't')) {
				score -= 3 * DartBoard::getRightNeighbour(target);
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			wentRightTrebleSIN++;
			break;
		default:
			std::cout << "ERROR IN SWITCH AT THROW SINGLE" << std::endl;
			break;
		}
	}
	throwsSIN++;
	std::cout << "==================================================================" << std::endl;
	std::cout << std::endl;
	/*std::cout.clear();*/
}

void Players::throwDouble(int target, int gamemode) {
	if (gamemode != 301) //Does not run unless gamemode is 501, because there is no double throws in 301
	{
		int randomStraight = rand() % 100 + 1; //Generate a random number between 1 and 100
		int randomSide = rand() % 8 + 1; //Generates  a random between 1 and 8. Each number respresent one of the 8 surroundingg the target segments
		std::cout << "Player now " << name << std::endl;
		std::cout << "Random is:" << randomStraight;
		std::cout << "		Score : " << score;
		std::cout << "		Random side is: " << randomSide << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "Target was: " << target << " double" << std::endl;

		if (randomStraight <= double_chance) { //checks if generated number is smaller or equal to the outerbull chance. If it is hits. Otherwise if goes to next else if
			std::cout << name << " hit target" << std::endl;
			if (validScore(2 * target, gamemode, 'd')) {
				score -= 2 * target;
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}
			hitTargetDOU++;
		}
		else {
			switch (randomSide) //Checks the randomSide number to know which one was hit.
			{
			case 1:
				std::cout << name << " missed double target, hit left double neighbour " << DartBoard::getLeftNeighbour(target) << std::endl; //Hit left neighbour 1/8 chance

				if (validScore(2 * DartBoard::getLeftNeighbour(target), gamemode, 'd')) {
					score -= 2 * DartBoard::getLeftNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;
				}
				wentLeftTargetDOU++;
				break;
			case 2:
				std::cout << name << " missed double target, hit right double neighbour " << DartBoard::getRightNeighbour(target) << std::endl; //Hit right neighbour 1/8 chance

				if (validScore(2 * DartBoard::getRightNeighbour(target), gamemode, 'd')) {
					score -= 2 * DartBoard::getRightNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentRightTargetDOU++;
				break;
			case 3:
			case 4: //Misses dartboard 3/8 chance because of possible 3 miss segments
			case 5:
				std::cout << "Missed dartboard" << std::endl;
				std::cout << name << " score now: " << score << std::endl;
				missed++;
				break;
			case 6: //Hits bottom left neighbour
				std::cout << name << " missed double target, hit left single neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

				if (validScore(DartBoard::getLeftNeighbour(target), gamemode, 's')) {
					score -= DartBoard::getLeftNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentLeftSingleDOU++;
				break;
			case 7: //Hits bottom neighbour
				std::cout << name << " missed double target, hit straight single neighbour " << target << std::endl;

				if (validScore(target, gamemode, 's')) {
					score -= target;
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentStraightSingleDOU++;
				break;
			case 8: //Hits bottom right neighbour
				std::cout << name << " missed double target, hit right single neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

				if (validScore(DartBoard::getRightNeighbour(target), gamemode, 's')) {
					score -= DartBoard::getRightNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;
				}
				wentRightSingleDOU++;
				break;
			default:
				std::cout << "ERROR IN SWITCH AT THROW DOUBLE" << std::endl;
				break;
			}
		}
		throwsDOU++;
		std::cout << "==================================================================" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "You cannot throw for double in 301. Nice try!" << std::endl;
	}
}

void Players::throwTreble(int target, int gamemode) {
	if (gamemode != 301)  //Does not run unless gamemode is 501, because there is no treble throws in 301
	{
		int randomStraight = rand() % 100 + 1; //Generates  a random between 1 and 100.
		int randomSide = rand() % 8 + 1; //Generates  a random between 1 and 8. Each number respresent one of the 8 surroundingg the target segments
		std::cout << "Player now " << name << std::endl;
		std::cout << "Random is:" << randomStraight;
		std::cout << "		Score : " << score;
		std::cout << "		Random side is: " << randomSide << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "Target was: " << target << " treble" << std::endl;

		if (randomStraight <= treble_chance) { //Checks if randomStraight is equal to less the treble chance. If it is the shot hits, otherwise it misses
			if (validScore(3 * target, gamemode, 't')) {
				score -= 3 * target;
				std::cout << name << " hit target" << std::endl;
				std::cout << name << " score now: " << score << std::endl;
			}
			else {
				std::cout << "Invalid score" << std::endl;
			}

			hitTargetTRE++;
		}
		else {
			switch (randomSide) //Checks the randomSide number to know which one was hit.
			{
			case 1: //Hit left neighbour 1/8 chance
				std::cout << "Missed treble target, hit left treble neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

				if (validScore(3 * DartBoard::getLeftNeighbour(target), gamemode, 't')) {
					score -= 3 * DartBoard::getLeftNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;
				}
				wentLeftTargetTRE++;
				break;
			case 2: //Hit right neighbour. 1/8 chance
				std::cout << "Missed treble target, hit right treble neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

				if (validScore(3 * DartBoard::getRightNeighbour(target), gamemode, 't')) {
					score -= 3 * DartBoard::getRightNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;
				}
				wentRightTargetTRE++;
				break;
			case 3:
			case 4: //hit top/bot left single neighbour. 2/8 chance sinde treble segments are surrounded by single segments
				std::cout << "Missed treble target, hit left single neighbour " << DartBoard::getLeftNeighbour(target) << std::endl;

				if (validScore(DartBoard::getLeftNeighbour(target), gamemode, 's')) {
					score -= DartBoard::getLeftNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentLeftSingleTRE++;
				break;
			case 5:
			case 6: //hit top/bot single neighbour. 2/8 chance sinde treble segments are surrounded by single segments
				std::cout << "Missed double target, hit straight single neighbour " << target << std::endl;

				if (validScore(target, gamemode, 's')) {
					score -= target;
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentStraightSingleTRE++;
				break;
			case 7:
			case 8: //hit top/bot right single neighbour. 2/8 chance sinde treble segments are surrounded by single segments
				std::cout << "Missed double target, hit right single neighbour " << DartBoard::getRightNeighbour(target) << std::endl;

				if (validScore(DartBoard::getRightNeighbour(target), gamemode, 's')) {
					score -= DartBoard::getRightNeighbour(target);
					std::cout << name << " score now: " << score << std::endl;
				}
				else {
					std::cout << "Invalid score" << std::endl;

				}
				wentRightSingleTRE++;
				break;
			default:
				std::cout << "ERROR IN SWITCH AT THROW TREBLE" << std::endl;
				break;
			}
		}
		throwsTRE++;
		std::cout << "==================================================================" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "You cannot throw for double in 301. Nice try!" << std::endl;
	}
}

//Strategy
void Players::strategy() {
	//std::cout << "STRATEGY" << std::endl;
	int difference = score - 50;

	if (score >= 140) { //if the score is over 140 throws for treble since treble is worth the most
		throwDart(20, 501, 't');
	}

	else if (isAhead == false && score <= 107 && score >= 61 && ((difference <= 60 && difference % 3 == 0) || (difference <= 40 && difference % 2 == 0))) { //Goes for a risky throw if the player is not ahead, and score is between 107 and 61 where the score - 50(difference) is <= 40 and dividable by 2 or <= 60 and dividable bt 3. if it passes checks throws a double or a treble which will allow it to get to 50 in one throw
		if (difference % 3 == 0) { //Checks if the score - 50 leaves a remainder. If it does not it runs
			int target = difference / 3;
			throwDart(target, 501, 't');
		}
		else if (difference % 2 == 0) { //Checks if the score - 50 leaves a remainder. If it does not it runs
			int target = difference / 2;
			throwDart(target, 501, 'd');
		}
		else {
			//std::cout << name << " Error in strategy. %checks" << std::endl;
		}
	}
	else if (score == 99 || (score <= 139 && score >= 101)) {
		for (int i = 0; i <= 39; i++) { //Loops until it finds a value from the array that is the same as the score in the threeDart array
			if (threeDart[1][i] == score) { //Runs if the value from the array is the same as the score
				int target = threeDart[0][i];
				if (target == 25) { //If the value for the target in the array is 25. Throw for outerbull, cause you throw a score of 25 using a treble
					throwDart(target, 501, 'b');
					break;
				}
				else {
					throwDart(target, 501, 't');
					break;
				}
			}
		}
	}
	else if (score == 100 || (score <= 98 && score >= 61)) {
		for (int i = 0; i <= 38; i++) { //Loops until it finds a value from the array that is the same as the score in the threeDart array
			if (twoDart[1][i] == score) { //Runs if the value from the array is the same as the score
				int target = twoDart[0][i];
				throwDart(target, 501, 't');
				break;
			}
		}
	}
	else if (score <= 60 && score >= 51) { //If not ahead tries to make the score 50 so a throw for bull will win. If ahead goes for a normal double finish
		if (isAhead == true) { 
			//std::cout << "Is ahead so go for double finish" << std::endl;
			throwDart(score - 40, 501, 's');
		}
		else {
			//std::cout << "Is not ahead so go for bull finish" << std::endl;
			throwDart(score - 50, 501, 's');
		}
			
	}
	else if (score == 50) { 
		throwDart(50, 501, 'b');
	}
	else if (score >= 41 && score <= 49) { //Gets the odd number to even
		throwDart(score - 40, 501, 's');
	}
	else if (score % 2 == 0 && score <= 40) { //Trows double to win
		//std::cout << "SCORE IS EVEN!!!" << std::endl;
		for (int i = 0; i <= 19; i++) {
			if (oneDart[1][i] == score) {
				//std::cout << "Score is " << score << " which can be won with double" << std::endl;
				//std::cout << "Element found at index " << i << std::endl;
				//std::cout << oneDart[0][i] << std::endl;
				//std::cout << std::endl;
				int target = oneDart[0][i];
				throwDart(target, 501, 'd');
				break;
			}
		}
	}
	else {
		//std::cout << "SCORE IS NOT EVEN!!!" << std::endl;
		throwDart(1, 501, 's');
	}
}


//Validation functions
void Players::averageCalculate(int gamemode)
{
	////301 Stats
	if (gamemode == 301) { //Displays stats for 301 if gamemode is 301
		if (infoPercentages == true) {
			float averageHitTarget = (float(hitTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " hit target he was aiming for during his throw single in " << averageHitTarget << " % of throws." << std::endl; //Displays message
			float averageLeftTarget = (float(wentLeftTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left neighbour during his throw single in " << averageLeftTarget << " % of throws." << std::endl; //Displays message
			float averageRightTarget = (float(wentRightTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right neighbour during his throw single in " << averageRightTarget << " % of throws." << std::endl; //Displays message

			float averageInnerBull = (float(innerBullseyesIN) / float(innerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " hit inner bullseye during his innerbull throw in " << averageInnerBull << " % of throws." << std::endl; //Displays message
			float averageMissedBullseyes = (float(missedBullseyesIN) / float(innerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " missed bullseye and hit a random number during his innerbull throw in " << averageMissedBullseyes << " % of throws." << std::endl; //Displays message

			float total = averageHitTarget + averageLeftTarget + averageRightTarget;
			std::cout << "In total " << total << " % of single throws." << std::endl; //Displays message
			std::cout << name << " made " << throwsSIN << " single throws." << std::endl;
			float totalBull = averageInnerBull + averageMissedBullseyes;
			std::cout << "In total " << totalBull << " % of innerbull throws." << std::endl; //Displays message
			std::cout << name << " made " << innerBullseyeThrows << " innerbull throws." << std::endl;
		}
		std::cout << name << " had " << winCount << " wins" << std::endl; //Displays message
		std::cout << std::endl;
	}
	else if (gamemode == 501) { //Displays stats for 501 if gamemode is 301
		if (infoPercentages == true) {
			//Single STATS
			float averageHitTargetSIN = (float(hitTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " hit target he was aiming for during his throw single in " << averageHitTargetSIN << " % of throws." << std::endl; //Displays message
			float averageLeftTargetSIN = (float(wentLeftTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left neighbour during his throw single in " << averageLeftTargetSIN << " % of throws." << std::endl; //Displays message
			float averageRightTargetSIN = (float(wentRightTargetSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right neighbour during his throw single in " << averageRightTargetSIN << " % of throws." << std::endl; //Displays message

			float averageWentLeftDoubleSIN = (float(wentLeftDoubleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left double neighbour during his throw single in " << averageWentLeftDoubleSIN << " % of throws." << std::endl; //Displays message
			float averageWentStraightDoubleSIN = (float(wentStraightDoubleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit straight double neighbour during his throw single in " << averageWentStraightDoubleSIN << " % of throws." << std::endl; //Displays message
			float averageWentRightDoubleSIN = (float(wentRightDoubleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right double neighbour during his throw single in " << averageWentRightDoubleSIN << " % of throws." << std::endl; //Displays message

			float averageWentLeftTrebleSIN = (float(wentLeftTrebleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left treble neighbour during his throw single in " << averageWentLeftTrebleSIN << " % of throws." << std::endl; //Displays message
			float averageWentStraightTrebleSIN = (float(wentStraightTrebleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit straight treble neighbour during his throw single in " << averageWentStraightTrebleSIN << " % of throws." << std::endl; //Displays message
			float averageWentRightTrebleSIN = (float(wentRightTrebleSIN) / float(throwsSIN)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right treble neighbour during his throw single in " << averageWentRightTrebleSIN << " % of throws." << std::endl; //Displays message

			float totalSingle = averageHitTargetSIN + averageLeftTargetSIN + averageRightTargetSIN + averageWentLeftDoubleSIN + averageWentStraightDoubleSIN + averageWentRightDoubleSIN + averageWentLeftTrebleSIN + averageWentStraightTrebleSIN + averageWentRightTrebleSIN;
			std::cout << "In total " << totalSingle << " % of single throws." << std::endl; //Displays message
			std::cout << name << " made " << throwsSIN << " single throws."<< std::endl;
			std::cout << std::endl;

			//Double STATS
			float averageHitTargetDOU = (float(hitTargetDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " hit target he was aiming for during his throw double in " << averageHitTargetDOU << " % of throws." << std::endl; //Displays message
			float averageLeftTargetDOU = (float(wentLeftTargetDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left neighbour during his throw double in " << averageLeftTargetDOU << " % of throws." << std::endl; //Displays message
			float averageRightTargetDOU = (float(wentRightTargetDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right neighbour during his throw double in " << averageRightTargetDOU << " % of throws." << std::endl; //Displays message

			float averageWentLeftSingleDOU = (float(wentLeftSingleDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left single neighbour during his throw double in " << averageWentLeftSingleDOU << " % of throws." << std::endl; //Displays message
			float averageWentStraightSingleDOU = (float(wentStraightSingleDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit straight single neighbour during his throw double in " << averageWentStraightSingleDOU << " % of throws." << std::endl; //Displays message
			float averageWentRightSingleDOU = (float(wentRightSingleDOU) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right single neighbour during his throw double in " << averageWentRightSingleDOU << " % of throws." << std::endl; //Displays message

			float averageMissedDOU = (float(missed) / float(throwsDOU)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for in " << averageMissedDOU << " % of throws." << std::endl; //Displays message

			float totalDouble = averageHitTargetDOU + averageLeftTargetDOU + averageRightTargetDOU + averageWentLeftSingleDOU + averageWentStraightSingleDOU + averageWentRightSingleDOU + averageMissedDOU;
			std::cout << "In total " << totalDouble << " % of double throws." << std::endl; //Displays message
			std::cout << name << " made " << throwsDOU << " double throws." << std::endl;
			std::cout << std::endl;

			//Treble STATS
			float averageHitTargetTRE = (float(hitTargetTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " hit target he was aiming for during his throw double in " << averageHitTargetTRE << " % of throws." << std::endl; //Displays message
			float averageLeftTargetTRE = (float(wentLeftTargetTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left neighbour during his throw treble in " << averageLeftTargetTRE << " % of throws." << std::endl; //Displays message
			float averageRightTargetTRE = (float(wentRightTargetTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right neighbour during his throw treble in " << averageRightTargetTRE << " % of throws." << std::endl; //Displays message

			float averageWentLeftSingleTRE = (float(wentLeftSingleTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit left single neighbour during his throw treble in " << averageWentLeftSingleTRE << " % of throws." << std::endl; //Displays message
			float averageWentStraightSingleTRE = (float(wentStraightSingleTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit straight single neighbour during his throw treble in " << averageWentStraightSingleTRE << " % of throws." << std::endl; //Displays message
			float averageWentRightSingleTRE = (float(wentRightSingleTRE) / float(throwsTRE)) * 100;
			std::cout << "On average " << name << " missed target he was aiming for and hit right single neighbour during his throw treble in " << averageWentRightSingleTRE << " % of throws." << std::endl; //Displays message

			float totalTreble = averageHitTargetTRE + averageLeftTargetTRE + averageRightTargetTRE + averageWentLeftSingleTRE + averageWentStraightSingleTRE + averageWentRightSingleTRE;
			std::cout << "In total " << totalTreble << " % of treble throws." << std::endl; //Displays message
			std::cout << name << " made " << throwsTRE << " treble throws." << std::endl;
			std::cout << std::endl;

			//Innerbull STATS
			float averageInnerBullIN = (float(innerBullseyesIN) / float(innerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " hit inner bullseye during his innerbull throw in " << averageInnerBullIN << " % of throws." << std::endl; //Displays message
			float averageOuterBullIN = (float(outerBullseyesIN) / float(innerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " hit outer bullseye during his innerbull throw in " << averageOuterBullIN << " % of throws." << std::endl; //Displays message
			float averageMissedBullseyesIN = (float(missedBullseyesIN) / float(innerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " missed bullseye and hit a random number during his innerbull throw in " << averageMissedBullseyesIN << " % of throws." << std::endl; //Displays message

			float totalInner = averageInnerBullIN + averageOuterBullIN + averageMissedBullseyesIN;
			std::cout << "In total " << totalInner << " % of innerbull throws." << std::endl; //Displays message
			std::cout << name << " made " << innerBullseyeThrows << " innerbull throws." << std::endl;
			std::cout << std::endl;

			//Outerbull STATS
			float averageInnerBullOUT = (float(innerBullseyesOUT) / float(outerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " hit inner bullseye during his outerbull throw in " << averageInnerBullOUT << " % of throws." << std::endl; //Displays message
			float averageOuterBullOUT = (float(outerBullseyesOUT) / float(outerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " hit outer bullseye during his outerbull throw in " << averageOuterBullOUT << " % of throws." << std::endl; //Displays message
			float averageMissedBullseyesOUT = (float(missedBullseyesOUT) / float(outerBullseyeThrows)) * 100;
			std::cout << "On average " << name << " missed bullseye and hit a random number during his outerbull throw in " << averageMissedBullseyesOUT << " % of throws." << std::endl; //Displays message

			float totalOuter = averageInnerBullOUT + averageOuterBullOUT + averageMissedBullseyesOUT;
			std::cout << "In total " << totalOuter << " % of outerbull throws." << std::endl; //Displays message
			std::cout << name << " made " << outerBullseyeThrows << " outerbull throws." << std::endl;
			std::cout << std::endl;
			std::cout << "=======================================================================================================================" << std::endl;
		}
	}
	

	//float averageBull = (float(innerBullseyes) / float(innerBullseyeThrows)) * 100;
	//std::cout << "On average " << name << " hit inner bullseye in " << averageBull << " % of throws." << std::endl; //Displays message
	//float averageStraightSingle = (float(hitTarget) / float(throws)) * 100;
	//std::cout << "On average " << name << " went straight single in " << averageStraightSingle << " % of throws." << std::endl; //Displays message
	//float averageWentLeft = (float(wentLeftTarget) / float(throws)) * 100;
	//std::cout << "On average " << name << " went left in " << averageWentLeft << " % of throws." << std::endl; //Displays message
	//float averageWentRight = (float(wentRightTarget) / float(throws)) * 100;
	//std::cout << "On average " << name << " went right in " << averageWentRight << " % of throws." << std::endl; //Displays message
	//float averageMissedBullseyes = (float(missedBullseyes) / float(throws)) * 100;
 	//std::cout << "On average " << name << " missed bullseye in " << averageMissedBullseyes << " % of throws." << std::endl; //Displays message
	//float total = averageStraightSingle + averageWentLeft + averageWentRight;
	//std::cout << "In total " << total << " % of throws." << std::endl; //Displays message
	//std::cout << "Had " << error << " errors" << std::endl;
	//std::cout << std::endl;

	Players::resetStats(); //Resets stats so if user back out of stats and play a new one they start anew
}

bool Players::checkWinner()
{
	if (score == 0) {
		//std::cout << name << " has reached score 0 and has won" << std::endl;
		return true;
	}
	else {
		//std::cout << name << " has not yet reached score 0" << std::endl;
		return false;
	}
}

bool Players::validScore(int target, int gamemode, char throwType) {
	int total = score - target; //The score after hitting target
	if (gamemode == 301) { //in 301 it checks if the score after target will be over 50 or 0
		if (total >= 50 || total == 0) {
			//std::cout << "Passes score checks." << std::endl;
			return true;
		}
		else {
			std::cout << "Fails score checks" << std::endl;
			return false;
		}
	}
	else if (gamemode == 501) { //In 501 it checks if the score after hitting target will be bigger then 1 and either be achieved by a double throw or a bull
		if (total > 1) {
			//std::cout << "Passes score checks. Can win with double" << std::endl;
			return true;

		}
		else if (target == 50 && total == 0) {
			//std::cout << "Passes score checks. Can win with bullseye" << std::endl;
			return true;
		}
		else if (throwType == 'd' && total == 0) {
			//std::cout << "Passes score checks. Can win with double" << std::endl;
			return true;
		}
		else if (total <= 1) {
			std::cout << name << "Is BUST" << std::endl;
			score = tempScore;
			return false;
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
	else {
		std::cout << "Error in valid score if else gamemode check" << std::endl;
		return false;
	}
}

void Players::resetStats() {
	//Innerbull
	innerBullseyesIN = 0;
	outerBullseyesIN = 0;
	missedBullseyesIN = 0;
	innerBullseyeThrows = 0;
	//Outerbull
	outerBullseyesOUT = 0;
	innerBullseyesOUT = 0;
	missedBullseyesOUT = 0;
	outerBullseyeThrows = 0;
	//Single
	hitTargetSIN = 0;
	wentLeftTargetSIN = 0;
	wentRightTargetSIN = 0;
	wentLeftDoubleSIN = 0;
	wentStraightDoubleSIN = 0;
	wentRightDoubleSIN = 0;
	wentLeftTrebleSIN = 0;
	wentStraightTrebleSIN = 0;
	wentRightTrebleSIN = 0;
	throwsSIN = 0;
	//Double
	hitTargetDOU = 0;
	wentLeftTargetDOU = 0;
	wentRightTargetDOU = 0;
	missed = 0;
	wentLeftSingleDOU = 0;
	wentStraightSingleDOU = 0;
	wentRightSingleDOU = 0;
	throwsDOU = 0;
	//Treble
	hitTargetTRE = 0;
	wentLeftTargetTRE = 0;
	wentRightTargetTRE = 0;
	wentLeftSingleTRE = 0;
	wentStraightSingleTRE = 0;
	wentRightSingleTRE = 0;
	throwsTRE = 0;
	winCount = 0;

	//Championships
	championshipsWon = 0;
}

//Increment functions
void Players::wonSet() {
	setsWon++;
}

void Players::wonRound() {
	winCount++;
}

void Players::wonChampionship() {
	championshipsWon++;
}
