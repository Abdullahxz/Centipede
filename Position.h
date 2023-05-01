/*
 * Position.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
protected:
	int x;
	int y;
public:
	Position ();
	Position(int X,int Y);
	int getX() const;
	void setX(int x);
	int getY() const ;
	void setY(int y);
	virtual ~Position();
};


#endif /* POSITION_H_ */
