#include "Shell.h"
//=============================================================================
// default constructor
//=============================================================================
Shell::Shell() : Entity()
{
	spriteData.width = ShellNS::WIDTH;           // size of Ship1
	spriteData.height = ShellNS::HEIGHT;
	spriteData.x = ShellNS::X;                   // location on screen
	spriteData.y = ShellNS::Y;
	spriteData.rect.bottom = ShellNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = ShellNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = ShellNS::ANIMATION_DELAY;
	startFrame = ShellNS::START_FRAME;     // first frame of ship animation
	endFrame = ShellNS::END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = ShellNS::WIDTH / 2.0;
	mass = ShellNS::MASS;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Shell::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	crosshair.initialize(gamePtr->getGraphics(), width, height, ncols, textureM);
	crosshair.setFrames(ShellNS::CROSSHAIR_START_FRAME, ShellNS::CROSSHAIR_END_FRAME);
	crosshair.setCurrentFrame(ShellNS::CROSSHAIR_START_FRAME);
	crosshair.setFrameDelay(0.1f);
	crosshair.setDegrees(ShellNS::CROSSHAIR_ROTATION_RATE);
	crosshair.setScale(0.8);
	spriteData.angle = PI / 2;
	spriteData.scale=0.08;
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Shell::draw()
{
		Image::draw();              // draw ship
		
		crosshair.draw(spriteData, graphicsNS::ALPHA50 );//gpp common test 

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Shell::update(float frameTime, Player turret)
{
	//http://jsfiddle.net/LyM87/ cannonball physics
	//if thrown
	//spriteData.angle += frameTime * ShellNS::ROTATION_RATE;

	//distance = sqrt(pow(turret.getX() - spriteData.x, 2) + pow(turret.getY() - spriteData.y, 2));

		crosshair.setDegrees(ShellNS::CROSSHAIR_ROTATION_RATE*frameTime);
	crosshair.update(frameTime);
	thrust = 0.25;
	tx = (turret.getX()+turret.getWidth()/4) - spriteData.x;
	ty = (turret.getY()) - spriteData.y;
	dist = sqrt(tx*tx + ty*ty);
	velocity.x = (tx / dist) * thrust;
	velocity.y = (ty / dist) * thrust;

	spriteData.x += velocity.x;
	spriteData.y += velocity.y;
	if (spriteData.x > GAME_WIDTH - ShellNS::WIDTH*getScale())
	{
		// position at right screen edge
		spriteData.x = GAME_WIDTH - ShellNS::WIDTH*getScale();
		velocity.x = -velocity.x;               // reverse X direction
	}
	else if (spriteData.x < 0)                  // else if hit left screen edge
	{
		spriteData.x = 0;                       // position at left screen edge
		velocity.x = -velocity.x;               // reverse X direction
	}
	// if hit bottom screen edge
	if (spriteData.y > GAME_HEIGHT - ShellNS::HEIGHT*getScale())
	{
		// position at bottom screen edge
		spriteData.y = GAME_HEIGHT - ShellNS::HEIGHT*getScale();
		velocity.y = -velocity.y;               // reverse Y direction
	}
	else if (spriteData.y < 0)                  // else if hit top screen edge
	{
		spriteData.y = 0;                       // position at top screen edge
		velocity.y = -velocity.y;               // reverse Y direction
	}
	//crosshair.setCurrentFrame(ShellNS::CROSSHAIR_START_FRAME);
	//Entity::update(frameTime);


}

