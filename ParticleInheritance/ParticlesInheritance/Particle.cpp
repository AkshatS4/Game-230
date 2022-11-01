//Nanxiang Wang & Akshat Sachan

#include "Game.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
Particle::Particle() {
	body = CircleShape(radius);
	body.setFillColor(Color(255,0,255));
	position = Vector2f(350, 455);
	velocity = Vector2f(0.0f,0.0f);
	body.setPosition(position);
	lifespan = 5;
	alive = true;
}

Particle::Particle(Vector2f& pos)
{
	body = CircleShape(radius);
	body.setFillColor(Color(255, 0, 255));
	position = pos;
	velocity = Vector2f(0.0f, 0.0f);
	body.setPosition(position);
	lifespan = 5;
	alive = true;
}

//functions
void Particle::update(RenderWindow& window) {
	body.setPosition(position + velocity);
	position = body.getPosition();
}

void Particle::render(RenderWindow& window) {

}


const CircleShape Particle::getShape() const {
	return body;
}

const Vector2f& Particle::getVelocity() const{
	return velocity;
}

const int Particle::getLifespan() const {
	return lifespan;
}

const bool Particle::isAlive() const{
	return alive;
}

void Particle::setVelocity(Vector2f& vel) {
	velocity = vel;
}

Particle::~Particle() {
}