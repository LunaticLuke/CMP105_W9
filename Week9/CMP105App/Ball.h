#include "Framework/GameObject.h"

#pragma once
class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
};

