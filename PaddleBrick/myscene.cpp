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
	t2.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity1 = new MyEntity();
	myentity1->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	myentity2 = new MyEntity();
	myentity2->position = Point2(SWIDTH / 4, SHEIGHT / 2);

	paddle1 = new Paddle();
	paddle1->position = Point2(SWIDTH / 2, SHEIGHT / 1.5);

	brickGrid = new Brick();
	brickGrid->position = Point2(SWIDTH / 2, SHEIGHT / 3);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity1);
	this->addChild(myentity2);
	this->addChild(paddle1);
	this->addChild(brickGrid);
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity1);
	this->removeChild(myentity2);
	this->removeChild(paddle1);
	this->removeChild(brickGrid);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity1;
	delete myentity2;
	delete paddle1;
	delete brickGrid;
	
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity1->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity1->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity1->sprite()->color;
		myentity1->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}

	if (t2.seconds() > 0.0333f) {
		RGBAColor color1 = brickGrid->sprite()->color;
		brickGrid->sprite()->color = Color::rotate(color1, 0.01f);
		t2.start();
	}
		
}
