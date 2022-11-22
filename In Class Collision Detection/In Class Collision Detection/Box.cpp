#include "Box.h"

using namespace gm;
using namespace sf;

Box::Box(const sf::Vector2f& position, const sf::Vector2f& size) {
	body.setPosition(position);
	body.setSize(size);

}

void Box::update(sf::RenderWindow& window) {

}

void Box::render(sf::RenderWindow& window) {
	window.draw(body);
}