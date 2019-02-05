#ifndef _PLAYER_H                 // Prevent multiple definitions if this 
#define _PLAYER_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "playerState.h"

//enum playerState
//{
//	IdleState, 
//	MoveState, 
//	ShootState, 
//	JumpState, 
//	HurtState, 
//	DeathState
//};

namespace playerNS
{
	const int WIDTH = 75;                   // image width
	const int HEIGHT = 75;                  // image height
	const int X = GAME_WIDTH / 2;			// location on screen
	const int Y = GAME_HEIGHT / 2;
	const float MASS = 300.0f;              // mass
	const float SPEED = 100;                // 100 pixels per second
	const int   TEXTURE_COLS = 10;           // texture has 8 columns
	const int   PLAYER_START_FRAME = 0;      // player starts at frame 0
	const int   PLAYER_END_FRAME = 9;        // player animation frames 0-9
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
	//const int   IDLE_START_FRAME = 0;      // player starts at frame 0
	//const int   IDLE_END_FRAME = 9;        // player animation frames 0-9
}

class Player : public Entity
{
public:
	Player();
	// ~Player();
	virtual void draw();
	virtual bool initialize(Input *inputPtr, int width, int height, int ncols,
		TextureManager *textureM, Graphics *graphicPtr);
	void update(float frameTime);

	void damage(WEAPON);

	virtual void handleInput(Input* input);
	/*{
		state->handleInput(*this, input);
	};*/

	//virtual bool getState() { return state; }
	//virtual void setState(PlayerState* currentState) { state = currentState; }

private:

	// Player's state
	PlayerState* state;

	// The player's current position (top-left co-ordinate of sprite)
	float playerX, playerY;

	// The amount of upward force to apply when the player first presses jump
	float jumpStartSpeedY;

	// The amount of Y acceleration to apply on each frame due to the force of gravity
	float accY;

	// True if currently jumping (prevents the player jumping while in mid-air)
	bool jumping;

	// HealthComponent healthcomponent;
	// MovementComponent movementcomponent;
};

#endif