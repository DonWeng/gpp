#ifndef _GAMESTATE_H            // Prevent multiple definitions if this 
#define _GAMESTATE_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "textureManager.h"
#include "image.h"
#include "input.h"
#include "graphics.h"
#include "game.h"
#include "player.h" 
#include "tile.h"
#include "playerState.h"
#include "monster.h"
#include "minion.h"

#include <vector>


namespace lucidWandererNS
{
	//Values
	const int LEVEL_WIDTH = 46;
	const int LEVEL_HEIGHT = 7;

	const int __ = -1;                  // empty tile

	//map [height][width]
	const int lvlOneMap[LEVEL_HEIGHT][LEVEL_WIDTH] =
	{
		__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,
		__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,
		__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,
		__,__,__, 3,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	//Flag
	const int FLAG_SIZE = 72;
	const int ITEMS_COL = 8;
	const int FLAG_FRAME = 51;
}

class GameState
{
//protected:
//	// common game properties
//	Graphics *graphics;         // pointer to Graphics
//	Input   *input;             // pointer to Input
//

private:
	//Only active states can call functions
	bool stateActive;

public:
	GameState();
	~GameState();

	//Overrides
	virtual void enter(Graphics* graphics, Input* input) = 0;
	virtual GameState* handleInput(Input *input) = 0;
	virtual void update(float frameTime) = 0;
	virtual void draw() = 0;
	virtual void collision() = 0;
	virtual void releaseAll() = 0;
	virtual void resetAll() = 0;
	virtual void exit() = 0;

	//Active functions
	virtual bool getActive() { return stateActive; }
	virtual void setActive(bool active) { stateActive = active; }

	// Return pointer to Graphics.
	//Graphics* getGraphics() { return graphics; }

	// Return pointer to Input.
	//Input* getInput() { return input; }

};


class MenuGameState : public GameState
{
private:
	TextureManager menuBackgroundTexture;
	Image menuBackground;

	TextureManager gameTitleTexture;
	Image gameTitle;

public:

	virtual void enter(Graphics* graphics, Input* input);
	virtual GameState* handleInput(Input *input);
	virtual void update(float frameTime);
	virtual void draw();
	virtual void collision();
	virtual void releaseAll();
	virtual void resetAll();
	virtual void exit();
	

};

class LevelGameState : public GameState
{
private:
	//background
	TextureManager backgroundTexture;
	Image sky;
	Image sky2;

	//Levvel/Map design
	TextureManager itemsTexture;
	Entity flagPoint;

	TextureManager tilesTexture;
	std::vector<Tile*> tileDirtList;
	std::vector<Tile*> tilePlatformList;
	Tile* tiles = NULL;

	//Enemies
	TextureManager blueGuardTexture;
	Monster* monster = NULL;
	
	//Player
	TextureManager playerTexture;
	Player player;
	PlayerState playerState;


	//Scrolling variable
	float mapX = 0;

	
	

public:
	
	virtual void enter(Graphics* graphics, Input* input);
	virtual GameState* handleInput(Input *input);
	virtual void update(float frameTime);
	virtual void draw();
	virtual void collision();
	virtual void releaseAll();
	virtual void resetAll();
	virtual void exit();
	

	//gets scroll X value
	void scrollX(float frameTime);

};


#endif