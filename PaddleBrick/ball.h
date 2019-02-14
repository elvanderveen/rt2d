
#ifndef MYBALL_H
#define MYBALL_H


#include <rt2d/entity.h>
#include <rt2d/scene.h>


/// @brief The MyEntity class is the Entity implementation.
class Ball : public Entity
{
public:
	/// @brief Constructor
	Ball();
	/// @brief Destructor
	virtual ~Ball();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool CircleParamater(int dosomething);

	bool OnCollisionEnter(Entity* other);

	/*bool OnCollisionEnter(Entity* brick);*/

	Vector2 velocity;

private:
	/* add your private declarations */
	
};

#endif