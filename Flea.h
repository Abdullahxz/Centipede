/*
 * Flea.h
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#ifndef FLEA_H_
#define FLEA_H_
#include "MoveableObject.h"
#include "util.h"
#include "MushroomArr.h"
#include "Player.h"
class Flea:public MoveableObject {
protected:
	int fleaX,fleaY;
	bool fleaB;
	int mushroomInPlayerArea;
	bool extramush;
public:
	Flea();
	void Draw();
	void Move();
	void Move(MushroomArr& mushroom);
	void Collision();
	void Collision(Fire& fire);
	void Collision(MushroomArr& mushroom);
	void Collision(Player& player);
	int getFleaX() const;
	void setFleaX(int fleaX);
	int getFleaY() const;
	void setFleaY(int fleaY);
	bool isFleaB() const;
	void setFleaB(bool fleaB);
	int getMushroomInPlayerArea() const;
	void setMushroomInPlayerArea(int mushroomInPlayerArea);
	bool isExtramush() const;
	void setExtramush(bool extramush);
};

#endif /* FLEA_H_ */
