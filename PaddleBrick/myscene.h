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

#include "myentity.h"
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
	MyEntity * myentity1;
	MyEntity* myentity2;
	Paddle* paddle1;
	Brick* brickGrid;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	Timer t2;
};

#endif /* SCENE00_H */
