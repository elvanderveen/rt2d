/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "ball.h"
#include "paddle.h"

Ball::Ball() : Entity()
{
	this->addSprite("assets/ball.tga");
	this->sprite()->color = RED;
	this->velocity = Vector2(200,-400);
	this->scale = Point(.5, .5);
}
Ball::~Ball()
{

}

/* if ((position.y - radius ) < 0) */
void Ball::update(float deltaTime)
{
	this->position += this->velocity * deltaTime;

	if (this->position.y > SHEIGHT - 25) {
		this->velocity.y *= -1; //onderkantScherm
	}	

	if (this->position.y < 0 + 25) {
		this->velocity.y *= -1; //bovenkantScherm
	}

	if (this->position.x > SWIDTH - 25) {
		this->velocity.x *= -1; //rechterantScherm
	}

	if (this->position.x < 0 + 25) {
		this->velocity.x *= -1; //linkerkantScherm
	}



	/*if (Ball.y > SHEIGHT - ballRadius || x + dx < ballRadius) {
		dx = -dx;
	}
	if (y + dy > SWIDTH - ballRadius || y + dy < ballRadius) {
		dy = -dy;
	}*/

	
}