/*
 * Spider.h
 *
 *  Created on: May 8, 2019
 *      Author: abdullah
 */

#ifndef SPIDER_H_
#define SPIDER_H_
#include "MoveableObject.h"
#include "Fire.h"
#include "Player.h"

class Spider:public MoveableObject {
protected:
	double spiderX,spiderY;
	int spiderD;
	bool spiderT;
public:
	Spider();
	void Draw();
	void Collision(Fire& fire);
	void Collision(Player& player);
	void Move();
	void Collision();
	virtual ~Spider();
	double getSpiderX() const;
	void setSpiderX(double spiderX);
	double getSpiderY() const;
	void setSpiderY(double spiderY);
	int getSpiderD() const;
	void setSpiderD(int spiderD);
	bool isSpiderT() const;
	void setSpiderT(bool spiderT);
};

#endif /* SPIDER_H_ */
