
#ifndef MYBRICK_H
#define MYBRICK_H

#include <rt2d/entity.h>
#include <rt2d/scene.h>


/// @brief The MyEntity class is the Entity implementation.
class Brick : public Entity
{
public:
	/// @brief Constructor
	Brick();
	/// @brief Destructor
	virtual ~Brick();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Timer brickColour;
	/* add your private declarations */

};

#endif