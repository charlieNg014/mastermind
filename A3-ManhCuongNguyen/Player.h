/***********************************************************
Project: Assignment 3 - FIT1048 - MasterMind Game
Tutor: Avi
Author: Manh Cuong Nguyen
Purpose: apply knowledge in C++ OOP to create C++ player
header file including all variables and functions.
***********************************************************/

#include <iostream>
#include <string>
using namespace std;

#ifndef Player_h
#define Player_h

class Player {
private:
	string playerName;
	string playerChoice;
	string userChoice;
	int playerScore;
	int point = 0;
	int solvedCase = 0;
	int cases = 0;
	int totalScore = 0;

public:


	//constructors
	Player();
	Player(string pName);

	//destructors
	~Player();

	//accessor methods
	string getName();
	short getScore();
	string getStats();

	//mutator methods
	void resetScore(int newPoint, int newSolvedCase, int newCases, int newTotalScore);
	void updateScore(int& newPoint, int& newSolvedCase, int& newCases, int& newTotalScore);
	void resetInitialStats();

};

#endif //Player_h



