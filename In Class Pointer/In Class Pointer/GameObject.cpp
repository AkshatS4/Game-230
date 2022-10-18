#include "GameObject.h"
#include <cstdlib>

using namespace sf;
using namespace gm;

GameObject::GameObject()
{
	shape = new CircleShape();
	shape->setFillColor(Color::Magenta);
}

GameObject::GameObject(const sf::Vector2f& position, float size)
{
	shape = new sf::CircleShape(size);
	shape->setPosition(position);
}

void GameObject::update(sf::RenderWindow& window)
{
	int randomMovementX = -3 + rand() % 7; //mod 7 beacause -3 to 3
	int randomMovementY = -3 + rand() % 7;
	shape->setPosition(Vector2f(getPosition().x + randomMovementX, getPosition().y + randomMovementY));
}

void GameObject::render(sf::RenderWindow& window)
{
	window.draw(*shape);
}

//Setters
void gm::GameObject::setPosition(const sf::Vector2f& position)
{
	shape->setPosition(position);
}

void gm::GameObject::setSize(float size)
{
	shape->setRadius(size);
}

//Getters
const Vector2f gm::GameObject::getPosition() const
{
	return shape->getPosition();
}

GameObject::~GameObject()
{
	delete shape;
}