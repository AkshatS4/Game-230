#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>

/*namespaces*/
using namespace std;
using namespace sf;


/*ENum*/
enum ParticleShape {
    Circle,
    Triangle,
    Square
};


/*Classes*/
class Particle {
private:
    ParticleShape shape;
    CircleShape body;
    int size;
    Vector2f position;
    Vector2f velocity;
    short lifespan;
    bool alive : 1;

public:
    Particle() {
        shape = ParticleShape::Circle;
        body = CircleShape(size);
        body.setPosition(position);
        size = 40;
        position = Vector2f(400, 400);
        velocity = Vector2f(0, 1);
        lifespan = 200;
        alive = true;
    }

    void update()
    {

    }

    void render(RenderWindow& window)
    {
        window.draw(body);
    }
};



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
        

        while (window.pollEvent(event))
        {
            //window close handle
            if (event.type == Event::Closed)
            {
                window.close();
            }
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
    //add render code
}
