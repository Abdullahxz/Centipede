/*
 * Mushroom.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "Mushroom.h"

Mushroom::Mushroom() {
	// TODO Auto-generated constructor stub
	mushroomHP=2;
	poisoned=false;
}

void Mushroom::Collision() {

}
void Mushroom::DrawP() {
	Torus2d(pos.getX(),pos.getY(),65,45,25,6,5,colors[PURPLE]);
	DrawRectangle(pos.getX()-1,pos.getY()+10,5,17,colors[AQUA_MARINE]);
}
void Mushroom::DrawP1() {
	Torus2d(pos.getX(),pos.getY(),65,45,25,6,5,colors[PURPLE]);
}
void Mushroom::Draw() {
	Torus2d(pos.getX(),pos.getY(),65,45,25,6,5,colors[RED]);
	DrawRectangle(pos.getX()-1,pos.getY()+10,5,17,colors[ORANGE]);
}

void Mushroom::Draw1() {
	Torus2d(pos.getX(),pos.getY(),65,45,25,6,5,colors[RED]);
	//DrawRectangle(pos.getX()-1,pos.getY()+10,5,17,colors[ORANGE]);
}

void Mushroom::Move() {

}

int Mushroom::getMushroomHp() const {
	return mushroomHP;
}

bool Mushroom::isPoisoned() const {
	return poisoned;
}

void Mushroom::setPoisoned(bool poisoned) {
	this->poisoned = poisoned;
}

void Mushroom::setMushroomHp(int mushroomHp) {
	mushroomHP = mushroomHp;
}
