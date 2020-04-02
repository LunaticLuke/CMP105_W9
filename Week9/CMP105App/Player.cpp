#include "Player.h"

Player::Player()
{
	setFillColor(sf::Color::Blue);
	setSize(sf::Vector2f(200, 200));
	
}

Player::~Player()
{
}

void Player::update(float dt)
{
	bullets.update(dt);
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		velocity.x = 15;
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		velocity.x = -15;
	}else if (input->isKeyDown(sf::Keyboard::Up))
	{
		velocity.y = -15;
	}else if (input->isKeyDown(sf::Keyboard::Down))
	{
		velocity.y = 15;
	}
	else
	{
		velocity = sf::Vector2f(0, 0);
	}
	if (input->isMouseLDown())
	{
		bullets.setInput(input);
		input->setMouseLDown(false);
		bullets.spawn(getPosition());
	}
	move(velocity * dt);
}

BulletManager Player::getBulletManager()
{
	return bullets;
}
