#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#pragma once
class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();
	void update(float dt) override;
	void setTargetPos(sf::Vector2f targetToSet);
	void Shoot();
private:
	sf::Vector2f targetPos;
	sf::Vector2f direction;
	float speed = 75.f;
};

