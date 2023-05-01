/*
 * Spider.cpp
 *
 *  Created on: May 8, 2019
 *      Author: abdullah
 */

#include "Spider.h"

Spider::Spider() {
	// TODO Auto-generated constructor stub
	spiderX=0;
	spiderY=0;
	spiderD=1;
	spiderT=false;
	setScoreBscore(0);
}
void Spider::Draw() {
	//DrawSquare(spiderX,spiderY,20,colors[AQUA]);
	DrawCircle(spiderX,spiderY,10,colors[AQUA]);
	DrawLine(spiderX+10,spiderY+5,spiderX+20,spiderY+10,3,colors[AQUA]);
	DrawLine(spiderX+20,spiderY+10,spiderX+30,spiderY+5,3,colors[AQUA]);
	DrawLine(spiderX+10,spiderY-5,spiderX+20,spiderY+5,3,colors[AQUA]);
	DrawLine(spiderX+20,spiderY+5,spiderX+30,spiderY-5,3,colors[AQUA]);
	DrawLine(spiderX-10,spiderY+5,spiderX-20,spiderY+10,3,colors[AQUA]);
	DrawLine(spiderX-20,spiderY+10,spiderX-30,spiderY+5,3,colors[AQUA]);
	DrawLine(spiderX-10,spiderY-5,spiderX-20,spiderY+5,3,colors[AQUA]);
	DrawLine(spiderX-20,spiderY+5,spiderX-30,spiderY-5,3,colors[AQUA]);

}
void Spider::Move() {
	spiderY=fabs(sin(spiderX+=3.2)*200);
	if (spiderX>=1020) {
		spiderX=0;
		spiderY=0;
		spiderT=false;
	}
}
void Spider::Collision() {

}
void Spider::Collision(Fire& fire) {
	for (int i=0;i<7;i++) {
		for (int j=0;j<7;j++) {
			if (fire.getFx()+i==spiderX && fire.getFy()+j==spiderY) {
				spiderX=0;
				spiderY=0;
				spiderT=false;
				scoreB.setScore(scoreB.getScore()+600);
				ofstream OutputFile("Logfile.txt",ios::app);
				OutputFile <<"==> Spider killed at "<<spiderX<<"   "<<spiderY<<"\n";
				OutputFile.close();
				fire.setC(false);
			}
		}
	}
}
void Spider::Collision(Player& player) {
	if (spiderX>=player.getPlayerx() && spiderX<=player.getPlayerx()+25 && spiderY>=player.getPlayery() && spiderY<=player.getPlayery()+20) {
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"==> Spider killed player at "<<spiderX<<"   "<<spiderY<<"\n";
		OutputFile.close();
		system("canberra-gtk-play -f GameOver.wav");
		exit(0);
	}
}
double Spider::getSpiderX() const {
	return spiderX;
}

void Spider::setSpiderX(double spiderX) {
	this->spiderX = spiderX;
}

double Spider::getSpiderY() const {
	return spiderY;
}

int Spider::getSpiderD() const {
	return spiderD;
}

bool Spider::isSpiderT() const {
	return spiderT;
}

void Spider::setSpiderT(bool spiderT) {
	this->spiderT = spiderT;
}

void Spider::setSpiderD(int spiderD) {
	this->spiderD = spiderD;
}

void Spider::setSpiderY(double spiderY) {
	this->spiderY = spiderY;
}

Spider::~Spider() {
	// TODO Auto-generated destructor stub
}

