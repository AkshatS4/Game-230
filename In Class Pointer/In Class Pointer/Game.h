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

 // Include our custom classes so that we can use it here
#include "GameObject.h"
#include "VCircle.h"
#include "HCircle.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// A dynamically allocated array of GameObjects
		// Because it is dynamically allocated, we can specifiy the size at runtime
		GameObject** objects;
		GameObject objects2[10];

		//VCircle** objects;
		//HCircle** objects;
		
		// How many GameObjects are in our objects array
		// This will be set to a random number at runtime
		int numberObjects;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Game Loop Programming Pattern Methods
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		// Destructor
		~Game();
	};
}

#endif