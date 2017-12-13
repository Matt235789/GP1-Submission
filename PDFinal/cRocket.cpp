/*
=================
cRocket.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cRocket.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cRocket::cRocket() : cSprite()
{
	this->rocketVelocity = { 0, 0 };
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cRocket::update(double deltaTime)
{

	FPoint direction = { 0.0f, 0.0f };

	SDL_Rect currentSpritePos = this->getSpritePos();
	currentSpritePos.x += this->rocketVelocity.x;
	currentSpritePos.y += this->rocketVelocity.y;

	this->rocketVelocity.x *= 0.95;
	this->rocketVelocity.y *= 0.95;

	this->setSpritePos({ currentSpritePos.x , currentSpritePos.y });
	this->setBoundingRect(this->getSpritePos());

	// move rocket back after going past certain co-ordinate
	if (getSpritePos().x < 0 - getBoundingRect().x)
	{
		setSpritePos({ getSpritePos().x + 10, getSpritePos().y });
	}
	if (getSpritePos().x > 1880 - getBoundingRect().x)
	{
		setSpritePos({ getSpritePos().x - 10, getSpritePos().y });
	}
}
/*
=================================================================
Sets the velocity for the rocket
=================================================================
*/
void cRocket::setRocketVelocity(SDL_Point rocketVel)
{
	rocketVelocity = rocketVel;
}
/*
=================================================================
Gets the rocket velocity
=================================================================
*/
SDL_Point cRocket::getRocketVelocity()
{
	return rocketVelocity;
}

