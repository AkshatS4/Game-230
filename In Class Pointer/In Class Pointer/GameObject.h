#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 // Use our gm namespace for both Game and GameObject classes
namespace gm {
	// Global constants related to our GameObject
	const int MinMovementAmount = -3;
	const int MaxMovementAmount = 3;

	// Our GameObject class! Maintains a shape and functionality needed to manipulate/render it
	// Will draw a circle and move that circle in a random direction every frame
	class GameObject {
	private:
		// Our shape object that the class maintains
		sf::CircleShape* shape;
	public:
		// Default constructor
		GameObject();
		// Overloaded constructor
		GameObject(const sf::Vector2f& position, float size);

		// Game loop programming pattern functions
		virtual void update(sf::RenderWindow& window);

		virtual void render(sf::RenderWindow& window);

		// Setters
		void setPosition(const sf::Vector2f& position);
		void setSize(float radius);

		// Getter
		const sf::Vector2f& getPosition() const;

		// Destructor
		~GameObject();
	};
}

#endif