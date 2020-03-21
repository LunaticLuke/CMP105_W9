#include "GoombaManager.h"

GoombaManager::GoombaManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Goomba.png");

	for (int i = 0; i < 40; i++)
	{
		goombas.push_back(Goomba());
		goombas[i].setAlive(false);
		goombas[i].setTexture(&texture);
		goombas[i].setSize(sf::Vector2f(100, 100));
	}
}

GoombaManager::~GoombaManager()
{
}

void GoombaManager::spawn()
{
}

void GoombaManager::update(float dt)
{
}

void GoombaManager::deathCheck()
{
}



void GoombaManager::Render(sf::RenderWindow* window)
{
}
