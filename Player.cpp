/*
 * Player.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "Player.h"


Player::Player():PDirection(0) {
	setPos(510,5);
}
void Player::Draw() {
//	DrawSquare( pos.getX()+4, pos.getY()+14, 7,colors[PINK]);
//	DrawSquare( pos.getX() , pos.getY() ,15,colors[RED]);
	DrawTriangle(pos.getX(),pos.getY(),pos.getX()+10,pos.getY()+20,pos.getX()+10,pos.getY(),colors[RED]);
	DrawTriangle(pos.getX()+15,pos.getY(),pos.getX()+15,pos.getY()+20,pos.getX()+25,pos.getY(),colors[RED]);
}
void Player::Collision() {

}
void Player::Move() {
	if (pos.getX()<0)
	{
		pos.setX(0);
	}
	else if (pos.getX()>1000)
	{
		pos.setX(1000);
	}
	else if (pos.getY()<0)
	{
		pos.setY(0);
	}
	else if (pos.getY()>175)
	{
		pos.setY(175);
	}

	glutPostRedisplay();
}

int Player::getPlayerx()const {
	return pos.getX();
}

int Player::getPlayery()const {
	return pos.getY();
}

void Player::setPlayerxy(int X,int Y) {
	pos.setX(X);
	pos.setY(Y);
}

short Player::getPDirection() const {
	return PDirection;
}

void Player::setPDirection(short dir) {
	PDirection = dir;
}

Player Player::operator=(const Player& rhs) {
	if (this == &rhs)
	return *this;
	PDirection=rhs.PDirection;
	pos.setX(rhs.getPlayerx());
	pos.setY(rhs.getPlayery());
	return *this;
}
