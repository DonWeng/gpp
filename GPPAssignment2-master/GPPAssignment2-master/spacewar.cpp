
#include "spaceWar.h"

//=============================================================================
// Constructor
//=============================================================================
Spacewar::Spacewar()
{}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
	
	delete currentGameState;
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

	currentGameState = new MenuGameState();

	//// player textures
	//if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture"));

	//// player
	//if(!player.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &playerTexture))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	//player.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	//player.setCurrentFrame(playerNS::PLAYER_START_FRAME);
	//player.setX(GAME_WIDTH / 10);
	//player.setY(GAME_HEIGHT - (GAME_HEIGHT/4));


	// playerStates
	// Use push and pop to change currentState
	/*switch (player.playercurrentState)
	{
	case IDLESTATE:	
		break;
	case MOVESTATE:
		break;
	case JUMPSTATE:
		break;
	case SHOOTSTATE:
		break;
	default:
		break;
	}*/

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
	handleInput();
	currentGameState->update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{
	currentGameState->collision();
   
}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites

	currentGameState->draw();

	// player.draw();
                  
	

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    
	// playerTexture.onLostDevice();

	currentGameState->releaseAll();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
	// playerTexture.onResetDevice();

	currentGameState->resetAll();

    Game::resetAll();
    return;
}



//Handle input function
void Spacewar::handleInput()
{
	GameState* state = currentGameState->handleInput(input);

	if (state != NULL)
	{
		//gameStateStack.push(state_);
		state->enter(graphics, input);

		delete currentGameState;
		currentGameState = state;
	}
}