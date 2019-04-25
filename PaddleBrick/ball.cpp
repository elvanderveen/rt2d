/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "ball.h"
#include "paddle.h"
#include "brick.h"

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

	if (this->position.x - (this->sprite()->size.x * scale.x / 2) < 0 || this->position.x + (this->sprite()->size.x * scale.x / 2) > SWIDTH) {
		velocity.x = -velocity.x;
	}
	if (this->position.y - (this->sprite()->size.y * scale.y / 2) < 0 || this->position.y + (this->sprite()->size.y * scale.y / 2) > SHEIGHT) {
		velocity.y = -velocity.y;
	}

	this->position += this->velocity * deltaTime;

	//if (this->position.y > SHEIGHT - 25) {
	//	this->velocity.y *= -1; //onderkantScherm
	//}	

	//if (this->position.y < 0 + 25) {
	//	this->velocity.y *= -1; //bovenkantScherm
	//}

	//if (this->position.x > SWIDTH - 25) {
	//	this->velocity.x *= -1; //rechterantScherm
	//}

	//if (this->position.x < 0 + 25) {
	//	this->velocity.x *= -1; //linkerkantScherm
	//}
	
	//bool collision (Ball, Brick) {
	//float  position.x = 
	//float position.y = 
	//}

	

	
}
//
//bool circle2rectangle(const Ball& Ball, const Paddle& paddle) {
//	float mx = std::max(Paddle.x, std::min(Ball.x, Paddle.x + Paddle.width));
//	float my = std::max(Paddle.y, std::min(Ball.y, Paddle.y + Paddle.height)); 
//	float dx = Ball.x - mx;
//	float dy = Ball.y - my;
//	return (dx * dx + dy * dy) < (Ball.radius * Ball.radius);
//}

bool Ball::CircleParamater(int dosomething) {
	return true;
}


bool Ball::OnCollisionEnter(Entity * other)
{
	if (this->position.x < other->position.x + other->sprite()->size.x * other->scale.x &&
		this->position.x + this->sprite()->size.x > other->position.x &&
		this->position.y < other->position.y + other->sprite()->size.y * other->scale.y &&
		this->sprite()->size.y * this->scale.y + this->position.y > other->position.y) 
	{
		return true;
	}
	return false;

}
bool Ball::OnCollisionEnterBrick(Brick * brick)
{
	if (this->position.x < brick->position.x + brick->sprite()->size.x * brick->scale.x &&
		this->position.x + this->sprite()->size.x > brick->position.x &&
		this->position.y < brick->position.y + brick->sprite()->size.y * brick->scale.y &&
		this->sprite()->size.y * this->scale.y + this->position.y > brick->position.y)
	{
		return true;
	}
	return false;


}
