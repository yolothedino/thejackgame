// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>

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
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Descent";
const char GAME_TITLE[] = "Descent";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 540;               // width of game in pixels
const UINT GAME_HEIGHT = 640;               // height of game in pixels

// game
const double ADAPTCIRCLE = 160;
const double FIXANGLE = 10;
const double PI = 3.14159265;
const double RADTODEGREE = PI / 180;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 225.5f;             // gravitational constant
const float MASS_PLANET = 5000.0;
const float MASS_SPACE_SHIP = 5.0f;		//number subject to change
const float MASS_PLAYER = 5.0f;			//number subject to change

//player(tank) variables
const int PLAYER_WIDTH = 81;
const int PLAYER_HEIGHT = 64;
const int PLAYER_TEXTURE_COLUMNS = 4;
const int PLAYER_START_FRAME = 0;
const int PLAYER_END_FRAME = 3;
const float PLAYER_MASS = 50.0f;				//number subject to change - idk what to put here
const float PLAYER_ANIMATION_DELAY = 0.2f;		//note: make player animate only when moving and throwing
const float PLAYER_BASE_STRENGTH = 25.0f;		//base strength, related to player throwing
const float PLAYER_BASE_SPEED = 100.0f;
const float PLAYER_MAX_HEALTH = 100;			//for dynamic health values, should represent health as a number
const int PLAYER_DAMAGE_TAKEN_MODIFIER = 1;

//player(tank) health
const int PLAYER_HEALTH_WIDTH = 28;
const int PLAYER_HEALTH_HEIGHT = 8;
const int PLAYER_HEALTH_TEXTURE_COLUMNS = 1;
const int PLAYER_HEALTH_START_FRAME = 0;
const int PLAYER_HEALTH_END_FRAME = 0;

//cannonball variables
const int CANNONBALL_WIDTH = 32;
const int CANNONBALL_HEIGHT = 32;
const int CANNONBALL_TEXTURE_COLUMNS = 1;
const int CANNONBALL_START_FRAME = 0;
const int CANNONBALL_END_FRAME = 1;
const float CANNONBALL_MASS = 1200.0f;				//number subject to change - idk what to put here
const float CANNONBALL_BASE_SPEED = 200.0f;			//base speed that CANNONBALL always moves on, MAY NOT BE RELEVANT DEPENDING ON HOW WE CALCULATE SPEED 
const float CANNONBALL_ANIMATION_DELAY = 0.2f;		//note: maybe Cannonball animates when moving 
const int CANNONBALL_DAMAGE = 5;
const double CANNONBALL_FORCE_POWER_DAMAGE_FACTOR = 0.5;	//how much of force is actual damage

//charging bar variabbles
const int CHARGINGBAR_WIDTH = 28;
const int CHARGINGBAR_HEIGHT = 8;
const int CHARGINGBAR_TEXTURE_COLUMNS = 1;
const int CHARGINGBAR_START_FRAME = 0;
const int CHARGINGBAR_END_FRAME = 0;

//refers to a wormhole/blackhole image, is not an actual object. Remove if confirmed to go for tank theme instead of Cannonball theme
//can also incorporate to 'explain' arrival of spaceships
//not priority
const int WORMHOLE_Y = 25;
const int WORMHOLE_WIDTH = 200;
const int WORMHOLE_HEIGHT = 200;
const int WORMHOLE_TEXTURE_COLUMNS = 1;
const int WORMHOLE_START_FRAME = 0;
const int WORMHOLE_END_FRAME = 0;
const float WORMHOLE_ROTATION_RATE = (float)PI*4;
const float WORMHOLE_ANIMATION_DELAY = 0.1f;		//animation can look very cool

