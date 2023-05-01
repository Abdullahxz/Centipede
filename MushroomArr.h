/*
 * MushroomArr.h
 *
 *  Created on: May 3, 2019
 *      Author: abdullah
 */

#ifndef MUSHROOMARR_H_
#define MUSHROOMARR_H_
#include "Mushroom.h"
#include "Fire.h"
//#include "ScoreBoard.h"

class MushroomArr:public Mushroom {
protected:
	int noOfMushrooms;
	Mushroom* mushroom_array;
	bool mushroomDisplay;
public:
	MushroomArr();
	void MushroomRand();
	void Draw();
	void Move();
	void Collision(Fire& fire);
	bool isMushroomDisplay() const;
	void setMushroomDisplay(bool mushroomDisplay) ;
	int getNoOfMushrooms() const;
	void setNoOfMushrooms(int noOfMushrooms);
	Mushroom& operator[](int index);
	~MushroomArr();
};


#endif /* MUSHROOMARR_H_ */
