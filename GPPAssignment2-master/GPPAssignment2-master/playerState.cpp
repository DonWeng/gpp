#include "playerState.h"
#include "player.h"

//=============================================================================
// Idle State
//=============================================================================
PlayerState* IdleState::handleInput(Player& player, Input* input)
{
	if (input->isKeyDown(VK_RIGHT)) // MOVE
	{
		return new MoveState();
	}

	else if (input->isKeyDown(VK_LEFT)) // MOVE
	{
		// velocity.x = playerNS::SPEED;

		return new MoveState();
	}

	else if (input->isKeyDown(VK_UP)) // JUMP
	{
		// velocity.y = playerNS::SPEED;
		return new JumpState();
		//setLoop(false);
	}

	else if (input->isKeyDown(VK_LBUTTON)) // SHOOT
	{
		return new ShootState();
	}

	return NULL; // remain in this state

}

void IdleState::enter(Player &player)
{
	player.setFrames(IDLE_START_FRAME, IDLE_END_FRAME);
	player.setCurrentFrame(IDLE_START_FRAME);
}

//=============================================================================
// Move State
//=============================================================================

void MoveState::enter(Player& player)
{
	player.setFrames(MOVE_START_FRAME, MOVE_END_FRAME);
	player.setCurrentFrame(MOVE_START_FRAME);
}

PlayerState* MoveState::handleInput(Player& player, Input* input)
{
	if (input->isKeyDown(NULL))
	{
		return new IdleState();
	}
	else
	{
		return NULL;
	}
}

//=============================================================================
// Jump State
//=============================================================================
void JumpState::enter(Player& player)
{
	player.setFrames(JUMP_START_FRAME, JUMP_END_FRAME);
	player.setCurrentFrame(JUMP_START_FRAME);
}

PlayerState* JumpState::handleInput(Player& player, Input* input)
{
	if (input->isKeyDown(NULL))
	{
		return new IdleState();
	}

	return NULL;

}


//=============================================================================
// Shoot State
//=============================================================================
void ShootState::enter(Player& player)
{
	player.setFrames(SHOOT_START_FRAME, SHOOT_END_FRAME);
	player.setCurrentFrame(SHOOT_START_FRAME);
}
PlayerState* ShootState::handleInput(Player& player, Input* input)
{
	if (input->isKeyDown(NULL))
	{

		return new IdleState();
	}

	return NULL;

}

//=============================================================================
// Hurt State
//=============================================================================
void HurtState::enter(Player& player)
{
	player.setFrames(HURT_START_FRAME, HURT_END_FRAME);
	player.setCurrentFrame(HURT_START_FRAME);
}