//spaceship variables
const int SPACESHIP_WIDTH = 58;
const int SPACESHIP_HEIGHT = 32;
const int SPACESHIP_TEXTURE_COLUMNS = 12;
const int SPACESHIP_START_FRAME = 0;
const int SPACESHIP_END_FRAME = 11;
const int SPACESHIP_DAMAGED_START_FRAME = 12;
const int SPACESHIP_DAMAGED_END_FRAME = 23;
const float SPACESHIP_MASS = 50.0f;				//number subject to change - idk what to put here
const float SPACESHIP_SPEED = 50.0f;
const float SPACESHIP_ANIMATION_DELAY = 0.1f;		//passively animates
const int SPACESHIP_STARTING_HEALTH = 5;
const double SPACESHIP_MOVEMENT_DISTANCE = 14.5;
const double SPACESHIP_MOVE_FREQUENCY = 1;
const int SPACESHIP_ATTACK_FREQUENCY = 1;
const double SPACESHIP_CRITICAL_HEALTH_FACTOR = 0.25;
const int SPACESHIP_REWARD_SCORE = 333;
const double SPACESHIP_REWARD_COMBO_MULTIPLIER = 1;		//amt of points multiplied for collateral kills
const int HORIZONTAL_GAP_LENGTH_BETWEEN_SPACESHIPS = 80;	//this affects how much ships can be created in a row, if values are too high will lead to weird spaceship orientation
const int VERTICAL_GAP_LENGTH_BETWEEN_SPACESHIPS = 20;

//SPACESHIP_BULLET variables
const int SPACESHIP_BULLET_WIDTH = 6;
const int SPACESHIP_BULLET_HEIGHT = 12;
const int SPACESHIP_BULLET_TEXTURE_COLUMNS = 2;
const int SPACESHIP_BULLET_START_FRAME = 0;
const int SPACESHIP_BULLET_END_FRAME = 1;
const float SPACESHIP_BULLET_SPEED = 150.0f;
const float SPACESHIP_BULLET_ANIMATION_DELAY = 0.2f;
const int SPACESHIP_BULLET_DAMAGE = 10;
const int MAX_NO_OF_SPACESHIP_BULLETS = 10;

//spaceship spawn variables
const int MAX_NO_OF_SPACESHIPS = 60; //number of spaceships allowed to exist at any time
const int AMT_OF_SPACESHIPS_PER_ROW = 5; //number should not be less than GAME_WIDTH/(SPACESHIP_WIDTH + HORIZONTAL_GAP_LENGTH_BETWEEN_SPACESHIPS)
const int WAVE_1_SPACESHIPS_AMT_OF_ROWS = 4;
const int WAVE_2_SPACESHIPS_AMT_OF_ROWS = 5;
const int WAVE_3_SPACESHIPS_AMT_OF_ROWS = 6;

const int WAVE_1_MAX_AMOUNT_OF_SPACESHIP_BULLETS_PER_VOLLEY = 4;		//bullet hell limiter
const int WAVE_2_MAX_AMOUNT_OF_SPACESHIP_BULLETS_PER_VOLLEY = 4;		//bullet hell limiter
const int WAVE_3_MAX_AMOUNT_OF_SPACESHIP_BULLETS_PER_VOLLEY = 6;		//bullet hell limiter

const double WAVE_1_SPACESHIPS_FIRE_CHANCE = 10;				//measured in percentages
const double WAVE_2_SPACESHIPS_FIRE_CHANCE = 10;					//measured in percentages
const double WAVE_2_SPACESHIPS_FIRE_INTELLIGENT_CHANCE = 25;	//measured in percentages
const double WAVE_3_SPACESHIPS_FIRE_CHANCE = 25;					//measured in percentages
const double WAVE_3_SPACESHIPS_FIRE_INTELLIGENT_CHANCE = 30;	//measured in percentages

const int WAVE_1_SPACESHIPS_HEALTH = 20;
const int WAVE_2_SPACESHIPS_HEALTH = 30;
const int WAVE_3_SPACESHIPS_HEALTH = 40;

const int PRE_WAVE_WAITING_TIME = 3;
const int PRE_WAVE_TEXT_X = 20;
const int PRE_WAVE_TEXT_Y = 150;


