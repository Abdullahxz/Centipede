/*
 * Flea.cpp
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#include "Flea.h"

Flea::Flea() {
	// TODO Auto-generated constructor stub
	fleaX=GetRandInRange(0,1010);
	fleaY=GetRandInRange(835,840);
	fleaB=false;
	mushroomInPlayerArea=0;
	setScoreBscore(0);
	extramush=true;
}

void Flea::Draw() {
	DrawCircle(fleaX,fleaY,10,colors[BLUE]);
}
void Flea::Move(){

}

void Flea::Move(MushroomArr& mushroom) {
	fleaY-=3;
	if (fleaY<175 && fleaY>20 && extramush==true) {
		mushroom.setNoOfMushrooms(mushroom.getNoOfMushrooms()+1);
		mushroom[mushroom.getNoOfMushrooms()-1].setPos(fleaX,fleaY);
		extramush=false;
	}
	if (fleaY<0) {
		fleaB=false;
		fleaX=GetRandInRange(0,1010);
		fleaY=GetRandInRange(835,840);
	}
}
void Flea::Collision() {

}
void Flea::Collision(Player& player) {
	if (fleaX>=player.getPlayerx() && fleaX<=player.getPlayerx()+25 && fleaY>=player.getPlayery() && fleaY<=player.getPlayery()+20) {
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"==> Flea killed player at "<<fleaX<<"   "<<fleaY<<"\n";
		OutputFile.close();
		exit(0);
	}
}
void Flea::Collision(Fire& fire) {
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if ((fire.getFx()==fleaX+i) && (fire.getFy()==fleaY+j)) {
				fleaX=GetRandInRange(0,1010);
				fleaY=GetRandInRange(855,865);
				fleaB=false;
				mushroomInPlayerArea=0;
				scoreB.setScore(scoreB.getScore()+200);
				ofstream OutputFile("Logfile.txt",ios::app);
				OutputFile <<"==>Flea killed at "<<fleaX<<"   "<<fleaY << endl;
				OutputFile.close();
				fire.setC(false);
			}
		}
	}

}
void Flea::Collision(MushroomArr& mushroom) {
	for (int i=0;i<mushroom.getNoOfMushrooms();i++) {
		if (mushroom[i].getPos().getY()<175 && mushroom[i].getPos().getY()>20  ) {
			//DrawCircle(fleaX,fleaY,5,colors[BLUE]);
			mushroomInPlayerArea+=1;
			//cout<<mushroomInPlayerArea<<endl;
		}
	}
	if (mushroomInPlayerArea==3)
	{
		fleaB=true;
	}
	else
	{
		mushroomInPlayerArea=0;
	}
}
int Flea::getFleaX() const {
	return fleaX;
}

void Flea::setFleaX(int fleaX) {
	this->fleaX = fleaX;
}

int Flea::getFleaY() const {
	return fleaY;
}

bool Flea::isFleaB() const {
	return fleaB;
}

void Flea::setFleaB(bool fleaB) {
	this->fleaB = fleaB;
}

void Flea::setFleaY(int fleaY) {
	this->fleaY = fleaY;
}


int Flea::getMushroomInPlayerArea() const {
	return mushroomInPlayerArea;
}

bool Flea::isExtramush() const {
return extramush;
}

void Flea::setExtramush(bool extramush) {
this->extramush = extramush;
}

void Flea::setMushroomInPlayerArea(int mushroomInPlayerArea) {
	this->mushroomInPlayerArea = mushroomInPlayerArea;
}
