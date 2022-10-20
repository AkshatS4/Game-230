#include "HCircle.h"

using namespace sf;
using namespace gm;

//make the circle move randomly up or down each update
void HCircle::update(RenderWindow& window)
{
	// Calculate the random movement amound in x and y directions
	int randomMovementX = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x +randomMovementX, getPosition().y));
}