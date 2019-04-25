/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include<iostream>
#include<list> // for list operations 
#include "myscene.h"
using namespace std;

MyScene::MyScene() : Scene()

{
	// start the timer.
	t.start();
	ishit = false;
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	paddle1 = new Paddle();
	paddle1->position = Point2(SWIDTH / 2, SHEIGHT / 1.25);
	
	// Ball

	ball = new Ball();
	ball->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	

	// BrickGrid


	int yoffset = 50;
	int xoffset = 230;

	for (int y=0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			Brick* b = new Brick();
			b->position.x = (x * 200) + xoffset;
			b->position.y = (y * 75) + yoffset;
			this->addChild(b);
			bricks.push_back(b);
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
bool MyScene::CheckCollisionBricks(Ball* ball, Brick* brick) {

	//	bool ball2brick(Ball ball, Brick brick);
	float mx = std::max(brick->position.x, std::min(ball->position.x, brick->position.x + brick->scale.x));
	float my = std::max(brick->position.y, std::min(ball->position.y, brick->position.y + brick->scale.y));
	float dx = ball->position.x - mx;
	float dy = ball->position.y - my;
	return (dx * dx + dy * dy) < (ball->scale.x / 2 * brick->scale.x / 2);

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
	checkAmountBlocks();
	//erase();

	for (size_t i = 0; i < bricks.size(); i++)
	{
		if (ball->OnCollisionEnterBrick(bricks[i])) {
			
			ball->velocity.y = -ball->velocity.y;
			//ishit = true;
			//this->removeChild(bricks[i]);
			

			
		}
	}
	
	CheckCollisionPaddle();
	
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

void MyScene::checkAmountBlocks() {
	blocksSize = this->bricks.size();
	std::cout << /*"Amount Blocks: " +*/ blocksSize << std::endl;
}

void MyScene::erase() {
	//delete blocks
	for (auto it = bricks.begin(); it != bricks.end();) {
		if ((*it)->toErase >= 1) {
			removeChild(*it);
			delete(*it);
			it = bricks.erase(it);
		}
		else {
			++it;
		}

	}
}


