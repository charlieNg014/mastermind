/***********************************************************
Project: Assignment 3 - FIT1048 - MasterMind Game
Tutor: Avi
Author: Manh Cuong Nguyen
Purpose: apply knowledge in C++ OOP to create C++
mainApplication header file including all variables and
functions.
***********************************************************/

#include <iostream>
#include <string>
#include "Player.h"
#include "GameBoard.h"
#include <vector>
using namespace std;

#ifndef MainApplication_h
#define MainApplication_h
//players: vector<player>
//gameBoard: vector<gameBoard>

Player player1;
GameBoard testGame;
vector<Player>gamePlayers;
vector<GameBoard>gameBoards;
string askedName;
string sourceWord;
string wordList;
string secretCode;
string enteredCode;
string quitGame;
int askedLevel;
int askedMode;
int instantPoint;
int inGameScore;
int noOfRows = 0;
int matchedPosition = 0;
int matchedCode = 0;
int box;
int hintCount = 0;
int gameWin = 0;
int gameLost = 0;

void displayRules(string fileName);
void createPlayer(Player newPlayer, GameBoard newGame);
void addPlayer(Player newPlayer);
void addGameBoard(GameBoard newGameBoard);
void gameOver(Player newPlayer, GameBoard newGame);
void getHint();
void getHelp();
string askingForName();
string generateSecretCode(int requestedLevel, int requestedMode);
string resetCode();
string getWordList(string fileName, int requestedLine);
int checkMatchingCode(string userCode, string computerCode);
int checkMatchingPosition(string userCode, string computerCode);
int askingForCaseLevel();
int askingForGameMode();
bool checkGameOver();
char askForLetter(string question);

#endif //MainApplication_h




