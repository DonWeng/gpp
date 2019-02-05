
#include "monster.h"

Monster::Monster() : Entity()
{
	spriteData.width = monsterNS::WIDTH;           // size of Player
	spriteData.height = monsterNS::HEIGHT;

	spriteData.x = monsterNS::X;                   // location on screen
	spriteData.y = monsterNS::Y;

	spriteData.rect.bottom = monsterNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = monsterNS::WIDTH;

	velocity.x = -monsterNS::SPEED;                             // velocity X
	velocity.y = 0;                             // velocity Y

	frameDelay = monsterNS::MONSTER_ANIMATION_DELAY;

	startFrame = monsterNS::BLUE_GUARD_SPAWN_START;     // first frame of player animation
	endFrame = monsterNS::BLUE_GUARD_SPAWN_END;     // last frame of player animation
	currentFrame = startFrame;

	radius = monsterNS::WIDTH / 2.0;

	mass = monsterNS::MASS;

	collisionType = entityNS::BOX;

	spriteData.scale = 1;

	health = 100;

	//Own variables
	positionX = LEVEL_EXTENT_X - monsterNS::WIDTH;




}


//=============================================================================
// Initialize the monster
//=============================================================================
bool Monster::initialize(Input *inputPtr, int width, int height, int ncols,
	TextureManager *textureM, Graphics *graphicPtr)
{
	return(Entity::initialize(inputPtr, width, height, ncols, textureM, graphicPtr));
}

//=============================================================================
// draw the monster
//=============================================================================
void Monster::draw()
{

	Image::draw();              // draw monster
}

//=============================================================================
// Update the monster
//=============================================================================
void Monster::update(float frameTime)
{
	Entity::update(frameTime);

	////only move monster if within screen
	//if (visible)
	//{
		//spriteData.x += frameTime * velocity.x;         // move monster visibly along X 
	//}

	// move monster invisibly along X 
	positionX += frameTime * velocity.x;       

	//Check if object is within level
	if (positionX < 0)
	{
		//If monster is past left edge
		//stop at left edge of map
		positionX = 0;

	}
	//If map is past right edge
	else if (positionX > LEVEL_EXTENT_X)
	{
		//stop at right edge of map
		positionX = LEVEL_EXTENT_X - (monsterNS::BLUE_GUARD_WIDTH * getScale());

	}

}

//=============================================================================
// Check visibility of monster
//=============================================================================
bool Monster::checkPosition(float mapX)
{
	//Calculate position of object in relations with screen
	float currentPosX = positionX + mapX;

	//Check if object is in screen
	if (currentPosX < GAME_WIDTH || currentPosX >(-monsterNS::WIDTH*getScale()))
	{
		//If so, set sprite coordinates to new position
		setX(currentPosX);

		//permission to draw
		inScreen = true;
	}
	else
	{
		//Don't draw as object not in screen
		inScreen = false;
	}

	

	return inScreen;
}


