// Include our header so that we can define our method declarations made there
#include "GameObject.h"

// For using random functionality
#include <cstdlib>

// It's fine to use namespaces in .cpp files, just not .h files (will pollute your namespace otherwise)
using namespace sf;
using namespace gm;

// Our default constructor
// Makes a white circle shape on the heap with no specified position or size
GameObject::GameObject() {
	shape = new CircleShape();
	shape->setFillColor(Color::White);
}

// Our overloaded constructor
// Makes a white circle shape on the heap with a specified position and size
GameObject::GameObject(const Vector2f& position, float size) {
	shape = new CircleShape(size);
	shape->setPosition(position);
	shape->setFillColor(Color::White);
}

// Move the game object randomly each update
void GameObject::update(RenderWindow& window) {
	// Calculate the random movement amound in x and y directions
	int randomMovementX = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);
	int randomMovementY = MinMovementAmount + rand() % (MaxMovementAmount - MinMovementAmount + 1);

	// Set the game object's new position with this random movement offset
	setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y + randomMovementY));
}

// Renders the game object
// Does this by telling the window to draw the dereferenced shape pointer
void GameObject::render(RenderWindow& window) {
	window.draw(*shape);
}

// Getters
// Gets the game object's position (which is stored in shape)
// Return by reference so that the returned object isn't returned by value/copied (which wastes space and time)
// Also return by const so that anyone who calls this function can't modify the referenced position within the class
// NOTE: Mark this function const since it should never modify anything in the class itself when called (i.e., it's a getter)
const Vector2f& GameObject::getPosition() const {
	return shape->getPosition();
}

// Setters
// Sets the game object's position (which is stored in shape)
void GameObject::setPosition(const Vector2f& position) {
	shape->setPosition(position);
}

// Sets the game object's size (which is stored in shape)
void GameObject::setSize(float size) {
	shape->setRadius(size);
}

// Destructor
// We put the shape on the heap in the constructor, make sure we free it here now that we are done with it!
GameObject::~GameObject()
{
	delete shape;
}