//boss spaceship variables
const int BOSS_SPACESHIP_WIDTH = 212;
const int BOSS_SPACESHIP_HEIGHT = 265;
const int BOSS_SPACESHIP_TEXTURE_COLUMNS = 3;
const int BOSS_SPACESHIP_START_FRAME = 0;
const int BOSS_SPACESHIP_END_FRAME = 2;
const float BOSS_SPACESHIP_ANIMATION_DELAY = 1.0f;
const int BOSS_SPACESHIP_STARTING_HEALTH = 300;

//powerup variables
const int POWERUP_WIDTH = 36;
const int POWERUP_HEIGHT = 36;
const int POWERUP_TEXTURE_COLUMNS = 2;
const int POWERUP_START_FRAME = 0;
const int POWERUP_END_FRAME = 0;
const float POWERUP_ANIMATION_DELAY = 0.25f;
const float POWERUP_ROTATION_RATE = (float)PI / 4;
const int POWERUP_MOVEMENT_SPEED = 200;
const int POWERUP_SPAWN_CHANCE = 25;			//in percentage, spawn chance when a spaceship is destroyed
const int POWERUP_SPAWN_FREQUENCY = 5;			//in seconds, value depicts if powerup spawns every X seconds
const int POWERUP_SPAWN_HEIGHT = GAME_WIDTH / 2;
const int POWERUP_REWARD_SCORE = 25;
const int MAX_NO_OF_POWERUPS = 1;
const int POWERUP_OBJECT_DURATION = 5;		//how long the powerup stays as an ingame object before expiring
const int POWERUP_BLINKING_END_FRAME = 1;
const int POWERUP_START_BLINKING_TIME_MARK = 3;	//at what secondsPassed does the powerup starts blinking to show it is close to expiring

//individual powerup effect values
const double POWERUP_TIME_SLOW_MULTIPLER = 2; //the bigger the number the slower it gets
const int POWERUP_TIME_SLOW_DURATION = 10;
const int POWERUP_TIME_SLOW_CODE = 1;

const int POWERUP_SHIELD_DAMAGE_MODIFIER = 0;	//damageTaken*(this value)
const int POWERUP_SHIELD_DURATION = 5;
const int POWERUP_RESTORE_HEALTH_CODE = 2;

const double POWERUP_INCREASE_TANK_SPEED_FACTOR = 2; //the higher the number the faster (too high = too fast)
const int POWERUP_INCREASE_TANK_SPEED_DURATION = 5;
const int POWERUP_INCREASE_TANK_SPEED_CODE = 3;

const int POWERUP_TIME_LOCK_DURATION = 5; //in seconds
const int POWERUP_TIME_LOCK_FACTOR = 0; //anything that is not 0 means this isn't working gracefully
const int POWERUP_TIME_LOCK_CODE = 1;
const int POWERUP_TIME_LOCK_UNLOCK_SOUND_DURATION = 3;

const int POWERUP_MAX_POWER_DURATION = 5;
const int POWERUP_MAX_POWER_CODE = 5;

const int POWERUP_TANK_ASSIST_DURATION = 10;			//spawns an allied tank that moves across X at ground level and periodically shoots weak bullets at spaceships, cannot be destroyed but is temporary
const int POWERUP_TANK_ASSIST_CODE = 2;

//helpful turret variables
const int ASSIST_TANK_WIDTH = 64;
const int ASSIST_TANK_HEIGHT = 64;
const int ASSIST_TANK_TEXTURE_COLUMNS = 2;
const int ASSIST_TANK_START_FRAME = 0;
const int ASSIST_TANK_END_FRAME = 1;
const float ASSIST_TANK_ANIMATION_DELAY = 0.2f;

const int ASSIST_TANK_ATTACK_FREQUENCY = 1;			//fires every X seconds
const float ASSIST_TANK_MOVEMENT_SPEED = 100.0f;

//ASSIST_TANK_BULLET variables
const int ASSIST_TANK_BULLET_WIDTH = 6;
const int ASSIST_TANK_BULLET_HEIGHT = 12;
const int ASSIST_TANK_BULLET_TEXTURE_COLUMNS = 2;
const int ASSIST_TANK_BULLET_START_FRAME = 0;
const int ASSIST_TANK_BULLET_END_FRAME = 1;
const float ASSIST_TANK_BULLET_SPEED = 200.0f;
const float ASSIST_TANK_BULLET_ANIMATION_DELAY = 0.2f;
const int ASSIST_TANK_BULLET_DAMAGE = 5;
const int MAX_NO_OF_ASSIST_TANK_BULLETS = 1;

