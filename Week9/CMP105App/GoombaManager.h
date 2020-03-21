#include "Goomba.h"
#include <math.h>
#include <vector>
#include <iostream>

#pragma once
class GoombaManager
{
public:
	GoombaManager();
	~GoombaManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void Render(sf::RenderWindow* window);
private:
	std::vector<Goomba> goombas;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::Text textToDisplay;
	int goombasBeingRendered = 0;
	sf::Font font;
};

