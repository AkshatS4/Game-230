#ifndef CIRCLE_OBJECT_H
#define CIRCLE_OBJECT_H

#include "ShapeObject.h";

// Use our gm namespace for all our defined classes
namespace gm {
	// Global constants related to manipulating our circle shape during update
	const int MinMovementAmount = -3;
	const int MaxMovementAmount = 3;

	// Our CircleObject class! Maintains a shape and functionality needed to manipulate/render it
	// Will draw a circle and move that circle in a random direction every frame
	class CircleObject : public ShapeObject {
	public:
		// Default constructor
		CircleObject();

		// Overloaded constructor that takes a position and radius size
		CircleObject(const sf::Vector2f& position, float size);

		// Game loop programming pattern functions, update
		// NOTE the override of the update in the ShapeObject class
		virtual void update(sf::RenderWindow& window) override;

		// Game loop programming pattern functions, render
		// NOTE the override of the render in the ShapeObject class
		virtual void render(sf::RenderWindow& window) override;

		// Setters
		virtual void setSize(float radius);

		// Destructor
		virtual ~CircleObject();
	};
}

#endif