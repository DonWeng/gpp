

#include "tile.h"


Tile::Tile() : Entity()
{
	spriteData.x = 0;
	spriteData.y = 0;
	spriteData.width = TILE_SIZE;
	spriteData.height = TILE_SIZE;
	spriteData.rect.bottom = TILE_SIZE;
	spriteData.rect.right = TILE_SIZE;
	setCurrentFrame(startFrame);
	edge.left = -70;
	edge.top = -70;
	edge.right = 70;
	edge.bottom = 70;

	mass = tileNS::MASS;
	collisionType = entityNS::BOX;
	spriteData.scale = tileNS::SCALE;
}


bool Tile::initialize(Input *inputPtr, int width, int height, int ncols,
	TextureManager *textureM, Graphics *graphicPtr)
{
	return Entity::initialize(inputPtr, width, height, ncols,
		textureM, graphicPtr);
}

void Tile::draw()
{
	Image::draw();
}