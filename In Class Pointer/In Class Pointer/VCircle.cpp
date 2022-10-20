#include "VCircle.h"

using namespace sf;
using namespace gm;

//make the circle move randomly up or down each update
void VCircle::update(RenderWindow& window) 
{
	// Calculate the random movement amound in x and y directions
	int randomMovementY = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x, getPosition().y + randomMovementY));
}