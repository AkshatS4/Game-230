#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>

//namespaces
using namespace std;
using namespace sf;

void HandleInput(RenderWindow& window, Event& e);
void Update(RenderWindow& window);
void Render(RenderWindow& window);


int main()
{
    //editor window
    RenderWindow window(VideoMode(1000, 1000), "SFML works!");

   
       
    //this is our game loop
    while (window.isOpen())
    {
        Event event;
        //window close handle
        if (event.type == Event::Closed)
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            
            HandleInput(window, event);

        }

        window.display();
    }
    return 0;
}

void HandleInput(RenderWindow& window, Event& e)
{
}

void Update(RenderWindow& window)
{
}

void Render(RenderWindow& window)
{
}
