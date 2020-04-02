#include "Bullet.h"
#include <math.h>
#include <vector>
#include <iostream>
#include "Framework/Input.h"

#pragma once
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void spawn(sf::Vector2f spawnPos);
	void update(float dt);
	void deathCheck();
	void Render(sf::RenderWindow* window);
	void setInput(Input* inputToSet);
private:
	std::vector<Bullet> bullets;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	Input* input;
	//sf::RenderWindow* rendWind;
};

