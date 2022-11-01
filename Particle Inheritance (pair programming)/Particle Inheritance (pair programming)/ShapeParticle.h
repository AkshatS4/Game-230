#ifndef SHAPE_PARTICLE_H
#define SHAPE_PARTICLE_H

//Includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <fstream>

#include "Particle.h"

namespace gm 
{
	class ShapeParticle : public Particle
	{
	protected:
		sf::Shape* shape;

	public:
		//default constructor
		ShapeParticle();

		virtual void update(sf::RenderWindow& window) = 0;
		
		virtual void render(sf::RenderWindow& window) = 0;

		virtual void getShape() const override;

		~ShapeParticle();

	};
}


#endif 

