/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "paddle.h"

 Paddle::Paddle() : Entity() 
{
	this->addSprite("assets/paddle.tga");
	this->sprite()->color = RED;
}
Paddle::~Paddle()
{
	
}

void Paddle::update(float deltaTime)
{
	if (this->position.x >= 64 && this->position.x <= SWIDTH - 64) {

		if (this->input()->getKey(KeyCode::D)) {
			this->position.x += 3.0;


		}

		if (this->input()->getKey(KeyCode::A)) {
			this->position.x += -3.0;
		}
	}

	if (this->position.x <= 64) {
		this->position.x += 1;
	}
	if (this->position.x >= SWIDTH - 64) {
		this->position.x -= 1;
	}
}