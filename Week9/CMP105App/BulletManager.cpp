#include "BulletManager.h"

BulletManager::BulletManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(sf::Vector2f(50, 50));
	}
	
	
}

BulletManager::~BulletManager()
{
}

void BulletManager::spawn(sf::Vector2f spawnPos)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setTargetPos(sf::Vector2f(input->getMouseX(), input->getMouseY()));
			bullets[i].Shoot();
			bullets[i].setAlive(true);
			bullets[i].setVelocity(100, 0);
			bullets[i].setPosition(spawnPos);
			return;
		}
	}
	bullets.push_back(Bullet());
	bullets[bullets.size() - 1].setAlive(false);
	bullets[bullets.size() - 1].setTexture(&texture);
	bullets[bullets.size() - 1].setSize(sf::Vector2f(100, 100));
}

void BulletManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}
	}
	deathCheck();
	
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{

			if (bullets[i].getPosition().y > 600)
			{
				
				bullets[i].setAlive(false);
			}
		}
	}
}



void BulletManager::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}

void BulletManager::setInput(Input* inputToSet)
{
	input = inputToSet;
}



