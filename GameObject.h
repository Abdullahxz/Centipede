/*
 * GameObject.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Position.h"
#include "ScoreBoard.h"

class GameObject {
protected:
	Position pos;
	bool start;
	ScoreBoard scoreB;
public:
	virtual void Draw()=0;
	virtual void Collision()=0;
	virtual void Move()=0;
	virtual ~GameObject();
	Position getPos() const;
	void setPos(int X,int Y);
	void setPos(Position pos);
	virtual ScoreBoard getScoreB() const;
	virtual void setScoreB(ScoreBoard scoreB);
	bool isStart() const;
	void setStart(bool start);
	virtual void setScoreBscore(int scr);
	virtual int getScoreBscore() const;
	virtual void setScoreBnoOfLives(int scr);
	virtual int getScoreBnoOfLives() const;
};


#endif /* GAMEOBJECT_H_ */
