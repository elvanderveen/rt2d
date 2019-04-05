/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	paddle1 = new Paddle();
	paddle1->position = Point2(SWIDTH / 2, SHEIGHT / 1.25);

	// Ball

	ball = new Ball();                                                                                                              
	ball->position = Point2(SWIDTH / 2, SHEIGHT / 2);


	// BrickGrid

	bricks = std::vector<Brick*>();

	int yoffset = 50;
	int xoffset = 230;

	for (int y=0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			Brick* b = new Brick();
			b->position.x = (x * 200) + xoffset;
			b->position.y = (y * 75) + yoffset;
			this->addChild(b);
		}
	}
	//for each(Brick* b in bricks) {
	//	if (ball->OnCollisionEnter(b)) {
	//		ball->velocity.y = -ball->velocity.y;	//TestLine
	//	}
	
		// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(paddle1);
	this->addChild(ball);
	
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(paddle1);
	this->removeChild(ball);
	
	// delete myentity from the heap (there was a 'new' in the constructor)
	delete paddle1;
	delete ball;

}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	CheckCollisionPaddle();
	CheckCollisionBricks();

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	/*if (input()->getKeyDown(KeyCode::Space)) {
		myentity1->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity1->scale = Point(1.0f, 1.0f);
	}*/

	// ###############################################################
	// Rotate color
	// ###############################################################
	/*if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity1->sprite()->color;
		myentity1->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}*/		
}

void MyScene::CheckCollisionPaddle(){

	if (ball->OnCollisionEnter(paddle1)) {
		ball->velocity.y = -ball->velocity.y;
	}

}

void MyScene::CheckCollisionBricks() {

		static bool ball2brick(const Ball& ball, const Brick& brick) {
		float mx = std::max(rect.x, std::min(circle.x, rect.x + rect.width));
		float my = std::max(rect.y, std::min(circle.y, rect.y + rect.height));
		float dx = circle.x - mx;
		float dy = circle.y - my;
		return (dx * dx + dy * dy) < (circle.radius * circle.radius);
	}

	//for (int b = 0; b < bricks.size(); b++)
	//{
	//	if (ball->OnCollisionEnter(bricks[b])) {
	//		ball->velocity.y = -ball->velocity.y;	//TestLine
	//	}
	//	
	//}

	// for-loop door vector bricks
	// Brick* brickTest = .... 1 item uit de vector
	//ball-OnCollisionEnter(brickTest);
	//*if (ball->OnCollisionEnter(bricks)) {
	//	ball->velocity.y = -ball->velocity.y;
	//}*

}