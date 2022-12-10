#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Particle.h"
#include "ParticleEffectConfiguration.h"

namespace gm {
	/* Our particle effect class creates and maintains an array of particle pointers */
	class ParticleEffect {
	private:
		sf::Vector2f position;
		Particle** particles;
		
		
		//ASSIGNMENT OVERLOAD
		
		// Adds a randomized particle at the specified index in the particles array
		void addParticle(int index);
	public:
		// Our particle effect constructor
		ParticleEffect(const sf::Vector2f& position);
		// Updates all of the particles in our particle effect
		void update(sf::RenderWindow& window, float deltaTime);
		// Draws all of the particles in our particle effect
		void render(sf::RenderWindow& window);
		// Starts the particle effect anew by creating a brand new set of particles in the particles array
		// NOTE: deletes the previous particle effect even if it hasn't finished yet
		void emit();
		// Particle effect destructor
		// Cleans up all of our particles off the heap

		// TODO: Overload assignment operator
		ParticleEffect operator=(const ParticleEffect& pe);

		// TODO: Overload copy constructor
		ParticleEffect(const ParticleEffect& pe1);

		~ParticleEffect();
	};
}
#endif