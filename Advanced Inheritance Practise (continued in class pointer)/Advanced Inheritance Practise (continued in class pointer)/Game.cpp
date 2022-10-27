// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Include object classes that we will use in game but are not needed in the header
// E.g., all derived classes
#include "VCircle.h"
#include "HCircle.h"

// For using random functionality
#include <cstdlib>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	// Set the random seed
	srand(time(NULL));

	// Randomly create between 5 and 50 game objects on the heap
	// Randomly determine the number of objects to create
	numberObjects = 5 + rand() % 46;
	// Dynamically allocate an array on the heap to hold pointers to that randomly generated number
	objects = new CircleObject * [numberObjects];

	// Go through each object pointer in the array and allocate an object that it can point to
	for (int i = 0; i < numberObjects / 2; i++) {
		objects[i] = new HCircle();
		// We will just make all objects the same size and start them in the center of the sreen for now
		// All game objects move randomly so we will be able to see them all somewhat at runtime :)
		objects[i]->setPosition(Vector2f(375, 275));
		objects[i]->setSize(50);
	}
	// Go through each object pointer in the array and allocate an object that it can point to
	for (int i = numberObjects / 2; i < numberObjects; i++) {
		objects[i] = new VCircle();
		// We will just make all objects the same size and start them in the center of the sreen for now
		// All game objects move randomly so we will be able to see them all somewhat at runtime :)
		objects[i]->setPosition(Vector2f(375, 275));
		objects[i]->setSize(50);
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput(sf::RenderWindow& window) {
	// Check for events from the window
	// E.g., is the window being closed?
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window) {
	// Go through each game object and call its update to change state every frame
	// This nicely follows the game loop programming pattern :)
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->update(window);
	}

}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();

	// Go through each game object and call its render to display it on the window
	// This nicely follows the game loop programming pattern :)
	for (int i = 0; i < numberObjects; i++) {
		objects[i]->render(window);
	}
	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {
	// We allocated all these game objects and an array... Make sure we clean up when done!
	// First, go through each game object in the array and free it from the heap
	for (int i = 0; i < numberObjects; i++) {
		delete objects[i];
	}

	// Then free the array itself from the heap!
	// NOTE: this order is critical! The other way around would cause a memory leak and potential errors/unexpected behavior
	delete[] objects;
}