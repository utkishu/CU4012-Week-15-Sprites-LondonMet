#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::BoundaryCheck(sf::Vector2f &movement)
{
    // Check left and right boundaries
    if (getPosition().x <= 0 || getPosition().x >= window->getSize().x - getSize().x)
    {
        movement.x = -movement.x; // Reverse horizontal movement
    }

    // Check top and bottom boundaries
    if (getPosition().y <= 0 || getPosition().y >= window->getSize().y - getSize().y)
    {
        movement.y = -movement.y; // Reverse vertical movement
    }
}
void Enemy::update(float dt, sf::Vector2f &movement)
{

		BoundaryCheck(movement);
		move(movement*dt);


}
