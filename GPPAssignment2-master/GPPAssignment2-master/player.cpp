#include "player.h"

Player::Player() : Entity()
{
	spriteData.width = playerNS::WIDTH;           // size of Player
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;                   // location on screen
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = playerNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = playerNS::PLAYER_ANIMATION_DELAY;
	startFrame = playerNS::PLAYER_START_FRAME;     // first frame of player animation
	endFrame = playerNS::PLAYER_START_FRAME;     // last frame of player animation
	currentFrame = startFrame;
	radius = playerNS::WIDTH / 2.0;
	mass = playerNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 1;

	// Set default player position
	playerX = 200.f;
	playerY = 150.f;

	// Set acceleration and speed
	float mScale = 60.f;

	// Set jump and gravity forces
	jumpStartSpeedY = 100.f * mScale;
	accY = 3.f * mScale;

	jumping = false;

}

bool Player::initialize(Input *inputPtr, int width, int height, int ncols,
	TextureManager *textureM, Graphics *graphicPtr)
{
	return(Entity::initialize(inputPtr, width, height, ncols, textureM, graphicPtr));
	state = new IdleState();
}

//=============================================================================
// draw the player
//=============================================================================
void Player::draw()
{
	Image::draw();              // draw player
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Player::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x += frameTime * velocity.x;         // move player along X 
	spriteData.y += frameTime * velocity.y;         // move player along Y

	// Player out of horizontal bound code moved to scrolling

	// Screen edge collision

	if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT*getScale())  // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - playerNS::HEIGHT*getScale();  // position at bottom screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}

}

//=============================================================================
// damage
//=============================================================================
void Player::damage(WEAPON weapon)
{

}

//=============================================================================
// Handle Input
//=============================================================================
void Player::handleInput(Input* input)
{
	//state->handleInput(*this, input);

	if (input->isKeyDown(VK_RIGHT))
	{
		velocity.x = playerNS::SPEED;
	}
	else if (input->isKeyDown(VK_LEFT))
	{
		velocity.x = -playerNS::SPEED;
	}
	else if (input->isKeyDown(VK_UP) && jumping == false)
	{
		jumping = true;
		velocity.y = -jumpStartSpeedY;
	}
	else
	{
		velocity.x = 0;                         // velocity X
		velocity.y = 0;							// velocity y
	}

	if (!input->isKeyDown(VK_UP))
	{
		jumping = false;
	}
	velocity.y += accY; // going back down

	/*
	PlayerState* currentState = state->handleInput(*this, input);

	//	state->enter(*this);
	//}

		state->enter(*this);
	}
	*/

	//playerState state;
	//switch (state)
	//{
	//case IdleState: // default state
		//if (input->isKeyDown(VK_RIGHT)) // MOVE
		//{
		//	velocity.x = playerNS::SPEED;
		//	state = MoveState;
		//}

		//else if (input->isKeyDown(VK_LEFT)) // MOVE
		//{
		//	velocity.x = -playerNS::SPEED;
		//	state = MoveState;
		//}

		//else if (input->isKeyDown(VK_UP)) // JUMP
		//{
		//	velocity.y = playerNS::SPEED;
		//	state = JumpState;
		//	//setFrames(jump.JUMP_START_FRAME, jump.JUMP_END_FRAME);
		//	//setCurrentFrame(jump.JUMP_START_FRAME);
		//	//setLoop(false);
		//}

		//else if (input->isKeyDown(VK_LBUTTON)) // SHOOT
		//{
		//	state = ShootState;
		//}

		//else
		//{
		//	velocity.x = 0;                             // velocity X
		//	velocity.y = 0;								// velocity y
		//}

	//case MoveState:
	//	// left or right arrow keys
	//	if (input->isKeyDown(VK_RIGHT))
	//	{
	//		velocity.x = playerNS::SPEED;
	//		state = MoveState;
	//	}
	//	else if (input->isKeyDown(VK_LEFT))
	//	{
	//		velocity.x = -playerNS::SPEED;
	//		state = MoveState;
	//	}

	//case ShootState:
	//case JumpState:
	//case HurtState:
	//case DeathState:
	//default:
	//	break;
	//}
}