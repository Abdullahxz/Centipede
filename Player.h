/*
 * Player.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "util.h"
#include "MoveableObject.h"
class Player:public MoveableObject {
protected:
	short PDirection;
public:
	Player();
	void Draw();
	void Collision();
	void Move();
	int getPlayerx()const;
	int getPlayery()const ;
	Player operator=(const Player& rhs);
	void setPlayerxy(int X,int Y);
	short getPDirection() const;
	void setPDirection(short dir);
};


#endif /* PLAYER_H_ */
