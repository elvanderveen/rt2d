/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "brick.h"

Brick::Brick() : Entity()
{
	this->addSprite("assets/brick.tga");
	this->sprite()->color = BLUE;
	brickColour.start();
	this->toErase = false;
}
Brick::~Brick()
{

}

void Brick::update(float deltaTime)
{
	if (brickColour.seconds() > 0.0333f) {
		RGBAColor color1 = this->sprite()->color;
		this->sprite()->color = Color::rotate(color1, 0.01f);
		brickColour.start();
	}
}