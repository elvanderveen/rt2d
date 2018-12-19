/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H


#include <rt2d/scene.h>


#include "paddle.h"
#include "brick.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	Paddle* paddle1;
	Brick* brick1;
	Brick* brick2;
	Brick* brick3;
	Brick* brick4;
	Brick* brick5;
	Brick* brick6;
	Brick* brick7;
	Brick* brick8;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	
	
};

#endif /* SCENE00_H */
