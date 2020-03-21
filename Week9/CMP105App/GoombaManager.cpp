#include "GoombaManager.h"
#include <string>

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
	textToDisplay.setFillColor(sf::Color::Red);
	textToDisplay.setCharacterSize(100);
	textToDisplay.setScale(1, 1);
	font.loadFromFile("font/arial.ttf");
	textToDisplay.setFont(font);
}

GoombaManager::~GoombaManager()
{
}

void GoombaManager::spawn()
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (!goombas[i].isAlive())
		{
			goombasBeingRendered++;
			goombas[i].setAlive(true);
			goombas[i].setVelocity(0, rand() % 100);
			goombas[i].setPosition(rand() % 900 - 100,-50);
			return;
		}
	}
	goombas.push_back(Goomba());
	goombas[goombas.size() - 1].setAlive(false);
	goombas[goombas.size() - 1].setTexture(&texture);
	goombas[goombas.size() - 1].setSize(sf::Vector2f(100, 100));
}

void GoombaManager::update(float dt)
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			goombas[i].update(dt);
		}
	}
	deathCheck();
	textToDisplay.setString(std::to_string(goombasBeingRendered));
}

void GoombaManager::deathCheck()
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			
			if (goombas[i].getPosition().y > 600)
			{
				goombasBeingRendered--;
				goombas[i].setAlive(false);
			}
		}
	}
}



void GoombaManager::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			window->draw(goombas[i]);
		}
	}
	window->draw(textToDisplay);
}
