#include "Framework/GameObject.h"
#include "BulletManager.h"

#pragma once
class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float dt) override;
	void handleInput(float dt) override;
	BulletManager getBulletManager();
private:
	sf::Texture texture;
	BulletManager bullets;
};

