#include "GameBoard.h"
#include "sstream"

GameBoard::GameBoard() {
	caseLevel = Detective;
	gameMode = Numbers;

}

GameBoard::GameBoard(CaseLevel gLevel, GameMode gMode) {
	caseLevel = gLevel;
	gameMode = gMode;
}

GameBoard::~GameBoard() {

}

CaseLevel GameBoard::getCaseNum() {
	return caseLevel;
}

GameMode  GameBoard::getModeNum() {
	return gameMode;
}

string GameBoard::getCaseLevel() {
	switch (caseLevel) {
	case Detective:
		return "Detective";
	case Inspector:
		return "Inspector";
	case ChiefInspector:
		return "Chief Inspector";
	default:
		return "Oops - no assigned level";
	}
}


string GameBoard::getGameMode() {
	switch (gameMode) {
	case Numbers:
		return "Numbers";
	case Symbols:
		return "Symbols";
	case Words:
		return "Words";
	default:
		return "Oops - no assigned mode";
	}
}


void GameBoard::displayGame(short matchedPosition, short matchedCode) {

}

string GameBoard::drawBoxes(int noOfBox, string matchingPos, string matchingCode, string Code) {
	stringstream sBoxes;
	string boxTop = "";
	string boxMid = "";
	string boxBot = "";
	string pos = "";
	string code = "";
	string indexCode;

	for (int i = 0; i < noOfBox; i++) {
		indexCode = Code[i];
		boxTop += " .---. ";
		boxMid += " | " + indexCode + " | ";
		boxBot += " .___. ";
	}
	pos += matchingPos;
	code += matchingCode;

	if (noOfBox == 4) {
		sBoxes << "|" << boxTop << "                                                   |" << endl;
		if (pos.length() == 13) {
			sBoxes << "|" << boxMid << code << pos << "                                      |";
		}
		else if (pos.length() + code.length() == 0) {
			sBoxes << "|" << boxMid << code << pos << "                                                   |";
		}
		else if (pos.length() + code.length() == 2) {
			sBoxes << "|" << boxMid << code << pos << "                                                 |";
		}
		else if (pos.length() + code.length() == 4) {
			sBoxes << "|" << boxMid << code << pos << "                                               |";
		}
		else if (pos.length() + code.length() == 6) {
			sBoxes << "|" << boxMid << code << pos << "                                             |";
		}
		else if (pos.length() + code.length() == 8) {
			sBoxes << "|" << boxMid << code << pos << "                                           |";
		}
		sBoxes << endl;
		sBoxes << "|" << boxBot << "                                                   |";
	}
	else if (noOfBox == 5) {
		sBoxes << "|" << boxTop << "                                            |" << endl;
		if (pos.length() == 13) {
			sBoxes << "|" << boxMid << code << pos << "                               |";
		}
		else if (pos.length() + code.length() == 0) {
			sBoxes << "|" << boxMid << code << pos << "                                            |";
		}
		else if (pos.length() + code.length() == 2) {
			sBoxes << "|" << boxMid << code << pos << "                                          |";
		}
		else if (pos.length() + code.length() == 4) {
			sBoxes << "|" << boxMid << code << pos << "                                        |";
		}
		else if (pos.length() + code.length() == 6) {
			sBoxes << "|" << boxMid << code << pos << "                                      |";
		}
		else if (pos.length() + code.length() == 8) {
			sBoxes << "|" << boxMid << code << pos << "                                    |";
		}
		else if (pos.length() + code.length() == 10) {
			sBoxes << "|" << boxMid << code << pos << "                                  |";
		}
		sBoxes << endl;
		sBoxes << "|" << boxBot << "                                            |";
	}
	else {
		sBoxes << "|" << boxTop << "                                     |" << endl;
		if (pos.length() == 13) {
			sBoxes << "|" << boxMid << code << pos << "                        |";
		}
		else if (pos.length() + code.length() == 0) {
			sBoxes << "|" << boxMid << code << pos << "                                     |";
		}
		else if (pos.length() + code.length() == 2) {
			sBoxes << "|" << boxMid << code << pos << "                                   |";
		}
		else if (pos.length() + code.length() == 4) {
			sBoxes << "|" << boxMid << code << pos << "                                 |";
		}
		else if (pos.length() + code.length() == 6) {
			sBoxes << "|" << boxMid << code << pos << "                               |";
		}
		else if (pos.length() + code.length() == 8) {
			sBoxes << "|" << boxMid << code << pos << "                             |";
		}
		else if (pos.length() + code.length() == 10) {
			sBoxes << "|" << boxMid << code << pos << "                           |";
		}
		else if (pos.length() + code.length() == 12) {
			sBoxes << "|" << boxMid << code << pos << "                         |";
		}
		sBoxes << endl;
		sBoxes << "|" << boxBot << "                                     |";
	}
	return sBoxes.str();
}





