/*
 * Position.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "Position.h"

Position::Position() {
	x=0;
	y=0;
}


Position::Position(int X,int Y) {
	x=X;
	y=Y;
}

int Position::getX() const {
	return x;
}

void Position::setX(int x) {
	this->x = x;
}

int Position::getY() const {
	return y;
}

void Position::setY(int y) {
	this->y = y;
}
Position::~Position() {
	// TODO Auto-generated destructor stub
}

