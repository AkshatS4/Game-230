#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	/* Our particle class maintains a shape(with position, color, size, etc) and *
	*  velocity, lifespan in milliseconds, and alive bit flag for our particle   */
	class Particle {
	private:
		sf::CircleShape* shape;
		sf::Vector2f velocity;
		float secondsLifespan;
		bool alive : 1;
	public:
		// Our particle constructor
		Particle();
		// Sets the particle values needed
		void init(const sf::Vector2f& position, float size, const sf::Vector2f& velocity, const sf::Color& color, float secondsLifespan);
		// Updates the particle (only if it is alive)
		void update(sf::RenderWindow& window, float deltaTime);
		// Draws the particle (only if it is alive)
		void render(sf::RenderWindow& window);
		// Gets the position of the particle
		const sf::Vector2f& getPosition() const;
		// Gets the alive flag of the particle
		bool isAlive() const;
		// The destructior for the particle

		// TODO: Overload assignment operator
		Particle operator=(const Particle& p);

		// TODO: Overload copy constructor
		Particle(const Particle& p1);

		~Particle();
	};
}

#endif