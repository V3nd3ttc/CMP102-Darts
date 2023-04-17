#pragma once

#include "DartBoard.h"
#include <string>



class Players
{
private:
	//Arrays
	int oneDart[2][20] =
	{
		
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, //Row 1 Score
		{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40} //Row 2 Target
	};

	int twoDart[2][39] =
	{
		{15, 10, 13, 16, 19, 10, 17, 20, 15, 10, 13, 16, 19, 14, 17, 20, 19, 18, 19, 20, 19, 14, 17, 20, 15, 18, 17, 16, 19, 20, 17, 20, 19, 18, 19, 20, 19, 20, 20 }, //Row 1 Target
		{61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 100} //Row 2 Score
		
	};

	int threeDart[2][40] =
	{
		{19, 20, 20, 20, 18, 19, 20, 19, 20, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 19, 20, 17, 18, 19, 20, 25, 19, 20, 18, 19, 20, 20, 20, 20, 20, 20, 20, 19, 20, 19}, //Row 1 Target
		{99, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139} //Row 2 Score
	};

	


	std::string name;
	//Chances  variables
	int innerbull_chance = 80;
	int outerbull_chance = 80;
	int hit_chance = 80; //Single chance
	int double_chance = 80;
	int treble_chance = 80;


	//Stats variables
	int	winCount = 0;
	int setsWon = 0;
	int championshipsWon = 0;
	int	score = 0;
	int tempScore = 0;

	//Information variables
	bool infoThrows = false;
	bool infoPercentages = false;
	bool isAhead = false;

	

	//Stats variables
	//Innerbull
	int innerBullseyesIN = 0;
	int	outerBullseyesIN = 0;
	int	missedBullseyesIN = 0;
	int	innerBullseyeThrows = 0;
	//Outerbull
	int outerBullseyesOUT = 0;
	int	innerBullseyesOUT = 0;
	int	missedBullseyesOUT = 0;
	int	outerBullseyeThrows = 0;
	//Single
	int hitTargetSIN = 0;
	int	wentLeftTargetSIN = 0;
	int	wentRightTargetSIN = 0;
	int	wentLeftDoubleSIN = 0;
	int	wentStraightDoubleSIN = 0;
	int	wentRightDoubleSIN = 0;
	int	wentLeftTrebleSIN = 0;
	int	wentStraightTrebleSIN = 0;
	int	wentRightTrebleSIN = 0;
	int	throwsSIN = 0;
	//Double
	int hitTargetDOU = 0;
	int	wentLeftTargetDOU = 0;
	int	wentRightTargetDOU = 0;
	int	missed = 0;
	int	wentLeftSingleDOU = 0;
	int	wentStraightSingleDOU = 0;
	int	wentRightSingleDOU = 0;
	int	throwsDOU = 0;
	//Treble
	int hitTargetTRE = 0;
	int	wentLeftTargetTRE = 0;
	int	wentRightTargetTRE = 0;
	int	wentLeftSingleTRE = 0;
	int	wentStraightSingleTRE = 0;
	int	wentRightSingleTRE = 0;
	int	throwsTRE = 0;

public:
	Players(std::string, int);
	Players();
	~Players();

	////Getters
	std::string getName();
	//Chance getters
	int getInnerbullChance();
	int getOuterbullChance();
	int getHitChance();
	int getDoubleChance();
	int getTrebleChance();
	//Stats getters
	int getWinCount();
	int getSetsWon();
	int getChampionshipsWon();
	//Score getters
	int getScore();
	int getTempScore();
	//Info getters
	bool getInfoThrows();
	bool getInfoPercentages();
	bool getIsAhead();
	
	///Setters
	void setName(std::string);
	//Chance setters
	void setInnerbullChance(int);
	void setOuterbullChance(int);
	void setHitChance(int);
	void setDoubleChance(int);
	void setTrebleChance(int);
	//Stats setters
	void setWinCount(int);
	void setSetsWon(int);
	void setChampionshipsWon(int);
	//Score setters
	void setScore(int);
	void setTempScore(int);
	//Info setters
	void setInfoThrows(bool);
	void setInfoPercentages(bool);
	void setIsAhead(bool);
	
	


	////Functions
	//Throws
	void throwDart(int, int, char);
	void throwInnerBull(int);
	void throwOuterBull(int);
	void throwSingle(int, int);
	void throwDouble(int, int);
	void throwTreble(int, int);
	//Strategy
	void strategy();

	//Validation
	bool validScore(int, int, char);
	void averageCalculate(int);
	bool checkWinner();
	void resetStats();

	//Increment functions
	void wonSet();
	void wonRound();
	void wonChampionship();

	

};
