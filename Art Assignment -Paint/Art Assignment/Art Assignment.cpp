#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>
using namespace std;
//boolean to activate and deactivate brush on moucse click - deactivated by deafult
bool  drawflag=false;

int main()
{
    //editor window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    float BrushSize = 50.f;
    //enum for range of values in brush : circle and square brush for now
    enum BrushType {Circle, Square};

    //making brush shapes
    sf::CircleShape shape(BrushSize);
    sf::RectangleShape square(sf::Vector2f(BrushSize * 1.f, BrushSize * 1.f));

    //local variable of brush selection enum to change brush type in the future //brush Cricle by default at start
    BrushType brushtype = Circle;
    //storing value(shape of brush) in current shape which is taken from the address of initial (circle) shape
    sf::Shape* CurrentBrush = &shape;

    shape.setFillColor(sf::Color::Green);
    square.setFillColor(sf::Color::Green);  

    

    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            //window close handle
            if (event.type == sf::Event::Closed)
                window.close();
            //activation/deactivation of brush on mouse click --removed
            //HOW TO CODE ON MOUSE BUTTON ISBUTTONPRESSED INSTEAD OF ONCLICK???---DONE
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                drawflag = true;
            }
            else 
            {
                drawflag = false;
            }

            //all events on keyboard key press event
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    shape.setFillColor(sf::Color::Red);
                    square.setFillColor(sf::Color::Red);
                }
                else if (event.key.code == sf::Keyboard::G)
                {
                    shape.setFillColor(sf::Color::Green);
                    square.setFillColor(sf::Color::Green);
                }
                else if (event.key.code == sf::Keyboard::B)
                {
                    shape.setFillColor(sf::Color::Blue);
                    square.setFillColor(sf::Color::Blue);
                }
                else if (event.key.code == sf::Keyboard::E)
                {
                   // Eraser HOW!!??
                   // transparent doesn't work
                   // shape.setFillColor(sf::Color::Transparent);
                   // square.setFillColor(sf::Color::Transparent);
                }                
                else if (event.key.code == sf::Keyboard::Down)
                {
                    if (BrushSize >= 5)
                    {
                        BrushSize -= 4.f;
                    }
                    else
                    {
                        BrushSize = 1.f; 
                    }
                    square.setSize(sf::Vector2f(BrushSize * 2.f, BrushSize * 2.f));
                    cout << "Brush size is " << BrushSize << endl;
                    shape.setRadius(BrushSize);                    
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    if (BrushSize < 50.f)
                    {
                        BrushSize += 4.f;
                    }
                    else
                    {
                        BrushSize = 50.f;
                    }
                    square.setSize(sf::Vector2f(BrushSize * 2.f, BrushSize * 2.f));
                    shape.setRadius(BrushSize);
                    cout << "Brush size is " << BrushSize << endl;
                }
                else if (event.key.code == sf::Keyboard::F)
                {
                    if (brushtype == Circle)
                    {                        
                        square.setFillColor(sf::Color::Red);
                        square.setSize(sf::Vector2f(BrushSize * 2.f, BrushSize * 2.f));
                        //store shape in current brush from adress of square
                        CurrentBrush = &square;
                        brushtype = Square;       
                        cout << "Brush changed to Square" << endl;

                    }
                    else if (brushtype == Square)
                    {                        
                        shape.setFillColor(sf::Color::Green);
                        shape.setRadius(BrushSize);
                        //store shape in current brush from adress of shape(circle)
                        CurrentBrush = &shape;
                        brushtype = Circle;                        
                        cout << "Brush changed to Circle"  << endl;
                    }
                    
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    sf::Texture texture;
                    texture.create(window.getSize().x, window.getSize().y);
                    texture.update(window);
                    if (texture.copyToImage().saveToFile("Art Assignment.png"))
                    {
                        std::cout << "Screenshot saved to Art Assignment.png" << std::endl;
                    }
                }
            }
        }
        
        if (drawflag)
        {
            //offseting mouse  to center of brush
            shape.setPosition(sf::Mouse::getPosition(window).x - BrushSize , sf::Mouse::getPosition(window).y - BrushSize );
            square.setPosition(sf::Mouse::getPosition(window).x - BrushSize, sf::Mouse::getPosition(window).y - BrushSize);
            //shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            //square.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            window.draw(*CurrentBrush);
            window.display();
        }
            
           
        
    }
    return 0;
}