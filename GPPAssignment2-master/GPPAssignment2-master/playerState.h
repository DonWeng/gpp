#ifndef _PLAYERSTATE_H                 // Prevent multiple definitions if this 
#define _PLAYERSTATE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
class Player;

// PlayerState interface
class PlayerState
{
public:
	virtual ~PlayerState() {}
	virtual void enter(Player& player) {}
	virtual PlayerState* handleInput(Player& player, Input* input) { return NULL; }
	//	virtual void update(Player& player) {}
		//States
		//static IdleState idle;
		//static MoveState move;
		//static ShootState shoot;
		//static JumpState jump;
		//static HurtState hurt;
		//static DeathState death;
};

class IdleState : public PlayerState
{
public:

	virtual void enter(Player& player);
	virtual PlayerState* handleInput(Player& player, Input* input);

private:
	const int	IDLE_START_FRAME = 0;
	const int	IDLE_END_FRAME = 9;

};


class MoveState : public PlayerState
{
public:

	virtual void enter(Player& player);
	virtual PlayerState* handleInput(Player& player, Input* input);

private:
	const int   MOVE_START_FRAME = 10;      // player starts at frame 10
	const int   MOVE_END_FRAME = 19;        // player animation frames 10-19
};

class ShootState : public PlayerState
{
public:

	virtual void enter(Player& player);
	virtual PlayerState* handleInput(Player& player, Input* input);

private:
	const int   SHOOT_START_FRAME = 20;      // player starts at frame 0
	const int   SHOOT_END_FRAME = 29;        // player animation frames 0-9
};


class JumpState : public PlayerState
{
public:

	virtual void enter(Player& player);

	virtual PlayerState* handleInput(Player& player, Input* input);

private:
	const int   JUMP_START_FRAME = 40;      // player starts at frame 40
	const int   JUMP_END_FRAME = 0;        // player animation frames 0

};


class HurtState : public PlayerState
{
public:

	virtual void enter(Player& player);

	// if... collision with enemy

private:
	const int   HURT_START_FRAME = 30;      // player starts at frame 30
	const int   HURT_END_FRAME = 39;        // player animation frames 30-39


};


class DeathState : public PlayerState
{
public:
	bool isDead = false;
	virtual void enter(Player& player) {}
	// if... no of hearts is 0
};

#endif