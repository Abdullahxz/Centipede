/*
 * MushroomArr.cpp
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#include "MushroomArr.h"

MushroomArr::MushroomArr() {
	noOfMushrooms=25;
	mushroomDisplay=true;
	mushroom_array=new Mushroom[noOfMushrooms+15];
	setScoreBscore(0);

}

void MushroomArr::MushroomRand() {
	InitRandomizer();
	for (int i=0;i<noOfMushrooms;i++) {
		mushroom_array[i].setPos(GetRandInRange(10,1010),GetRandInRange(40,810));
	}
	ofstream OutputFile("Logfile.txt",ios::app);
	OutputFile <<"Random Mushrooms generated" << endl;
	OutputFile.close();
	for (int i=noOfMushrooms;i<noOfMushrooms+15;i++) {
		mushroom_array[i].setPos(-10,-10);
	}
}
void MushroomArr::Draw() {
	for (int i=0;i<noOfMushrooms;i++) {
		if (mushroom_array[i].getMushroomHp()==2 && mushroom_array[i].isPoisoned()==false)
			mushroom_array[i].Draw();
		else if (mushroom_array[i].getMushroomHp()==1 && mushroom_array[i].isPoisoned()==false)
			mushroom_array[i].Draw1();
		if (mushroom_array[i].getMushroomHp()==2 && mushroom_array[i].isPoisoned()==true)
			mushroom_array[i].DrawP();
		else if (mushroom_array[i].getMushroomHp()==1 && mushroom_array[i].isPoisoned()==true)
			mushroom_array[i].DrawP1();
	}
	for (int i=noOfMushrooms;i<noOfMushrooms+15;i++) {
		if (mushroom_array[i].getMushroomHp()==2)
			mushroom_array[i].Draw();
		else if (mushroom_array[i].getMushroomHp()==1)
			mushroom_array[i].Draw1();
	}
}

Mushroom& MushroomArr::operator[](int index) {
	if (index < 0 || index > noOfMushrooms) {
		cout<<"Invalid Index";
	}
	return mushroom_array[index];
}



void MushroomArr::Collision(Fire& fire) {
	for (int i=0;i<noOfMushrooms;i++) {
		for (int j=0;j<15;j++) {
			for (int k=0;k<10;k++) {
				if ((fire.getFy()+k==mushroom_array[i].getPos().getY()) && (fire.getFx()+j==mushroom_array[i].getPos().getX() || fire.getFx()-j==mushroom_array[i].getPos().getX()) && fire.isC()==true) {
					mushroom_array[i].setMushroomHp(mushroom_array[i].getMushroomHp()-1);
					if (mushroom_array[i].getMushroomHp()==0) {
						ofstream OutputFile("Logfile.txt",ios::app);
						OutputFile <<"==> Mushroom destroyed at "<<mushroom_array[i].getPos().getX()<<"   "<<mushroom_array[i].getPos().getY() << endl;
						OutputFile.close();
						mushroom_array[i].setPos(0,0);
						fire.setC(false);
						scoreB.setScore(scoreB.getScore()+1);
						glutPostRedisplay();
					}
					fire.setC(false);
					glutPostRedisplay();
				}
			}
		}
	}
}

bool MushroomArr::isMushroomDisplay() const {
	return mushroomDisplay;
}

void MushroomArr::setMushroomDisplay(bool mushroomDisplay) {
	this->mushroomDisplay = mushroomDisplay;
}

int MushroomArr::getNoOfMushrooms() const {
	return noOfMushrooms;
}

void MushroomArr::setNoOfMushrooms(int noOfMushrooms) {
	this->noOfMushrooms = noOfMushrooms;
}
void MushroomArr::Move() {

}

MushroomArr::~MushroomArr() {
	delete [] mushroom_array;
}
