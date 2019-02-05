#ifndef _MINION_H
#define _MINION_H
#define WIN32_LEAN_AND_MEAN

#include "monster.h"
#include "constants.h"

class Minion : public Monster
{
private:
	bool moving;

public:
	//Constructor & Destructor
	Minion();

	//inherited functions
	virtual void draw();
	virtual bool initialize(Input *inputPtr, int width, int height, int ncols,
		TextureManager *textureM, Graphics *graphicPtr);
	virtual void update(float frameTime);

};





#endif