#include "Player.h"
#include "sstream"

Player::Player() {
	playerName = "Charlie";
}

Player::Player(string pName) {
	playerName = pName;
	resetInitialStats();
}

Player::~Player() {

}

string Player::getName() {
	return playerName;
}

short Player::getScore() {
	return playerScore;
}

string Player::getStats() {
	stringstream playerStats;
	playerStats << "   Cases:    " << cases << endl;
	playerStats << "   Solved:   " << solvedCase << endl;
	playerStats << "   Points:   " << point << endl;
	playerStats << "   Total:    " << totalScore << endl;
	playerStats << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	return playerStats.str();
}

void Player::resetScore(int newPoint, int newSolvedCase, int newCases, int newTotalScore) {
	point = newPoint;
	solvedCase = newSolvedCase;
	cases = newCases;
	totalScore = newTotalScore;
}


void Player::updateScore(int& newPoint, int& newSolvedCase, int& newCases, int& newTotalScore) {
	point = newPoint;
	solvedCase = newSolvedCase + solvedCase;
	cases = newCases + cases;
	totalScore = newTotalScore + totalScore;
}

void Player::resetInitialStats() {
	point = 0;
	solvedCase = 0;
	cases = 0;
	totalScore = 0;
};
