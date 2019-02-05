
#ifndef _ASTEROID_H                 // Prevent multiple definitions if this 
#define _ASTEROID_H                 // file is included in more than one place 
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace asteroidNS
{

	const int WIDTH = 40;                   // image width
	const int HEIGHT = 40;                  // image height

	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = 0; // radians per second
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass


	const int   TEXTURE_COLS = 8;           
	const int   ASTEROID_START_FRAME = 0;      
	const int   ASTEROID_END_FRAME = 7;        


	const float ASTEROID_ANIMATION_DELAY = 0.1f;    // time between frames

}

// inherits from Entity class
class Asteroid : public Entity
{
private:

	boolean active = true;

public:
	// constructor
	Asteroid();

	// inherited member functions
	virtual void draw();
	/*virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);*/
	void update(float frameTime);


	boolean getActive();
	void setActive(boolean flag);

};
#endif

