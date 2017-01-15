/*
player(s)'s city is invaded by alien spaceships in the sky
sudddenly wormholes appear above the player and drop magical wheels of alien-destroying cheese
also drops a note in English that tells the player(s) to throw the cheese, and 
then the game starts after player presses a button

this game intentionally does not make sense

Main Menu:
* Press S to play 'Throw the Cheese' (1 player)
* Press D to play 'Throw the Cheese Together' (2 players)
* Press F to show credits (optional)

Instructions is shown before the game starts (during intro) so player(s) won't miss the instructions
Controls are shown during instructions and during the game so player(s) won't forget

if 2 player, color code them red and blue for clarity

*/ 

#include "ThrowTheCheese.h"

//=============================================================================
// Constructor
//=============================================================================
ThrowTheCheese::ThrowTheCheese()
{}

//=============================================================================
// Destructor
//=============================================================================
ThrowTheCheese::~ThrowTheCheese()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void ThrowTheCheese::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

	//object and texture initialization
	/*
    // game item texture 
    if (!exampleTexture.initialize(graphics, EXAMPLE_OBJECT_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing example texture"));

    if (!exampleImage.initialize(graphics,0,0,0,&exampleTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing example image"));

	//initialize object
	if (!exampleObject.initialize(this, ObjectNS::WIDTH, ObjectNS::HEIGHT, ObjectNS::TEXTURE_COLS, &exampleTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing example object"));
	//lines to manipulate object (if any)
	exampleObject.setFrames(ObjectNS::START_FRAME, ObjectNS::END_FRAME);
	exampleObject.setCurrentFrame(ObjectNS::START_FRAME); 
	exampleObject.setX(GAME_WIDTH / 4);
	exampleObject.setY(GAME_HEIGHT / 4);
	//set velocity, set speed, set size, etc etc
	*/

	if (!groundTexture.initialize(graphics, GROUND_TILESET_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground texture"));

	if (!cheeseTexture.initialize(graphics, CHEESE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cheese texture"));

	if (!spaceshipTexture.initialize(graphics, SPACESHIP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spaceship texture"));

	if (!ground.initialize(graphics, 0, 0, 0, &groundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground tiles"));

	if(!cheese.initialize(this, ObjectNS::WIDTH, ObjectNS::HEIGHT, ObjectNS::TEXTURE_COLS, &cheeseTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cheese game object"));

	if (!enemy_spaceship.initialize(this, ObjectNS::WIDTH, ObjectNS::HEIGHT, ObjectNS::TEXTURE_COLS, &spaceshipTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spaceship game object"));

	ground.setX(0);
	ground.setY(GROUND_LEVEL_HEIGHT);		//sets ground to 3/4 of game width

	cheese.setX(GAME_WIDTH / 2);
	cheese.setY(GROUND_LEVEL_HEIGHT - CHEESE_HEIGHT);

	enemy_spaceship.setFrames(SpaceshipNS::START_FRAME, SpaceshipNS::END_FRAME);
	enemy_spaceship.setCurrentFrame(SpaceshipNS::START_FRAME);
	enemy_spaceship.setX(GAME_WIDTH / 4);
	enemy_spaceship.setY(GAME_HEIGHT / 4);

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void ThrowTheCheese::update()
{
	//exampleObject.update(frameTime);
	cheese.update(frameTime);
	enemy_spaceship.update(frameTime);
	//other update mechanics here

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void ThrowTheCheese::ai()
{

	//no ai

}

//=============================================================================
// Handle collisions
//=============================================================================
void ThrowTheCheese::collisions()
{
    VECTOR2 collisionVector;
    
	//loop for multiple objects
		//if object collides with thing
			//do thing

	/*if (ship1.collidesWith(planet, collisionVector))
	{
		// bounce off planet
		ship1.bounce(collisionVector, planet);
		ship1.damage(PLANET);
	}*/


}

//=============================================================================
// Render game items
//=============================================================================
void ThrowTheCheese::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    ground.draw();                   // add the object to the scene
	cheese.draw();					//in real game, cheese should be drawn later, when wormhole appears
	enemy_spaceship.draw();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void ThrowTheCheese::releaseAll()
{
	exampleTexture.onLostDevice();
	cheeseTexture.onLostDevice();
	groundTexture.onLostDevice();
	spaceshipTexture.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void ThrowTheCheese::resetAll()
{
    exampleTexture.onResetDevice();
	cheeseTexture.onResetDevice();
	groundTexture.onResetDevice();
	spaceshipTexture.onResetDevice();
    Game::resetAll();
    return;
}