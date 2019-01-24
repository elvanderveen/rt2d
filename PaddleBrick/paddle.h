
#ifndef MYPADDLE_H
#define MYPADDLE_H


#include <rt2d/entity.h>
#include <rt2d/scene.h>


/// @brief The MyEntity class is the Entity implementation.
class Paddle : public Entity
{
public:
	/// @brief Constructor
	Paddle();
	/// @brief Destructor
	virtual ~Paddle();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	
};

#endif