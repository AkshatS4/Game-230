#ifndef SHAPE_OBJECT_H
#define SHAPE_OBJECT_H

#include "GameObject.h"

// Use our gm namespace for all our defined classes
namespace gm {
	// Our abstract ShapeObject class that defines the interface for all shape based objects that appear in our games
	class ShapeObject : public GameObject
	{
	protected:
		// All shape objects should have a pointer to some shape
		sf::Shape* shape;
	public:
		// Default constructor
		ShapeObject();

		// Overloaded constructor that takes a position
		ShapeObject(const sf::Vector2f& position);

		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window) = 0;

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window) = 0;

		// Our position getter, NOTE the override since we are overriding the base GameObject method
		virtual const sf::Vector2f& getPosition() const override;

		// Our position setter, NOTE the override since we are overriding the base GameObject method
		virtual void setPosition(const sf::Vector2f& position) override;
	};
}

#endif