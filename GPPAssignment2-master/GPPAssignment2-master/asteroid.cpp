#include "asteroid.h"

//=============================================================================
// default constructor
//=============================================================================
Asteroid::Asteroid() : Entity()
{
	spriteData.width = asteroidNS::WIDTH;           // size of asteroid
	spriteData.height = asteroidNS::HEIGHT;
	spriteData.x = asteroidNS::X;                   // location on screen
	spriteData.y = asteroidNS::Y;
	spriteData.rect.bottom = asteroidNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = asteroidNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = asteroidNS::ASTEROID_ANIMATION_DELAY;
	startFrame = asteroidNS::ASTEROID_START_FRAME;     // first frame of asteroid animation
	endFrame = asteroidNS::ASTEROID_END_FRAME;     // last frame of asteroid animation
	currentFrame = startFrame;
	radius = asteroidNS::WIDTH / 2.0;
	mass = asteroidNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
//bool Asteroid::initialize(Game *gamePtr, int width, int height, int ncols,
//	TextureManager *textureM)
//{
//
//	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
//}

//=============================================================================
// draw the asteroid
//=============================================================================
void Asteroid::draw()
{

	Image::draw();              // draw asteroid


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Asteroid::update(float frameTime)
{
	Entity::update(frameTime);


}

boolean Asteroid::getActive()
{
	return active;
}

void Asteroid::setActive(boolean flag)
{
	active = flag;
}