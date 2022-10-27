// Include our header so that we can define our method declarations made there
#include "CircleObject.h"

// For using random functionality
#include <cstdlib>

// It's fine to use namespaces in .cpp files, just not .h files (will pollute your namespace otherwise)
using namespace sf;
using namespace gm;

// Our default constructor
// Makes a white circle shape on the heap with no specified position or size
CircleObject::CircleObject()
	: ShapeObject()
{
	shape = new CircleShape();
	shape->setFillColor(Color::White);
}

// Our overloaded constructor
// Makes a white circle shape on the heap with a specified position and size
CircleObject::CircleObject(const Vector2f& position, float size)
	: ShapeObject(position)
{
	shape = new CircleShape(size);
	shape->setFillColor(Color::White);
	shape->setPosition(position);
}

// Move the circle object randomly each update
void CircleObject::update(RenderWindow& window) {
	// Calculate the random movement amound in x and y directions
	int randomMovementX = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);
	int randomMovementY = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);

	// Set the circle object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y + randomMovementY));
}

// Renders the circle object
// Does this by telling the window to draw the dereferenced shape pointer
void CircleObject::render(RenderWindow& window) {
	// Uh oh! Dereferencing a shape pointer will cause a slicing issue
	// This is an instance where we can use a dynamic cast to the derived CircleShape class since we know it will always be a CircleShape
	window.draw(*dynamic_cast<CircleShape*>(shape));
}

// Sets the circle object's size (which is stored in shape)
void CircleObject::setSize(float size) {
	// Uh oh! A shape pointer can't access derived class methods such as setRadius in the CircleShape class
	// This is an instance where we can use a dynamic cast to the derived CircleShape class since we know it will always be a CircleShape
	dynamic_cast<CircleShape*>(shape)->setRadius(size);
}

// Destructor
// We put the shape on the heap in the constructor, make sure we free it here now that we are done with it!
CircleObject::~CircleObject()
{
	delete shape;
}