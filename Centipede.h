/*
 * Centipede.h
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_
#define UP 5
#define DOWN -5
#define LEFT -10
#define RIGHT 10
#define STOP 0
#include <fstream>
#include "Fire.h"
#include "MushroomArr.h"
#include "Player.h"
#include "Segment.h"
class Centipede:public Segment {
protected:
	int noOfSegments;
	Segment* centipede_array;
	short cDirection;
	bool checkDown;
public:
	Centipede();
	void Move();
	void Draw();
	void Collision(MushroomArr& mushroom);
	void Collision(Fire& fire,MushroomArr& mushroom);
	void Collision(Player& player);
	void Movement();
	virtual ~Centipede();
	short getDirection() const;
	void setDirection(short direction);
	int getNoOfSegments() const;
	void setNoOfSegments(int noOfSegments);
};

#endif /* CENTIPEDE_H_ */
