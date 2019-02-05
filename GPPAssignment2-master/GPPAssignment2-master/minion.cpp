
#include "minion.h"

Minion::Minion() : Monster()
{
	spriteData.width = monsterNS::BLUE_GUARD_WIDTH;           // size of Player
	spriteData.height = monsterNS::BLUE_GUARD_HEIGHT;

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

	collisionType = entityNS::CIRCLE;

	spriteData.scale = 1;

	health = 100;

	//Own variables
	positionX = LEVEL_EXTENT_X - monsterNS::WIDTH;

	moving = false;


}


//=============================================================================
// Initialize the monster
//=============================================================================
bool Minion::initialize(Input *inputPtr, int width, int height, int ncols,
	TextureManager *textureM, Graphics *graphicPtr)
{
	return(Entity::initialize(inputPtr, width, height, ncols, textureM, graphicPtr));
}

//=============================================================================
// draw the monster
//=============================================================================
void Minion::draw()
{
	if (getCurrentFrame() == monsterNS::BLUE_GUARD_SPAWN_END)
	{
		setFrames(monsterNS::BLUE_GUARD_START_FRAME, monsterNS::BLUE_GUARD_END_FRAME);
		setCurrentFrame(monsterNS::BLUE_GUARD_START_FRAME);

		moving = true;
	}

	if (getCurrentFrame() == monsterNS::BLUE_GUARD_DEATH_END)
	{
		visible = false;
	}

	Monster::draw();              // draw monster
}

//=============================================================================
// Update the monster
//=============================================================================
void Minion::update(float frameTime)
{
	if (moving)
	{
		Monster::update(frameTime);
	}
	else
	{
		Entity::update(frameTime);
	}
	

}

//=============================================================================
//
//=============================================================================


