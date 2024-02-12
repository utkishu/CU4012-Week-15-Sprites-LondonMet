#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void update(float dt,sf::Vector2f &movement);

	void BoundaryCheck(sf::Vector2f &movement);

};

