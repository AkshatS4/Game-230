#include <iostream>

// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
// Note that the particle effect is null since we are deallocating and allocating a new one on every left mouse click
// On the other hand, we want to allocate everything once with the particle effect pool and then reuse the allocated particles
// So allocate that at the start of the game
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), pe(nullptr) {
	// Lock our framerate
	window.setFramerateLimit(60);

	// Initialize random
	srand(time(NULL));

	// Reset our clock to start keeping track of time between frames
	clock.restart();
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Calculate delta time
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		// Close the window
		if (event.type == Event::Closed)
			window.close();

		// Spawn a new particle effect if the left mouse button is pressed
		// NOTE: Make sure to delete the previous effect before spawning a new one or we will get memory leaks!
		if (Mouse::isButtonPressed(Mouse::Left)) {
			// Uncomment the below two lines to create the less efficient particle effect and compare frame rates
			// Avoid memory leak of the previous particle effect
			delete pe;
			// Create a new particle effect on the heap to manage
			pe = new ParticleEffect(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	// Tell our effect to update its particles each frame
	if (pe) pe->update(window, deltaTime);
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Make sure the effect isn't null before we try to render it
	// E.g., if the player hasn't clicked the window for the first time to create an effect
	if (pe) pe->render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
// In this case, the ParticleEffect we are managing on the heap
Game::~Game() {
	delete pe;
}