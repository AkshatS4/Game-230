#ifndef VCIRCLE_H
#define VCIRCLE_H

#include "CircleObject.h"

// Use our gm namespace for all our defined classes
namespace gm {
	// Our VCircle class! Inherits from GameObject to maintain a shape and functionality needed to manipulate/render it
	// Will draw a circle and move that circle in a random up or down direction every frame
	class VCircle : public CircleObject {
	private:
		sf::Color color;
	public:
		//VCircle(sf::Color color);
		// Overrides the update in our base GameObject class
		virtual void update(sf::RenderWindow& window);
	};
}

#endif