//gameplay condition variables (affected by powerups, otherwise they generally stays the same)
const int GROUND_LEVEL_HEIGHT = GAME_HEIGHT - GAME_HEIGHT / 10;			//no objects may go beyond this line, essentially means 'ground level'
const int GAMEOVER_SPACESHIP_DISTANCE = GROUND_LEVEL_HEIGHT - 150;		//when spaceship reaches here, game over, boom
const int SKY_LEVEL_DIVIDER = 78;
const int GROUND = 560;

//gameplay modifiers
const int GAME_BASE_TIME_MODIFIER = 1;	//Base value for time modifier. affects time counter. 
const int GAME_BASE_SPEED_MODIFIER = 1; //Base value for speed modifier, affects speed (for powerups)
const int SECOND = 1;				//an ingame second equals to 1

//main menu frames
const int MENU_WIDTH = GAME_WIDTH;
const int MENU_HEIGHT = GAME_HEIGHT;
const int MENU_TEXTURE_COLUMNS = 0;
const int MENU_START_FRAME = 0;
const int MENU_END_FRAME = 1;

//pause frames
const int PAUSE_WIDTH = GAME_WIDTH;
const int PAUSE_HEIGHT = GAME_HEIGHT;
const int PAUSE_TEXTURE_COLUMNS = 0;
const int PAUSE_START_FRAME = 0;
const int PAUSE_END_FRAME = 1;

//instruction frames
const int INSTRUCTIONS_WIDTH = GAME_WIDTH;
const int INSTRUCTIONS_HEIGHT = GAME_HEIGHT;
const int INSTRUCTIONS_TEXTURE_COLUMNS = 0;
const int INSTRUCTIONS_START_FRAME = 0;
const int INSTRUCTIONS_END_FRAME = 0;

//credits frames
const int CREDITS_WIDTH = GAME_WIDTH;
const int CREDITS_HEIGHT = GAME_HEIGHT;
const int CREDITS_TEXTURE_COLUMNS = 0;
const int CREDITS_START_FRAME = 0;
const int CREDITS_END_FRAME = 0;

//game win/lose frames
const int WINLOSE_WIDTH = GAME_WIDTH;
const int WINLOSE_HEIGHT = GAME_HEIGHT;
const int WINLOSE_TEXTURE_COLUMNS = 2;
const int WINLOSE_START_FRAME = 0;
const int WINLOSE_END_FRAME = 1;

//turret frames
const int TURRET_WIDTH = 35;
const int TURRET_HEIGHT = 35;
const int TURRET_TEXTURE_COLUMNS = 7;

//smoke frames
const int SMOKE_WIDTH = 16;
const int SMOKE_HEIGHT = 32;
const int SMOKE_TEXTURE_COLS = 4;
const int SMOKE_START_FRAME = 0;
const int SMOKE_END_FRAME = 3;

//shell variables
const int SHELL_WIDTH = 400;
const int SHELL_HEIGHT = 400;
const int SHELL_START_FRAME = 0;
const int SHELL_END_FRAME = 0;
const int SHELL_TEXTURE_COLUMNS = 2;
const float SHELL_MASS = 5.0f;
const float SHELL_BASE_SPEED = 5.0f;
const float SHELL_ANIMATION_DELAY = 0.0f;
const int SHELL_DAMAGE = 30;
const int SHELL_SPAWNCOUNTER = 10;

//background frames
const int BACKGROUND_WIDTH = 540;
const int BACKGROUND_HEIGHT = 640;
const int BACKGROUND_TEXTURE_COLS = 4;
const int BACKGROUND_START_FRAME = 0;
const int BACKGROUND_END_FRAME = 3;

