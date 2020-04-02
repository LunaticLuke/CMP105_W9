#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	setVelocity(100,0);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	
	direction = Vector::normalise(direction);
	velocity = direction * speed;
	move(velocity * dt);
}

void Bullet::setTargetPos(sf::Vector2f targetToSet)
{
	targetPos = targetToSet;
}

void Bullet::Shoot()
{
	direction = targetPos - getPosition();
}
