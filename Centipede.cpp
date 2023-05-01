/*
 * Centipede.cpp
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#include "Centipede.h"

Centipede::Centipede() {
	// TODO Auto-generated constructor stub
	noOfSegments=15;
	centipede_array=new Segment[noOfSegments];
	centipede_array[0].setPos(10,830);
	cDirection=RIGHT;
	checkDown=true;
	setScoreBscore(0);
}

void Centipede::Draw() {
	for (int i=0;i<noOfSegments;i++) {
		//		if (i==0) {
		//			centipede_array[i].DrawHead();
		//		}
		//		else
		centipede_array[i].Draw();
	}
}

void Centipede::Collision(Fire& fire,MushroomArr& mushroom) {
	for (int k=0;k<noOfSegments;k++) {
		for (int i=0;i<7;i++) {
			for (int j=0;j<7;j++) {
				if ((fire.getFx()+j==centipede_array[k].getPos().getX()) && (fire.getFy()+i==centipede_array[k].getPos().getY()) && fire.isC()==true) {
					mushroom.setNoOfMushrooms(mushroom.getNoOfMushrooms()+1);
					mushroom[mushroom.getNoOfMushrooms()-1].setPos(centipede_array[k].getPos().getX(),centipede_array[k].getPos().getY());
					for (int l=k;l<noOfSegments;l++) {
						centipede_array[k].setPos(centipede_array[k+1].getPos().getX(),centipede_array[k+1].getPos().getY());
					}
					noOfSegments--;
					fire.setC(false);
					scoreB.setScore(scoreB.getScore()+10);
					ofstream OutputFile("Logfile.txt",ios::app);
					OutputFile <<"==> Fire hit at centipede index "<< k<< endl;
					OutputFile <<"==> Mushroom generated at " << k<< endl;
					OutputFile.close();
				}
			}
		}
	}
}

void Centipede::Collision(Player& player) {
	for (int k=0;k<noOfSegments;k++) {
		for (int i=0;i<15;i++){
			for (int j=0;j<20;j++) {
				if (player.getPlayerx()+i==centipede_array[k].getPos().getX() && player.getPlayery()+j==centipede_array[k].getPos().getY()) {
					glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
							1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
					glClear (GL_COLOR_BUFFER_BIT);
					ifstream InputFile ("HighScore.txt");
					if(InputFile.is_open())
					{
						int HScore;
						InputFile >> HScore;
						if (200 >= HScore)
						{
							DrawString( 50, 259, "CONGRATS, YOU ACHIEVED A NEW HIGHSCORE ", colors[66]);
							DrawString( 200, 300, "YOUR SCORE IS ", colors[66]);
							DrawString( 400, 300, "score" , colors[66]);
							ofstream OutputFile("HighScore.txt");
							OutputFile << 200;
							OutputFile.close();
							InputFile.close();
						}
						else
						{
							DrawString( 200, 300, "YOUR SCORE IS ", colors[66]);
							DrawString( 400, 300, "  "  , colors[66]);
							DrawString( 100, 259, "YOU COULDNT BREAK THE HIGH SCORE ", colors[66]);
							InputFile.close();
						}
					}
					DrawString( 170, 345, "HARD LUCK, GAME OVER. ", colors[66]);
					ofstream OutputFile("Logfile.txt",ios::app);
					OutputFile <<"PLAYER COLLIDED WITH CENTIPEDE, THE GAME WILL NOW EXIT" << endl;
					OutputFile.close();
					system("canberra-gtk-play -f GameOver.wav");
					//sleep(1);
					exit(1);
					//player.setPlayerxy(player.getPlayerx()+i,player.getPlayery()+j);
				}
			}
		}
	}
}

void Centipede::Collision(MushroomArr& mushroom) {
	for (int i=0;i<mushroom.getNoOfMushrooms();i++) {
		for (int j=0;j<25;j++) {
			for (int k=0;k<12;k++) {
				if ((centipede_array[0].getPos().getX()==mushroom[i].getPos().getX()+j) && (centipede_array[0].getPos().getY()==mushroom[i].getPos().getY()+k)) {
					//cout<<"Collision detected at "<< centipede_array[0].getPos().getX()+j<<"   "<<centipede_array[0].getPos().getY()+k <<endl;
					if (cDirection==LEFT && checkDown==true) {
						cDirection=DOWN;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
						cDirection=RIGHT;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
					}
					else if (cDirection==RIGHT && checkDown==true) {
						cDirection=DOWN;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
						cDirection=LEFT;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
					}
					if (cDirection==LEFT && checkDown==false) {
						cDirection=UP;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
						cDirection=RIGHT;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
					}
					else if (cDirection==RIGHT && checkDown==false) {
						cDirection=UP;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
						cDirection=LEFT;
						Centipede::Move();
						Centipede::Draw();
						glutPostRedisplay();
					}
					ofstream OutputFile("Logfile.txt",ios::app);
					OutputFile <<"Collision between centipede and mushroom detected at "<< centipede_array[0].getPos().getX()+j<<"   "<<centipede_array[0].getPos().getY()+k <<endl;
					OutputFile.close();
					glutPostRedisplay();

				}
			}
		}
	}
}

void Centipede::Move() {
	if (cDirection==RIGHT)
		centipede_array[0].setPos(centipede_array[0].getPos().getX()+8,centipede_array[0].getPos().getY());
	else if (cDirection==LEFT)
		centipede_array[0].setPos(centipede_array[0].getPos().getX()-8,centipede_array[0].getPos().getY());
	else if (cDirection==UP)
		centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()+10);
	else if (cDirection==DOWN)
		centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	for (int i=noOfSegments-1; i>0;i--) {
		centipede_array[i].setPos(centipede_array[i-1].getPos().getX(),centipede_array[i-1].getPos().getY());
	}
}

void Centipede::Movement() {
	if (centipede_array[0].getPos().getX()>1020 && checkDown==true)
	{
		cDirection=DOWN;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		cDirection=LEFT;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
	if (centipede_array[0].getPos().getX()<0 && checkDown==true)
	{
		cDirection=DOWN;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		cDirection=RIGHT;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
	if (centipede_array[0].getPos().getY()<0)
	{
		centipede_array[0].setPos(0,0);
		cDirection=RIGHT;
		checkDown=false;
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Centipede will now remain in Players area "<< endl;
		OutputFile.close();
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
	if (centipede_array[0].getPos().getX()>1020 && checkDown==false)
	{
		cDirection=UP;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		cDirection=LEFT;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
	if (centipede_array[0].getPos().getX()<0 && checkDown==false)
	{
		cDirection=UP;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		cDirection=RIGHT;
		Centipede::Move();
		Centipede::Draw();
		glutPostRedisplay();
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
	if (centipede_array[0].getPos().getY()>830)
	{
		centipede_array[0].setPos(10,830);
		cDirection=RIGHT;
		checkDown=true;
		//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
	}
		if (centipede_array[0].getPos().getY()>175 && checkDown==false)
		{
			centipede_array[0].setPos(10,165);
			checkDown=true;
			if (centipede_array[0].getPos().getX()>1020 && checkDown==true)
			{
				cDirection=DOWN;
				Centipede::Move();
				Centipede::Draw();
				glutPostRedisplay();
				cDirection=LEFT;
				Centipede::Move();
				Centipede::Draw();
				glutPostRedisplay();
				//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);
			}
			if (centipede_array[0].getPos().getX()<0 && checkDown==true)
			{
				cDirection=DOWN;
				Centipede::Move();
				Centipede::Draw();
				glutPostRedisplay();
				cDirection=RIGHT;
				Centipede::Move();
				Centipede::Draw();
				glutPostRedisplay();
				//centipede_array[0].setPos(centipede_array[0].getPos().getX(),centipede_array[0].getPos().getY()-10);

			}
		}

}

short Centipede::getDirection() const {
	return cDirection;
}

void Centipede::setDirection(short direction) {
	cDirection = direction;
}

int Centipede::getNoOfSegments() const {
	return noOfSegments;
}

void Centipede::setNoOfSegments(int noOfSegments) {
	this->noOfSegments = noOfSegments;
}

Centipede::~Centipede() {
	// TODO Auto-generated destructor stub
	delete [] centipede_array;
}

