#include "GameObject.h"

using namespace sf;
using namespace gm;

// Default constructor
GameObject::GameObject() {}

// Overloaded constructor that takes a position
// NOTE that we set the position using the initialization list
GameObject::GameObject(const Vector2f& position) : position(position) {}


// Our position getter, NOTE the const reference return and marking the method itself const
const Vector2f& GameObject::getPosition() const {
	return position;
}

// Our position setter, takes a Vector2f by const reference
void GameObject::setPosition(const Vector2f& position) {
	this->position = position;
}