#include "Particle.h"

using namespace sf;
using namespace gm;

// Our particle constructor
Particle::Particle() : shape(new CircleShape), secondsLifespan(0), alive(false) {
}

void Particle::init(const Vector2f& position, float size, const Vector2f& velocity, const Color& color, float secondsLifespan) {
	shape->setRadius(size);
	shape->setPosition(position);
	shape->setFillColor(color);

	this->velocity = velocity;
	this->secondsLifespan = secondsLifespan;
	alive = true;
}

// Updates the particle (only if it is alive)
void Particle::update(RenderWindow& window, float deltaTime) {
	if (!alive) return;

	// Update position
	// NOTE: we are calculating and using delta time so that movement is not frame dependent
	shape->setPosition(getPosition().x + deltaTime * velocity.x, getPosition().y + deltaTime * velocity.y);

	// Update lifespan
	// If we run of out lifespan then die
	secondsLifespan -= deltaTime;
	if (secondsLifespan <= 0) {
		alive = false;
	}
}

// Draws the particle (only if it is alive)
void Particle::render(RenderWindow& window) {
	if (alive) {
		window.draw(*shape);
	}
}

// Gets the position of the particle
const Vector2f& Particle::getPosition() const {
	return shape->getPosition();
}

// Gets the alive flag of the particle
bool Particle::isAlive() const {
	return alive;
}

//OVERLAODED ASSIGNMENT OPERATOR
Particle gm::Particle::operator=(const Particle& p)
{
		shape = new CircleShape();
		shape = p.shape;
		secondsLifespan = p.secondsLifespan;
		alive = p.alive;
		velocity = p.velocity;
		return *this;

}

//COPY CONSTRUCTOR OF THE CLASS PARTICLE
gm::Particle::Particle(const Particle& p1)
{
	shape = new CircleShape();
	secondsLifespan = p1.secondsLifespan;
	alive = p1.alive;
}

// The destructior for the particle
Particle::~Particle() {
	delete shape;
}