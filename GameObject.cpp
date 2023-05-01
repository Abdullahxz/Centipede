/*
 * GameObject.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "GameObject.h"

Position GameObject::getPos() const {
	return pos;
}

void GameObject::setPos(int X,int Y) {
	pos.setX(X);
	pos.setY(Y);
}

 ScoreBoard GameObject::getScoreB() const {
	 return scoreB;
}

 void GameObject::setScoreB(ScoreBoard scoreB) {
	this->scoreB = scoreB;
}

bool GameObject::isStart() const {
	return start;
}

void GameObject::setStart(bool start) {
	this->start = start;
}

void GameObject::setPos(Position pos) {
	this->pos = pos;
}

void GameObject::setScoreBscore(int scr) {
	scoreB.setScore(scr);
}
int GameObject::getScoreBscore() const {
	return scoreB.getScore();
}
void GameObject::setScoreBnoOfLives(int scr) {
	scoreB.setNumberOfLives(scr);
}
int GameObject::getScoreBnoOfLives() const {
	return scoreB.getNumberOfLives();
}
GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

