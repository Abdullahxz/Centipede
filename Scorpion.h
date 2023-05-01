/*
 * Scorpion.h
 *
 *  Created on: May 8, 2019
 *      Author: abdullah
 */

#ifndef SCORPION_H_
#define SCORPION_H_
#include "MoveableObject.h"
#include "Fire.h"
#include "MushroomArr.h"
class Scorpion:public MoveableObject {
protected:
	double scorpioX,scorpioY;
	int scorpioD;
	bool scorpioT;
public:
	Scorpion();
	void Draw();
	void Collision(Fire& fire);
	void Collision(MushroomArr& mushroom);
	void Move();
	void Collision();
	virtual ~Scorpion();
	int getScorpioD() const;
	void setScorpioD(int scorpioD);
	bool isScorpioT() const;
	void setScorpioT(bool scorpioT);
	double getScorpioX() const;
	void setScorpioX(double scorpioX);
	double getScorpioY() const;
	void setScorpioY(double scorpioY);
};

#endif /* SCORPION_H_ */
