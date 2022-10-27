#include "HCircle.h"

using namespace sf;
using namespace gm;

// Move the circle randomly left or right each update
void HCircle::update(RenderWindow& window) {
	// Calculate the random movement amound in the x direction
	int randomMovementX = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y));
}