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

/* My Classes */
#include "Game.h"



/* Namespaces */
using namespace std;
using namespace sf;
using namespace gm;

/* Functions */
// Main, our applicaiton entry function
int main()
{
    /*int i = 5;
    int* ip = &i;
    int ia[]{ 1,2,3,4 };
    
    changeValue(ia);
    */

    // Create the window for the game
    RenderWindow window(VideoMode(800, 800), "SFML works!");

    Game g;

    // This is our game loop!
    // All input, logic, and rendering should be handled here
    while (window.isOpen())
    {
        // Our game object handles the game loop programming pattern
        g.HandleInput(window);
        
        g.Update(window);

        g.Render(window);
    }

    // The game has exited normally so send a normal exit status integer back
    return 0;
}