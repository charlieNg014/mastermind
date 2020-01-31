/***********************************************************
Project: Assignment 3 - FIT1048 - MasterMind Game
Tutor: Avi
Author: Manh Cuong Nguyen
Purpose: apply knowledge in C++ OOP to create C++ player
header file including all variables and functions.
***********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "MainApplication.h"
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

void initiateGame() {
	//display the rules of the game
	displayRules("gameRules");

	//pause the system to let player reads the rules and clear when they are ready
	system("pause");
	system("cls");

	//invoke function to get details from players
	askingForName();
	askingForCaseLevel();
	askingForGameMode();



}
void playGame(Player newPlayer, GameBoard newGame) {
	//local variables
	string matchedCodeSymbol;
	string matchedPosSymbol;



	//initialise the local variable to check game over
	bool isGameOver = false;

	//decide the number of rows
	if (askedLevel == 0) {
		noOfRows = 10;
	}
	else if (askedLevel == 1) {
		noOfRows = 12;
	}
	else {
		noOfRows = 14;
	}

	//reset secret code
	resetCode();

	//generate a secret code
	generateSecretCode(askedLevel, askedMode);
	//cout << secretCode << endl;

	//display the title
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                          MasterMind :: Code Detective                            " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl << endl;
	//display the initial title of the code
	if (askedLevel == 0) {
		box = 4;
	}
	else if (askedLevel == 1) {
		box = 5;
	}
	else {
		box = 6;
	}
	//display the hidden code without revealing
	cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
	cout << testGame.drawBoxes(box, "  Hidden Code", "", "      ") << endl;
	cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
	cout << "| The code element coule be: ";
	for (int i = 0; i < (int)wordList.length(); i++) {
		cout << wordList.substr(i, 1) << " ";
	}
	if (wordList.length() == 10) {
		cout << "                               |";
	}
	else if (wordList.length() == 14) {
		cout << "                       |";
	}
	else {
		cout << "   |";
	}
	cout << endl;

	//loop the game
	while (!isGameOver) {
		string askRule;
		string askHint;
		//asking player for their code
		cout << "| The code could be:";
		cin >> enteredCode;

		//check if the enter code less than required inputs
		if (enteredCode.length() < 6) {
			enteredCode += "      ";
		}


		//getting the user code but with allowance length
		if (box == 4) {
			enteredCode = enteredCode.substr(0, 4);
			//cout << enteredCode;
		}
		else if (box == 5) {
			enteredCode = enteredCode.substr(0, 5);
			//cout << enteredCode;
		}
		else {
			enteredCode = enteredCode.substr(0, 6);
			//cout << enteredCode;
		}
		//loop to quit the game
		for (int i = 0; i < (int)enteredCode.length(); i++) {
			quitGame = enteredCode.substr(i, 1);
			askRule = enteredCode.substr(i, 1);
			askHint = enteredCode.substr(i, 1);
			if (quitGame == "q" || quitGame == "Q") {
				char askForQuit = askForLetter("Do you want to resign the game? (y/n)");
				if (askForQuit == 'Y') {
					if (box == 4) {
						enteredCode = "    ";
					}
					else if (box == 5) {
						enteredCode = "     ";
					}
					else {
						enteredCode = "      ";
					}
					i = enteredCode.length() + 1;
				}
				else {
					i = enteredCode.length() + 1;
					if (box == 4) {
						enteredCode = "    ";
					}
					else if (box == 5) {
						enteredCode = "     ";
					}
					else {
						enteredCode = "      ";
					}
				}
			}
			else if (askRule == "R" || askRule == "r") {
				getHelp();
			}
			else if (askHint == "H" || askHint == "h") {
				getHint();
			}
		}

		//check if in the entered code has same number
		matchedCode = 0;
		checkMatchingCode(enteredCode, secretCode);
		//cout << matchedCode;

		//check the matching position between two codes
		matchedPosition = 0;
		checkMatchingPosition(enteredCode, secretCode);
		//cout << matchedPosition;

		//decreament the number of Rows after each time plays
		noOfRows--;
		//convert matching code and position into symbols
		matchedCodeSymbol = "";
		for (int i = 0; i < (matchedCode - matchedPosition); i++) {
			matchedCodeSymbol += "? ";
		}

		matchedPosSymbol = "";
		for (int y = 0; y < matchedPosition; y++) {
			matchedPosSymbol += "o ";
		}

		//display the interface
		cout << testGame.drawBoxes(box, matchedCodeSymbol, matchedPosSymbol, enteredCode) << endl;

		//calculate the in-game score
		instantPoint = (matchedCode - matchedPosition) * 1 + matchedPosition * 2;
		if (instantPoint >= inGameScore) {
			inGameScore = instantPoint;
		}
		instantPoint = 0;

		//check game over
		isGameOver = checkGameOver();
	}
	//end the game
	gameOver(newPlayer, newGame);
}


int main() {
	initiateGame();

	//generate an object of player
	Player newPlayer = Player(askedName);

	//generate an object of gameBoard
	GameBoard newGame = GameBoard(CaseLevel(askedLevel), GameMode(askedMode));

	//adding Player
	createPlayer(newPlayer, newGame);

	playGame(newPlayer, newGame);
	return 0;
}


void displayRules(string fileName) {
	string rulesFile;
	ifstream fileToRead;
	fileToRead.open(fileName + ".txt");
	if (fileToRead.is_open()) {
		while (getline(fileToRead, rulesFile)) {
			cout << rulesFile << endl;
		}
		fileToRead.close();
	}
	else {
		cout << fileName << ".txt is not exist. Open file failed" << endl;
	}
}

//getting the name
string askingForName() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"              MasterMind :: Code Detective\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		"Please fill this WD-708a form correctly, ensuring you submit\n"
		"it to the appropriate clerk before proceeding with your first\n"
		"case\n\n"
		"The desk Sergeant is available, if you need assistance\n\n"
		"Please enter your name: ";

	cin >> askedName;
	cout << endl << endl;
	return askedName;
}

//getting case level
int askingForCaseLevel() {
	cout << "Please select a Case Level at which to play.\n"
		"[0] Detective, [1] Inspector, [2] Chief Inspector: ";
	cin >> askedLevel;
	cout << endl << endl;
	return askedLevel;
}

//getting game mode
int askingForGameMode() {
	cout << "Please select a which game mode you wish to play.\n"
		"[0] Numbers, [1] Symbols, [2] Words: ";
	cin >> askedMode;
	cout << endl << endl;
	return askedMode;
}


//add player
void createPlayer(Player newPlayer, GameBoard newGame) {

	cout << "Thanks, " << newGame.getCaseLevel() << " " << newPlayer.getName() << ". Good luck with your cases!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "   Name:     " << newPlayer.getName() << endl;
	cout << "   Rank:     " << newGame.getCaseLevel() << endl;
	cout << newPlayer.getStats() << endl;

	//add new players
	addPlayer(newPlayer);

	//add new gameboard
	addGameBoard(newGame);
}

//add new player to vector player
void addPlayer(Player newPlayer) {
	gamePlayers.push_back(newPlayer);
};

//add the new gameboard to the vector gameboard
void addGameBoard(GameBoard newGameBoard) {
	gameBoards.push_back(newGameBoard);
}

//reset code
string resetCode() {
	secretCode = "";
	return secretCode;
}

string getWordList(string fileName, int requestedLine) {
	//local variables
	string line = "";
	int lineCount = 1;

	ifstream wordListFile;
	wordListFile.open(fileName);
	if (wordListFile.is_open()) {
		while (lineCount < 4) {
			getline(wordListFile, line);
			if (lineCount == requestedLine) {
				wordList = line;
				lineCount = 4;
			}
			lineCount++;
		}
	}
	else {
		cout << "File not found" << endl;
	}
	return wordList;
}

//generate the secret code
string generateSecretCode(int requestedLevel, int requestedMode) {
	//local variables
	string random;
	int noOfColumn = 0;

	//getting the column based on level
	if (askedLevel == 0) {
		noOfColumn = 4;
	}
	else if (askedLevel == 1) {
		noOfColumn = 5;
	}
	else if (askedLevel == 2) {
		noOfColumn = 6;
	}

	//getting the code based on mode
	for (int i = 0; i < noOfColumn; i++) {
		if (askedMode == 0) {
			sourceWord = getWordList("wordList.txt", 1);
			random = sourceWord.substr(rand() % sourceWord.length() + 0, 1);
			secretCode.append(random);
		}
		else if (askedMode == 1) {
			sourceWord = getWordList("wordList.txt", 2);
			random = sourceWord.substr(rand() % sourceWord.length() + 0, 1);
			secretCode.append(random);
		}
		else if (askedMode == 2) {
			sourceWord = getWordList("wordList.txt", 3);
			random = sourceWord.substr(rand() % sourceWord.length() + 0, 1);
			secretCode.append(random);
		}
	}

	return secretCode;
}

//checking the matching code
int checkMatchingCode(string userCode, string computerCode) {
	//local variables
	string newCode;
	string text;

	//adding the first code 
	newCode = userCode[0];

	//get the new code if they have same numbers in code
	//check if the user enter the correct code
	if (userCode.length() > 0) {
		//loop to check the code 
		for (int i = 0; i < (int)userCode.length(); i++) {
			bool flag = true;
			for (int j = 0; j < (int)newCode.length(); j++) {
				//compare the code
				if (userCode[i] == newCode[j]) {
					flag = false;
					j = newCode.length() + 1;
				}
			}
			if (flag) {
				text = userCode[i];
				newCode.append(text);
			}
		}
	}

	//check the matching code
	for (int i = 0; i < (int)newCode.length(); i++) {
		for (int j = 0; j < (int)computerCode.length(); j++) {
			if (newCode[i] == computerCode[j]) {
				matchedCode++;
			}
		}
	}
	return matchedCode;
}

//checking the matching position
int checkMatchingPosition(string userCode, string computerCode) {
	for (int i = 0; i < (int)userCode.length(); i++) {
		if (userCode[i] == computerCode[i]) {
			matchedPosition++;
		}
	}
	return matchedPosition;
}


//get Help for Rules display
void getHelp() {
	displayRules("gameRules");
	enteredCode = "    ";

	//display the title
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                          MasterMind :: Code Detective                            " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl << endl;

	//display the hidden code without revealing
	cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
	cout << testGame.drawBoxes(box, "  Hidden Code", "", "      ") << endl;
	cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
	cout << "| The code element coule be: ";
	for (int i = 0; i < (int)wordList.length(); i++) {
		cout << wordList.substr(i, 1) << " ";
	}
	if (wordList.length() == 10) {
		cout << "                               |";
	}
	else if (wordList.length() == 14) {
		cout << "                       |";
	}
	else {
		cout << "   |";
	}
	cout << endl;
}

//get Hint
void getHint() {
	if (box == 4) {
		enteredCode = "    ";
	}
	else if (box == 5) {
		enteredCode = "     ";
	}
	else {
		enteredCode = "      ";
	}
	hintCount++;
	if (hintCount <= 3) {
		cout << "| One of hidden code is: " << secretCode.substr(rand() % (secretCode.length()) + 0, 1) << "                                                      |" << endl;
	}
	else {
		cout << "| You are running out of getting hints!                                         |" << endl;
	}
}

bool checkGameOver() {
	if (quitGame == "q" || quitGame == "Q" || noOfRows == 0 || (matchedPosition == 4 && box == 4) || (matchedPosition == 5 && box == 5) || (matchedPosition == 6 && box == 6)) {
		return true;
	}
	else {
		return false;
	}
}

char askForLetter(string question) {
	char choice = ' ';
	while (choice == ' ') {
		cout << endl << question;
		cin >> choice;
	}
	return toupper(choice);
}

void gameOver(Player newPlayer, GameBoard newGame) {
	//local variables
	int instantCase;
	int instantSolvedCase;
	//int instantTotalScore;

	//reset all the instant scores
	instantCase = 0;
	instantSolvedCase = 0;

	if ((matchedPosition == 4) || (matchedPosition == 5) || (matchedPosition == 6)) {
		cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl << endl;
		cout << "Congratulation " << newPlayer.getName() << ", you have solved the case !" << endl << endl;

		//update the score in the game
		instantCase++;
		instantSolvedCase++;
		inGameScore = inGameScore + noOfRows * 2;

		//update score to player
		player1.updateScore(inGameScore, instantSolvedCase, instantCase, inGameScore);

		//display Score
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "   Name:     " << newPlayer.getName() << endl;
		cout << "   Rank:     " << newGame.getCaseLevel() << endl;
		cout << player1.getStats() << endl;

		//checking the number of wins (equal to 5)
		gameWin++;
		if (gameWin == 5) {
			cout << "You won " << gameWin;
			gameWin = 0;

			char upLevel = askForLetter("Do you want to promote upper level?  (y/n)");
			if (upLevel == 'Y') {
				//increase the level
				if (askedLevel == 0) {
					askedLevel = 1;
				}
				else if (askedLevel == 1) {
					askedLevel = 2;
				}
			}
		}

	}
	else if (noOfRows == 0 || quitGame == "q") {
		cout << ".~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl << endl;
		cout << "You have lost the game. Good luck next time, " << newPlayer.getName() << "!" << endl;
		cout << endl;

		//update the score in the game
		instantCase++;

		//update score to player
		player1.updateScore(inGameScore, instantSolvedCase, instantCase, inGameScore);

		//display score
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "   Name:     " << newPlayer.getName() << endl;
		cout << "   Rank:     " << newGame.getCaseLevel() << endl;
		cout << player1.getStats() << endl;

		//check the number of lost (equal to 5)
		gameLost++;
		if (gameLost == 5) {
			cout << "You lost " << gameLost;
			gameLost = 0;
			//increase the level
			if (askedLevel == 3) {
				askedLevel = 2;
			}
			else if (askedLevel == 1) {
				askedLevel = 0;
			}
		}
	}
	char answer = askForLetter("Are you ready for next case? (y/n): ");
	if (answer == 'Y') {
		hintCount = 0;
		playGame(newPlayer, newGame);
	}
	else {
		cout << "Thanks for playing,  " << newPlayer.getName() << "!" << endl;
		system("pause");
	}
}