const int BOSSLASER_WIDTH = 8;
const int BOSSLASER_HEIGHT = 17;
const int BOSSLASER_START_FRAME = 0;
const int BOSSLASER_END_FRAME = 1;
const int BOSSLASER_TEXTURE_COLUMNS = 2;
const float BOSSLASER_ANIMATION_DELAY = 0.5f;
const float BOSSLASER_BASE_SPEED = 150.0f;
const float BOSSLASER_MASS = 5.0f;
const int BOSSLASER_DAMAGE = 10;
// graphic images
const char GROUND_TILESET_IMAGE[] = "resources\\images\\ground_tile.png";
const char CANNONBALL_IMAGE[] = "resources\\images\\cannonball.png";
const char SPACESHIP_IMAGE[] = "resources\\images\\spaceship.png";
const char MENU_IMAGE[] = "resources\\images\\menu.png";
const char PAUSE_IMAGE[] = "resources\\images\\pause.png";
const char BOSS_SPACESHIP_IMAGE[] = "resources\\images\\boss_spaceship.png";
const char TANK_IMAGE[] = "resources\\images\\tank.png";
const char TANK_HEALTH_IMAGE[] = "resources\\images\\tankHealth.png";
const char BKGRND_IMAGE[] = "resources\\images\\background.png";
const char INSTRUCTION_IMAGE[] = "resources\\images\\instruction.png";
const char TURRET_IMAGE[] = "resources\\images\\turret.png";
const char SHELL_IMAGE[] = "resources\\images\\shell.png";
const char CHARGINGBAR_IMAGE[] = "resources\\images\\chargingbar.png";
const char BOSSLASER_IMAGE[] = "resources\\images\\bosslaser.png";
const char GAME_WIN_IMAGE[] = "resources\\images\\gamewin.png";
const char GAME_LOSE_IMAGE[] = "resources\\images\\gamelose.png";
const char SPACESHIP_BULLET_IMAGE[] = "resources\\images\\spaceship_bullet.png";
const char ASSIST_TANK_IMAGE[] = "resources\\images\\assist_tank.png";
const char ASSIST_TANK_BULLET_IMAGE[] = "resources\\images\\assist_tank_bullet.png";
const char POWERUP_TIME_SLOW_IMAGE[] = "resources\\images\\powerup_timeSlow.png";
const char POWERUP_RESTORE_HEALTH_IMAGE[] = "resources\\images\\powerup_shield.png";
const char POWERUP_INCREASE_TANK_SPEED_IMAGE[] = "resources\\images\\powerup_increaseSpeed.png";
const char POWERUP_TIME_LOCK_IMAGE[] = "resources\\images\\powerup_timeLock.png";
const char POWERUP_MAX_POWER_IMAGE[] = "resources\\images\\powerup_maxPower.png";
const char POWERUP_PASSERBY_TANK_IMAGE[] = "resources\\images\\powerup_passerbyTank.png";
const char WORMHOLE_IMAGE[] = "resources\\images\\wormhole.png";
const char HISCORE_FILE[] = "resources\\highscore.txt";
const char CREDITS_IMAGE[] = "resources\\images\\credits.png";

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY = VK_MENU;         // Alt key
const UCHAR ENTER_KEY = VK_RETURN;       // Enter key
const UCHAR DOWN_KEY = VK_DOWN;
const UCHAR SPACE_KEY = VK_SPACE;
const UCHAR UP_KEY = VK_UP;
const UCHAR LEFT_KEY = VK_LEFT;
const UCHAR RIGHT_KEY = VK_RIGHT;
const UCHAR M_KEY = 0x4D;
const UCHAR TAB_KEY = VK_TAB;
const UCHAR PAUSE_KEY = 0x50;
//note - might want to change the following to more obvious names
const UCHAR O_KEY = 0x31;					//number 1
const UCHAR TW_KEY = 0x32;					//number 2
const UCHAR TH_KEY = 0x33;					//number 3
const UCHAR W_KEY = 0x57;
const UCHAR A_KEY = 0x41;
const UCHAR S_KEY = 0x53;
const UCHAR D_KEY = 0x44;
const UCHAR F_KEY = 0x46;

enum hitWho{ land, spaceShip, bossShip, player };

#endif