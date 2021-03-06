// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }

#define TRANSCOLOR SETCOLOR_ARGB(0,255,0,255)  // transparent color (light magenta)


//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Spacewar";
const char GAME_TITLE[] = "Lucid Wanderer";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  640;               // width of game in pixels
const UINT GAME_HEIGHT = 480;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant
const float MASS_PLANET = 1.0e14f;
const float MASS_SHIP = 5.0f;

// Lucid Wanderer Constants
const float LEVEL_EXTENT_X = GAME_WIDTH * 5;
const int TILE_SIZE = 70;

// graphic images
//const char NEBULA_IMAGE[] =   "pictures\\orion.jpg";     // photo source NASA/courtesy of nasaimages.org 
//const char SHIP_IMAGE[] = "pictures\\spaceship.png";  // ship texture
//const char ASTEROID_IMAGE[] = "pictures\\asteroids.png"; //asteroid texture

//MAIN MENU IMAGES
const char TITLE_IMAGE[] = "pictures\\title_screen.jpeg";	//Title
const char MENU_BACKGROUND_IMAGE[] = "pictures\\grid_bg.png";	//Background of menu


//LEVEL IMAGES
const char PLAYER_IMAGE[] = "pictures\\player.png"; //player texture
const char BACKGROUND_IMAGE[] = "pictures\\backgrounds.png"; //background texture
const char TILES_IMAGE[] = "pictures\\tiles_spritesheet.png";	//tiles texture
const char ITEMS_IMAGE[] = "pictures\\items_spritesheet.png";	//item texture
const char BLUE_GUARD_IMAGE[] = "pictures\\guardBlue64.png";	//minion texture

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY      = VK_MENU;         // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;       // Enter key

// weapon types
enum WEAPON {TORPEDO, SHIP, PLANET};

#endif
