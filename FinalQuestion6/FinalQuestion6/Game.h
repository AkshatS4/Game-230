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

 /* Our Includes */
#include "ParticleEffect.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 640;
	const int GameHeight = 640;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		sf::RenderWindow window;
		// The particle effect pointer
		ParticleEffect* pe;
		//COPY CONSTRUCTOR CALLED
		

		//ASSIGNMENT OVERLOAD
		
		
		// Variables for keeping track of delta time
		sf::Clock clock;
		float deltaTime = 0;

	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();
	};
}

#endif