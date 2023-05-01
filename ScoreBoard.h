/*
 * ScoreBoard.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include "util.h"

class ScoreBoard {
protected:
	int numberOfLives,score;
public:
	ScoreBoard();
	virtual int getNumberOfLives() const;
	virtual void setNumberOfLives(int numberOfLives);
	virtual int getScore() const;
	virtual void setScore(int score);
	virtual ~ScoreBoard();
};

#endif /* SCOREBOARD_H_ */
