#include "Framework/GameObject.h"

#pragma once
class Goomba : public GameObject
{
public:
	Goomba();
	~Goomba();
	void update(float dt) override;
};

