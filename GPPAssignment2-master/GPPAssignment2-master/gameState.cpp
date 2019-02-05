#include "gameState.h"

//=============================================================================
// Game State
//=============================================================================
GameState::GameState()
{
	stateActive = true;
}

GameState::~GameState()
{
	
}


//=============================================================================
// Menu Game State
//=============================================================================

void MenuGameState::enter(Graphics* graphics, Input* input)
{
	setActive(true);


}

GameState* MenuGameState::handleInput(Input *input)
{
	if (input->isKeyDown(VK_DOWN))
	{
		//start game
		setActive(false);

		return new LevelGameState();
	}

	return NULL;
}

void MenuGameState::update(float frameTime)
{

}

void MenuGameState::draw()
{
	// graphics->spriteBegin();                // begin drawing sprites

	// graphics->setBackColor(graphicsNS::BLACK);

	// graphics->spriteEnd();                  // end drawing sprites
}

void MenuGameState::collision()
{

}

void MenuGameState::releaseAll() {}
void MenuGameState::resetAll() {}
void MenuGameState::exit() {}





//=============================================================================
// Level Game State
//=============================================================================

void LevelGameState::enter(Graphics* graphics, Input* input)
{
	mapX = 0;
	setActive(true);
	
	//=======================================================================================================
	//==============================================ENVIRONMENT==============================================
	//=======================================================================================================

	// backgound texture
	if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	// sky image
	if (!sky.initialize(graphics, 1759, 480, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing sky"));
	if (!sky2.initialize(graphics, 1759, 480, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing sky2"));

	
	//Tile texture
	if (!tilesTexture.initialize(graphics, TILES_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tiles texture"));

	//Tiles
	for (int x = 0; x < lucidWandererNS::LEVEL_WIDTH; x++)
	{
		tiles = new Tile();
		if (!tiles->initialize(input, tileNS::SPRITE_TILE_SIZE, tileNS::SPRITE_TILE_SIZE, tileNS::TILE_COLS, &tilesTexture, graphics))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing dirt tiles"));
		tiles->setX(x);
		tiles->setY(6 * TILE_SIZE);
		tiles->setCurrentFrame(tileNS::DIRT_FRAME);

		tileDirtList.push_back(tiles);
	}

	//Platform
	for (int x = 0; x < lucidWandererNS::LEVEL_WIDTH; x++)
	{
		tiles = new Tile();
		if (!tiles->initialize(input, tileNS::SPRITE_TILE_SIZE, tileNS::SPRITE_TILE_SIZE, tileNS::TILE_COLS, &tilesTexture, graphics))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform tiles"));
		tiles->setX(x);
		tiles->setY(TILE_SIZE * 3);
		tiles->setCurrentFrame(tileNS::PLATFORM_BLOCK_FRAME);

		tilePlatformList.push_back(tiles);
	}
	
	//Items texture
	if (!itemsTexture.initialize(graphics, ITEMS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing items texture"));

	//Flag
	if (!flagPoint.initialize(input, lucidWandererNS::FLAG_SIZE, lucidWandererNS::FLAG_SIZE, lucidWandererNS::ITEMS_COL, &itemsTexture, graphics))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing flag point"));
	flagPoint.setX(GAME_WIDTH / 2);
	flagPoint.setY(TILE_SIZE * 5);
	flagPoint.setCurrentFrame(lucidWandererNS::FLAG_FRAME);
	flagPoint.setCollisionType(entityNS::BOX);
	RECT flagBoundary;
	flagBoundary.left = -lucidWandererNS::FLAG_SIZE;
	flagBoundary.right = lucidWandererNS::FLAG_SIZE;
	flagBoundary.top = -lucidWandererNS::FLAG_SIZE;
	flagBoundary.bottom = lucidWandererNS::FLAG_SIZE;



	//=======================================================================================================
	//==============================================PLAYER===================================================
	//=======================================================================================================

	// player textures
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture"));

	// player
	if (!player.initialize(input, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &playerTexture, graphics))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	player.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	player.setCurrentFrame(playerNS::PLAYER_START_FRAME);
	player.setX(0);
	//player.setX((GAME_WIDTH / 2) - ((playerNS::WIDTH*player.getScale()) / 2));
	player.setY(GAME_HEIGHT - (GAME_HEIGHT / 4));

	//=======================================================================================================
	//==============================================ENEMY====================================================
	//=======================================================================================================

	monster = new Minion();

	// minion textures
	if (!blueGuardTexture.initialize(graphics, BLUE_GUARD_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing blue guard texture"));

	// BLUE GUARD
	if (!monster->initialize(input, monsterNS::BLUE_GUARD_WIDTH, monsterNS::BLUE_GUARD_HEIGHT, monsterNS::TEXTURE_COLS, &blueGuardTexture, graphics))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing blue guard"));
	monster->setFrames(monsterNS::BLUE_GUARD_SPAWN_START, monsterNS::BLUE_GUARD_SPAWN_END);
	monster->setCurrentFrame(monsterNS::BLUE_GUARD_SPAWN_START);
	monster->setX(GAME_WIDTH - monsterNS::BLUE_GUARD_WIDTH);
	monster->setY(GAME_HEIGHT - (GAME_HEIGHT / 4));




}


//=======================================================================================================
//==============================================LOOP=====================================================
//=======================================================================================================

GameState* LevelGameState::handleInput(Input *input)
{
	if (!getActive())
	{
		return new MenuGameState();
	}

	if (input->isKeyDown(VK_ESCAPE))
	{
		return new MenuGameState();
	}
	
	player.handleInput(input);

	return NULL;
}

void LevelGameState::update(float frameTime)
{
	player.update(frameTime);

	//scroll map and level objects
	scrollX(frameTime);

	//Update position of tiles
	for (int row = 0; row < lucidWandererNS::LEVEL_HEIGHT; row++)	//for each row of map
	{
		for (int col = 0; col < lucidWandererNS::LEVEL_WIDTH; col++)
		{
			if (lucidWandererNS::lvlOneMap[row][col] >= 0)
			{
				switch (lucidWandererNS::lvlOneMap[row][col])
				{
				case 1:
					tileDirtList[col]->setX((float)(col*TILE_SIZE) + mapX);
					tileDirtList[col]->setY((float)(row*TILE_SIZE));
					break;

				case 2:
					tilePlatformList[col]->setX((float)(col*TILE_SIZE) + mapX);
					tilePlatformList[col]->setY((float)(row*TILE_SIZE));
					break;

				}
			}
		}

	}

	//Update monsters
	monster->update(frameTime);
	
}

void LevelGameState::draw()
{
	//Scroll background
	sky.setX(mapX);
	sky2.setX(sky.getWidth() + mapX);

	//draw background
	sky.draw();
	sky2.draw();
	
	//Draw tiles in screen
	for (int a = 0; a < tileDirtList.size(); a++)
	{
		if (tileDirtList[a]->getX() > (-TILE_SIZE) && tileDirtList[a]->getX() < GAME_WIDTH)
		{
			tileDirtList[a]->draw();
		}
	}
	for (int b = 0; b < tilePlatformList.size(); b++)
	{
		if (tilePlatformList[b]->getX() > (-TILE_SIZE) && tilePlatformList[b]->getX() < GAME_WIDTH)
		{
			tilePlatformList[b]->draw();
		}
	}

	//Draw items in screen
	flagPoint.setX((GAME_WIDTH / 2) + mapX);
	if (flagPoint.getX() > (-TILE_SIZE) && flagPoint.getX() < GAME_WIDTH)
	{
		flagPoint.draw();
	}


	//Draw monster
	if (monster->checkPosition(mapX))
	{
		monster->draw();

	}

	//Draw player
	player.draw();

}

void LevelGameState::collision()
{

	VECTOR2 collisionVector;

	for (int a = 0; a < tileDirtList.size(); a++)
	{
		if (player.collidesWith(*tileDirtList.at(a), collisionVector))
		{

		}
	}

	for (int b = 0; b < tilePlatformList.size(); b++)
	{
		if (player.collidesWith(*tilePlatformList.at(b), collisionVector))
		{
			player.bounce(collisionVector, *tilePlatformList[b]);
		}
	}

	//If enemy collide with flag,
	if (flagPoint.collidesWith(*monster, collisionVector))
	{
		//kill flag
		flagPoint.damage(100);
	}



	//Check if game should end
	if (flagPoint.getHealth() < 0)
	{
		setActive(false);

	}

}

//=======================================================================================================
//==============================================ENDING FUNCTIONS==============================================
//=======================================================================================================

void LevelGameState::releaseAll() 
{
	backgroundTexture.onLostDevice();
	playerTexture.onLostDevice();
	blueGuardTexture.onLostDevice();
}

void LevelGameState::resetAll() 
{
	backgroundTexture.onResetDevice();
	playerTexture.onResetDevice();
	blueGuardTexture.onResetDevice();
}

void LevelGameState::exit() 
{
	for (auto it = tileDirtList.begin(); it != tileDirtList.end(); )
	{
		if (!getActive())
		{
			SAFE_DELETE(*it);
			it = tileDirtList.erase(it);
		}
	}
	for (auto it = tilePlatformList.begin(); it != tilePlatformList.end(); )
	{
		if (!getActive())
		{
			SAFE_DELETE(*it);
			it = tilePlatformList.erase(it);
		}
	}


	SAFE_DELETE(monster);
	SAFE_DELETE(tiles);
	
	releaseAll();

}



//=======================================================================================================
//==============================================OTHERS==============================================
//=======================================================================================================


void LevelGameState::scrollX(float frameTime)
{

	//Player position
	float playerX = player.getX();
	//Player Width
	float playerW = player.getWidth() * player.getScale();

	//if player on left side of screen
	if (playerX < (GAME_WIDTH / 2) - (playerW / 2))
	{
		//scroll map right
		mapX += playerNS::SPEED * frameTime;
	}
	//if player on right side of screen
	else if (playerX > (GAME_WIDTH / 2) - (playerW / 2))
	{
		//scroll map left
		mapX -= playerNS::SPEED * frameTime;
	}

	//If map is past left edge
	if (mapX > 0)
	{
		//stop at left edge of map
		mapX = 0;

		
		

	}
	//If map is past right edge
	else if (mapX < (-LEVEL_EXTENT_X) + GAME_WIDTH)
	{
		//stop at right edge of map
		mapX = GAME_WIDTH - LEVEL_EXTENT_X;

		
		
	}
	//If map is not past either edge, set player back to center
	else
	{
		player.setX((GAME_WIDTH / 2) - (playerW / 2));
	}

	//stop player if they are past the left edge
	if (playerX < 0)
	{
		player.setX(0);
	}
	//if player is past right edge, stop them
	else if (playerX > GAME_WIDTH - playerW)
	{
		player.setX(GAME_WIDTH - playerW);
	}


}

