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
	public:
		//Prototypes
		Particle();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		CircleShape getPosition();
		bool isAlive();
		void setVelocity(Vector2f vel);
		~Particle();
	};

	class ParticleEffect {
	public:
		//Prototypes
		ParticleEffect();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		void emit();
		void addParticle(int index, Particle* particle);
	};
}

#endif