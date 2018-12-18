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
	myentity1 = new MyEntity();
	myentity1->position = Point2(SWIDTH / 2, SHEIGHT / 1.75);

	paddle1 = new Paddle();
	paddle1->position = Point2(SWIDTH / 2, SHEIGHT / 1.25);

	// BrickGrid

	brick1 = new Brick();
	brick1->position = Point2(SWIDTH / 6, SHEIGHT /2.5 );

	brick2 = new Brick();
	brick2->position = Point2(SWIDTH / 2.75, SHEIGHT /2.5 );

	brick3 = new Brick();
	brick3->position = Point2(SWIDTH / 1.75, SHEIGHT /2.5 );

	brick4 = new Brick();
	brick4->position = Point2(SWIDTH / 1.25, SHEIGHT /2.5 );

	brick5 = new Brick();
	brick5->position = Point2(SWIDTH / 6, SHEIGHT /3.5 );

	brick6 = new Brick();
	brick6->position = Point2(SWIDTH / 2.75, SHEIGHT /3.5 );

	brick7 = new Brick();
	brick7->position = Point2(SWIDTH / 1.75, SHEIGHT /3.5 );

	brick8 = new Brick();
	brick8->position = Point2(SWIDTH / 1.25, SHEIGHT /3.5 );



	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity1);
	this->addChild(paddle1);
	this->addChild(brick1);
	this->addChild(brick2);
	this->addChild(brick3);
	this->addChild(brick4);
	this->addChild(brick5);
	this->addChild(brick6);
	this->addChild(brick7);
	this->addChild(brick8);
	
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity1);
	this->removeChild(paddle1);
	this->removeChild(brick1);
	this->removeChild(brick2);
	this->removeChild(brick3);
	this->removeChild(brick4);
	this->removeChild(brick5);
	this->removeChild(brick6);
	this->removeChild(brick7);
	this->removeChild(brick8);
	

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity1;
	delete paddle1;
	delete brick1;
	delete brick2;
	delete brick3;
	delete brick4;
	delete brick5;
	delete brick6;
	delete brick7;
	delete brick8;
	
	
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


		
}
