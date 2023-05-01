/*
 * Segment.cpp
 *
 *  Created on: May 4, 2019
 *      Author: abdullah
 */

#include "Segment.h"

Segment::Segment() {
	// TODO Auto-generated constructor stub

}
void Segment::Draw() {
	DrawRoundRect(pos.getX(),pos.getY(),9,9,colors[GREEN]);
	DrawLine(pos.getX()+2,pos.getY(),pos.getX()+2,pos.getY()-5,1,colors[RED]);
}
void Segment::Collision() {

}
void Segment::Move() {

}
void Segment::DrawHead() {
	//DrawCircle(pos.getX()+15,pos.getY()+5,6,colors[LIGHT_SEA_GREEN]);

	DrawRoundRect(pos.getX()+10,pos.getY(),10,10,colors[WHITE]);
}


Segment::~Segment() {
	// TODO Auto-generated destructor stub
}

