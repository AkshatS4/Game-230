#include "ShapeObject.h"

using namespace sf;
using namespace gm;

// Default constructor
// NOTE that we are setting the shape pointer to null
ShapeObject::ShapeObject() : shape(nullptr) {}

// Overloaded constructor that takes a position
// NOTE that we are initializing the base class with the provided vector in the initialization list
// NOTE that we are also setting the shape pointer to null
ShapeObject::ShapeObject(const Vector2f& position) : GameObject(position), shape(nullptr) {}

// Getters
// 
// Our position getter
// Gets the game object's position (which is stored in shape)
// Return by reference so that the returned object isn't returned by value/copied (which wastes space and time)
// Also return by const so that anyone who calls this function can't modify the referenced position within the class
// NOTE: Mark this function const since it should never modify anything in the class itself when called (i.e., it's a getter)
const Vector2f& ShapeObject::getPosition() const {
	return shape->getPosition();
}

// Setters
// 
// Our position setter, NOTE the pass by const reference
// Sets the shape object's position (which is stored in shape) and the base game object's position
void ShapeObject::setPosition(const Vector2f& position) {

	shape->setPosition(position);

	// NOTE: we can call the base setPosition method as well to keep position up to date in the base class
	GameObject::setPosition(position);
}