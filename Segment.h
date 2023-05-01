/*
 * Segment.h
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include "MoveableObject.h"
#include "util.h"
class Segment: public MoveableObject {
protected:
public:
	Segment();
	void Draw();
	void DrawHead();
	void Move();
	void Collision();
	virtual ~Segment();
};

#endif /* SEGMENT_H_ */
