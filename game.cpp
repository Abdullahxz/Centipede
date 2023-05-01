//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "Position.h"
#include "GameObject.h"
#include "Mushroom.h"
#include "MushroomArr.h"
#include "ScoreBoard.h"
#include "Fire.h"
#include "Player.h"
#include "Flea.h"
#include "MoveableObject.h"
#include "Centipede.h"
#include "Spider.h"
#include "Scorpion.h"
#include <iostream>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#define UP 5
#define DOWN -5
#define LEFT -10
#define RIGHT 10
#define STOP 0





// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}




GameObject *Game[7];





/*
 * Main Canvas drawing function.
 * */
Board *b;
MushroomArr* m;
Fire* f;
Flea* fl;
Centipede* c;
Player* p;
Spider* sp;
Scorpion* sc;


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	Game[0]->Draw();
	Game[0]->Move();
	Game[1]->Draw();
	Game[1]->Move();
	c->Movement();
	c->Collision(*f,*m);
	c->Collision(*m);
	c->Collision(*p);
	if (sp->isSpiderT()){
		sp->Draw();
		sp->Move();
		sp->Collision(*f);
		sp->Collision(*p);
	}
	if (sc->isScorpioT()){
		sc->Draw();
		sc->Move();
		sc->Collision(*f);
		sc->Collision(*m);
	}
	if(f->isC()==true) {
		Game[2]->Draw();
		f->Move();
	}
	if(f->getFy()>=1020)
		f->setC(false);
	if (m->isMushroomDisplay()==true) {
		m->MushroomRand();
		m->setMushroomDisplay(false);
	}
	Game[3]->Draw();
	m->Collision(*f);
	if (fl->isFleaB()==true){
		Game[4]->Draw();
		fl->Move(*m);
		fl->Collision(*f);
		fl->Collision(*p);

	}
	fl->Collision(*m);
	//Display Score
	DrawString( 20, 800, "Score: ", colors[MISTY_ROSE]);
	DrawString( 90, 800, Num2Str(m->getScoreBscore()+c->getScoreBscore()+fl->getScoreBscore()+sc->getScoreBscore()+sc->getScoreBscore()), colors[MISTY_ROSE]);
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		Game[0]->setPos(Game[0]->getPos().getX()-10,Game[0]->getPos().getY());
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved left, now at pos "<<Game[0]->getPos().getX()-10<<"   "<<Game[0]->getPos().getY()<<endl;
		OutputFile.close();
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		Game[0]->setPos(Game[0]->getPos().getX()+10,Game[0]->getPos().getY());
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved right, now at pos "<<Game[0]->getPos().getX()+10<<"   "<<Game[0]->getPos().getY()<<endl;
		OutputFile.close();
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		Game[0]->setPos(Game[0]->getPos().getX(),Game[0]->getPos().getY()+10);
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved up, now at pos "<<Game[0]->getPos().getX()<<"   "<<Game[0]->getPos().getY()+10<<endl;
		OutputFile.close();
	}
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		Game[0]->setPos(Game[0]->getPos().getX(),Game[0]->getPos().getY()-10);
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved down, now at pos "<<Game[0]->getPos().getX()<<"   "<<Game[0]->getPos().getY()-10<<endl;
		OutputFile.close();
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32) //Key for placing the bomb
	{
		if(f->isC()==false) {
			//do something if b is pressed
			//		f.setFxFy();
			//		f.Draw();
			//		f.Move();
			f->setFx(Game[0]->getPos().getX()+10);
			f->setFy(Game[0]->getPos().getY()+20);
			f->setC(true);
			ofstream OutputFile("Logfile.txt",ios::app);
			OutputFile <<"space pressed" << endl;
			OutputFile.close();
			//system("canberra-gtk-play -f Fire3.wav");
			glutPostRedisplay();
			glutIgnoreKeyRepeat(0);
		}
	}
	if (key == 'w') {
		Game[0]->setPos(Game[0]->getPos().getX(),Game[0]->getPos().getY()+10);
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved up, now at pos "<<Game[0]->getPos().getX()<<"   "<<Game[0]->getPos().getY()+10<<endl;
		OutputFile.close();
	}
	else if (key == 's') {
		Game[0]->setPos(Game[0]->getPos().getX(),Game[0]->getPos().getY()-10);
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved down, now at pos "<<Game[0]->getPos().getX()<<"   "<<Game[0]->getPos().getY()-10<<endl;
		OutputFile.close();
	}
	else if (key == 'a') {
		Game[0]->setPos(Game[0]->getPos().getX()-10,Game[0]->getPos().getY());
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved left, now at pos "<<Game[0]->getPos().getX()-10<<"   "<<Game[0]->getPos().getY()<<endl;
		OutputFile.close();
	}
	else if (key == 'd') {
		Game[0]->setPos(Game[0]->getPos().getX()+10,Game[0]->getPos().getY());
		ofstream OutputFile("Logfile.txt",ios::app);
		OutputFile <<"Player moved right, now at pos "<<Game[0]->getPos().getX()+10<<"   "<<Game[0]->getPos().getY()<<endl;
		OutputFile.close();
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	if (sp->getSpiderD()%50==0) {
		sp->setSpiderT(true);
	}
	sp->setSpiderD(sp->getSpiderD()+1);
	if (sc->getScorpioD()%30==0) {
		sc->setScorpioT(true);
	}
	sc->setScorpioD(sc->getScorpioD()+1);
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if(f->isC()==false) {
			//do something if b is pressed
			//		f.setFxFy();
			//		f.Draw();
			//		f.Move();
			f->setFx(Game[0]->getPos().getX()+10);
			f->setFy(Game[0]->getPos().getY()+20);
			f->setC(true);
			ofstream OutputFile("/home/abdullah/workspace/Centipede/Logfile.txt",ios::app);
			OutputFile <<"Left Mouse Button pressed" << endl;
			OutputFile.close();
			//system("canberra-gtk-play -f Fire3.wav");
			glutPostRedisplay();
			glutIgnoreKeyRepeat(0);
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	system("canberra-gtk-play -f GameStart.wav");


	Game[0]=new Player;
	Game[1]=new Centipede;
	Game[2]=new Fire;
	Game[3]=new MushroomArr;
	Game[4]=new Flea;
	Game[5]=new Spider;
	Game[6]=new Scorpion;
	p=dynamic_cast<Player*>(Game[0]);
	c=dynamic_cast<Centipede*>(Game[1]);
	f=dynamic_cast<Fire*>(Game[2]);
	m=dynamic_cast<MushroomArr*>(Game[3]);
	fl=dynamic_cast<Flea*>(Game[4]);
	sp=dynamic_cast<Spider*>(Game[5]);
	sc=dynamic_cast<Scorpion*>(Game[6]);


	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
