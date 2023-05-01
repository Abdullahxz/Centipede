/*
 * ScoreBoard.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
	score=0;
	numberOfLives=1;
}

int ScoreBoard::getNumberOfLives() const {
	return numberOfLives;
}

void ScoreBoard::setNumberOfLives(int numberOfLives) {
	this->numberOfLives = numberOfLives;
}

int ScoreBoard::getScore() const {
	return score;
}

void ScoreBoard::setScore(int score) {
	this->score = score;
}

ScoreBoard::~ScoreBoard() {

}
