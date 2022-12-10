#include "ParticleEffect.h"
#include <cstdlib>

using namespace gm;
using namespace sf;

// Our particle effect constructor
ParticleEffect::ParticleEffect(const Vector2f& position) : position(position) {
	particles = new Particle * [NumberParticles];

	for (int i = 0; i < NumberParticles; i++) {
		particles[i] = nullptr;
	}

	emit();
}

// Updates all of the particles in our particle effect
void ParticleEffect::update(RenderWindow& window, float deltaTime) {
	for (int i = 0; i < NumberParticles; i++) {
		particles[i]->update(window, deltaTime);
	}
}

// Draws all of the particles in our particle effect
void ParticleEffect::render(RenderWindow& window) {
	for (int i = 0; i < NumberParticles; i++) 
	{
		particles[i]->render(window);
	}
}

// Starts the particle effect anew by creating a brand new set of particles in the particles array
// NOTE: deletes the previous particle effect even if it hasn't finished yet
void ParticleEffect::emit() {
	for (int i = 0; i < NumberParticles; i++) {
		addParticle(i);
	}
}

// Adds a randomized particle at the specified index in the particles array
void ParticleEffect::addParticle(int index) {
	float size = MinSize + rand() % (MaxSize - MinSize + 1);
	float speedX = MinSpeed + rand() % (MaxSpeed - MinSpeed + 1);
	float speedY = MinSpeed + rand() % (MaxSpeed - MinSpeed + 1);
	float lifespan = (float(rand()) / float(RAND_MAX)) * (MaxLifespan - MinLifespan);
	if (!particles[index]) particles[index] = new Particle();
	particles[index]->init(position, size, Vector2f(speedX, speedY), Color::White, lifespan);
}

//ASSIGNMENT OPERATOR OVERLOAD
ParticleEffect gm::ParticleEffect::operator=(const ParticleEffect& pe)
{

	for (int i = 0; i < NumberParticles; i++)
	{
		delete particles[i];
	}
	delete[] particles;

	particles = new Particle * [NumberParticles];
	position = pe.position;

	for (int i = 0; i < NumberParticles; i++)
	{
		particles[i] = pe.particles[i];
	}

	return *this;
}

//COPY CONSTRUCTOR FOR PARTICLE EFFECT CLASS
gm::ParticleEffect::ParticleEffect(const ParticleEffect& pe1)
{
	particles = new Particle * [NumberParticles];
	position = pe1.position;
	for (int i = 0; i < NumberParticles; i++) 
	{
		particles[i] = pe1.particles[i];
	}
}

// Particle effect destructor
// Cleans up all of our particles off the heap
ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < NumberParticles; i++) {
		delete particles[i];
	}
	delete[] particles;
}