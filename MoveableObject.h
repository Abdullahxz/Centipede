/*
 * MoveableObject.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_
#include "GameObject.h"
class MoveableObject:public GameObject {
protected:
public:
	virtual void Move()=0;
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
