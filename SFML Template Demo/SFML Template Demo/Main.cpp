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

//global Variables
Music bgm;
SoundBuffer sfxBuffer;
Sound sfx;
Sprite TileSprite;
Texture TileTexture;

int main()
{
    //editor window
    RenderWindow window(VideoMode(1000, 1000), "SFML works!");

    if (!bgm.openFromFile("Assets/Audio/BGM.wav"))
    {
        //something bad happened
        return -1;
    }
    bgm.play();
    bgm.setLoop(true);
       
    //SFX
    if (!sfxBuffer.loadFromFile("Assets/Audio/Victory Jingle SFX.wav"))
    {
        //bad stuff
        return -1;
    }
    sfx.setBuffer(sfxBuffer);
    sfx.play();

    //Sprite
    if (!TileTexture.loadFromFile("Assets/Graphics/Tile1.png"))
    {
        //bad thing
        return -1;
    }
    TileSprite.setTexture(TileTexture);
    TileSprite.setPosition(100, 100);


    //this is our game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) 
        {
            //window close handle
            if (event.type == Event::Closed)
            {
                window.close();
            }

            while (window.pollEvent(event))
            {

                HandleInput(window, event);
                Render(window);
            }

            window.display();
        }
    }
    return 0;
}

void HandleInput(RenderWindow& window, Event& e)
{
    if (e.type == Event::Closed)
    {
        window.close();
    }
    //Play sfx on mouse click
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        sfx.play();
    }

}

void Update(RenderWindow& window)
{
    
}

void Render(RenderWindow& window)
{
    window.clear();
    window.draw(TileSprite);
    window.display();
}
