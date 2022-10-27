#ifndef HCIRCLE_H
#define HCIRCLE_H

#include "CircleObject.h"

// Use our gm namespace for all our defined classes
namespace gm {
	// Our HCircle class! Inherits from GameObject to maintain a shape and functionality needed to manipulate/render it
	// Will draw a circle and move that circle in a random left or right direction every frame
	class HCircle : public CircleObject {
	public:
		// Overrides the update in our base GameObject class
		virtual void update(sf::RenderWindow& window);
	};
}

#endif