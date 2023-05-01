/*
 * Mushroom.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include "util.h"
#include "GameObject.h"
class Mushroom:public GameObject {
protected:
	int mushroomHP;
	bool poisoned;
public:
	Mushroom();
	void Collision();
	void Draw();
	void Move();
	void Draw1();
	void DrawP();
	void DrawP1();
	int getMushroomHp() const;
	void setMushroomHp(int mushroomHp);
	bool isPoisoned() const;
	void setPoisoned(bool poisoned);
};

#endif /* MUSHROOM_H_ */
