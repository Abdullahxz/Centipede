/*
 * Fire.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "Fire.h"

Fire::Fire() {
	//		Fx=Game[0]->getPos().getX()+8;
	//		Fy=Game[0]->getPos().getY()+25;
	//		//setPos(Fx,Fy);
	c=false;
}
Fire::~Fire() {
	// TODO Auto-generated destructor stub
}

void Fire::Draw() {
	DrawRectangle(Fx,Fy,4,10,colors[WHITE]);
}
void Fire::Collision() {

}
void  Fire::Move() {
	//setPos(Fx,Fy+20);
	Fy+=5;
}


int Fire::getFx() const {
	return Fx;
}

void Fire::setFx(int fx) {
	Fx = fx;
}

int Fire::getFy() const {
	return Fy;
}

void Fire::setFy(int fy) {
	Fy = fy;
}

bool Fire::isC() const {
	return c;
}

void Fire::setC(bool c) {
	this->c = c;
}
