/*
 * Scorpion.cpp
 *
 *  Created on: May 8, 2019
 *      Author: abdullah
 */

#include "Scorpion.h"

Scorpion::Scorpion() {
	// TODO Auto-generated constructor stub
	scorpioD=1;
	scorpioT=false;
	scorpioX=0;
	scorpioY=0;
	setScoreBscore(0);
}
void Scorpion::Draw() {
	DrawRectangle(scorpioX,scorpioY,20,15,colors[AQUA]);
	DrawRectangle(scorpioX-20,scorpioY,15,10,colors[AQUA]);
	DrawRectangle(scorpioX-35,scorpioY,10,5,colors[AQUA]);
}
void Scorpion::Move() {
	scorpioY=680;
	scorpioX+=1;
	if (scorpioX>=1020) {
		scorpioX=0;
		scorpioY=0;
		scorpioT=false;
	}
}
void Scorpion::Collision(Fire& fire) {
	for (int i=0;i<15;i++) {
		for (int j=0;j<7;j++) {
			if ((fire.getFx()+i==scorpioX || fire.getFx()-i==scorpioX) && fire.getFy()+j==scorpioY) {
				scorpioX=0;
				scorpioY=0;
				scorpioT=false;
				scoreB.setScore(scoreB.getScore()+1000);
				ofstream OutputFile("Logfile.txt",ios::app);
				OutputFile <<"==> Scorpio killed at "<<scorpioX<<"   "<<scorpioY<<"\n";
				OutputFile.close();
				fire.setC(false);
			}
		}
	}
}
void Scorpion::Collision(MushroomArr& mushroom) {
	for (int k=0;k<mushroom.getNoOfMushrooms();k++) {
		for (int i=0;i<2;i++) {
			for (int j=0;j<20;j++) {
				if (mushroom[k].getPos().getX()+i==scorpioX && mushroom[k].getPos().getY()+j==scorpioY) {
					ofstream OutputFile("Logfile.txt",ios::app);
					OutputFile <<"==> Scorpio poisoned Mushroom at "<<mushroom[k].getPos().getX()<<"   "<<mushroom[k].getPos().getY()<<"\n";
					OutputFile.close();
					mushroom[k].setPoisoned(true);
				}
			}
		}
	}
}
void Scorpion::Collision() {

}

int Scorpion::getScorpioD() const {
	return scorpioD;
}

void Scorpion::setScorpioD(int scorpioD) {
	this->scorpioD = scorpioD;
}

bool Scorpion::isScorpioT() const {
	return scorpioT;
}

void Scorpion::setScorpioT(bool scorpioT) {
	this->scorpioT = scorpioT;
}

double Scorpion::getScorpioX() const {
	return scorpioX;
}

void Scorpion::setScorpioX(double scorpioX) {
	this->scorpioX = scorpioX;
}

double Scorpion::getScorpioY() const {
	return scorpioY;
}

void Scorpion::setScorpioY(double scorpioY) {
	this->scorpioY = scorpioY;
}

Scorpion::~Scorpion() {
	// TODO Auto-generated destructor stub
}

