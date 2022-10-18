// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <cstdlib>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

const int NumberObjects = 75;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() 
{
	objects = new GameObject * [NumberObjects];

	for (int i = 0; i < NumberObjects; i++) 
	{
		objects[i] = new GameObject();
		objects[i]->setPosition(Vector2f(400, 400));
		objects[i]->setSize(20);

	}
	//test.setPosition(Vector2f(400, 400));
	//test.setSize(50);

	//setting the random seed
	srand(time(NULL));
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::HandleInput(sf::RenderWindow& window) {
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
void Game::Update(sf::RenderWindow& window) {
	// We aren't doing anything here currently so we can just print out that the code is updating as a sanity check
	//std::cout << "Updating" << std::endl;
	for (int i = 0; i < NumberObjects; i++)
	{
		objects[i]->update(window);
	}
	//test.update(window);
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::Render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();

	for (int i = 0; i < NumberObjects; i++)
	{
		objects[i]->render(window);
	}
	//test.render(window);
	// Display the window buffer for this frame
	window.display();
}
/*
void Game::changeValue(int* i)
{
	*i += 5;

}*/

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() 
{
	for (int i = 0; i < NumberObjects; i++)
	{
		delete objects[i];
	}
	delete[] objects;
	
}