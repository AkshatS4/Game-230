// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include "Random.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;

//global variable
ParticleEffect e;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	e = ParticleEffect();

}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::HandleInput(sf::RenderWindow& window) {
	// Check for events from the window
	// E.g., is the window being closed?
	sf::Event event;
	while (window.pollEvent(event))
	{		
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		{
			e.emit();
		}
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::Update(sf::RenderWindow& window) {
	// We aren't doing anything here currently so we can just print out that the code is updating as a sanity check
	//std::cout << "Updating" << std::endl;
	//Event event;
	//while (window.pollEvent(event))
	//{
		e.update(window);
	//}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::Render(sf::RenderWindow& window) 
{
	// This clears the window at the beginning of every frame
	//window.clear();
	e.render(window);
	// Display the window buffer for this frame
	//window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}