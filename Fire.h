/*
 * Fire.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef FIRE_H_
#define FIRE_H_
#include "util.h"
#include "MoveableObject.h"

class Fire:public MoveableObject {
protected:
	int Fx,Fy;
	bool c;
public:
	Fire();
	void Draw();
	void Collision();
	void  Move();
	int getFx() const;
	void setFx(int fx);
	int getFy() const;
	void setFy(int fy);
	bool isC() const;
	void setC(bool c);
	virtual ~Fire();
};


#endif /* FIRE_H_ */
