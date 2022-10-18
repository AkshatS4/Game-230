//AKSHAT SACHAN AND NANXIANG WANG
// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* STL Includes */
#include <iostream>


using namespace std;
using namespace sf;

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm
{
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Game Loop Programming Pattern Methods
		void HandleInput(sf::RenderWindow& window);
		void Update(sf::RenderWindow& window);
		void Render(sf::RenderWindow& window);
		// Destructor
		~Game();
	};

	class Particle {
	private:
		//Global variables
		sf::CircleShape body;
		float radius = 10;
		sf::Vector2f position;
		sf::Vector2f velocity;
		short lifespan;
		bool alive;
	public:
		//Prototypes
		Particle();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		sf::CircleShape getShape() const;
		sf::Vector2f getVelocity() const;
		bool isAlive() const;
		void setVelocity(sf::Vector2f vel);
		~Particle();
	};

	class ParticleEffect
	{
	private:
		//Global variables
		Particle* arr[10];
		sf::Clock clock;
	public:
		//Prototypes
		ParticleEffect();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		void emit();
		Particle* addParticle(int index, Particle* particle);
	};
}

#endif