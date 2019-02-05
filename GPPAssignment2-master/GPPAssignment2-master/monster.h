
#ifndef _MONSTER_H
#define _MONSTER_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace monsterNS
{
	const int WIDTH = 75;                   // image width
	const int HEIGHT = 75;                  // image height
	const int X = GAME_WIDTH / 2;			// initial location on screen
	const int Y = GAME_HEIGHT / 2;
	const float MASS = 300.0f;              // mass
	const float SPEED = 75;                // in pixels per second
	const float MONSTER_ANIMATION_DELAY = 0.5f;    // time between frames

	//BLUE GUARD
	const int BLUE_GUARD_WIDTH = 64;
	const int BLUE_GUARD_HEIGHT = 64;


	//TEXTURE Columns
	const int   TEXTURE_COLS = 4;           // texture has <no.> columns

	//FRAMES
	const int   BLUE_GUARD_START_FRAME = 0;      // blue robot starts at frame 0
	const int   BLUE_GUARD_END_FRAME = 3;        // blue robot animation frames 0-9
	const int	BLUE_GUARD_SPAWN_START = 32;	
	const int	BLUE_GUARD_SPAWN_END = 35;
	const int	BLUE_GUARD_DEATH_START = 24;
	const int	BLUE_GUARD_DEATH_END = 27;



	
}



class Monster : public Entity
{
	
	
protected:
	//Attributes
	float positionX;
	bool inScreen;


public:
	//Constructor & Destructor
	Monster();

	//functions
	virtual void draw();
	virtual bool initialize(Input *inputPtr, int width, int height, int ncols,
		TextureManager *textureM, Graphics *graphicPtr);
	virtual void update(float frameTime);


	bool checkPosition(float mapX);
};


#endif
