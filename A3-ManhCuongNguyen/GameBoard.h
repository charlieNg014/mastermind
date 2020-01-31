/***********************************************************
Project: Assignment 3 - FIT1048 - MasterMind Game
Tutor: Avi
Author: Manh Cuong Nguyen
Purpose: apply knowledge in C++ OOP to create C++
gameBoard header file including all variables and functions.
***********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Enum.h"
using namespace std;


#ifndef GameBoard_h
#define GameBoard_h

class GameBoard {
private:
	CaseLevel caseLevel;
	GameMode gameMode;
	string instantCode;
	string hiddenCode;

public:
	//constructors
	GameBoard();
	GameBoard(CaseLevel gLevel, GameMode gMode);

	//destructors
	~GameBoard();


	//accessor methods
	string getCaseLevel();
	string getGameMode();
	CaseLevel getCaseNum();
	GameMode getModeNum();

	//mutator methods
	void displayGame(short matchedPosition, short matchedCode);
	string drawBoxes(int noOfBox, string matchingPos, string matchingCode, string Code);
};

#endif //GameBoard_h

