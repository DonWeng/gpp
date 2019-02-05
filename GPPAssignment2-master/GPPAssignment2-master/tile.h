


#ifndef _TILE_H
#define _TILE_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace tileNS {
	//COLUMNS
	const int TILE_COLS = 12;
	const int SPRITE_TILE_SIZE = 72;

	//FRAMES
	const int PLATFORM_BLOCK_FRAME = 117;
	const int DIRT_FRAME = 103;


	//Other attribute of tiles
	const float MASS = 300.0f;
	const float SCALE = 1.0f;
}

class Tile : public Entity
{
public:
	//Constructor
	Tile();

	//Functions
	virtual void draw();
	virtual bool initialize(Input *inputPtr, int width, int height, int ncols,
		TextureManager *textureM, Graphics *graphicPtr);


};


#endif
