#include "Bat.h"

//Setting start params
Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(50,5));
	shape.setPosition(position);
}

sf::FloatRect Bat::getPosition()
{
	return shape.getGlobalBounds();
}
sf::RectangleShape Bat::getShape()
{
	return shape;
}

/**
 * @brief movement functions
*/
void Bat::moveLeft()
{
	bMovingLeft = true;
}
void Bat::moveRight()
{
	bMovingRight = true;
}
void Bat::stopLeft()
{
	bMovingLeft = false;
}
void Bat::stopRight()
{
	bMovingRight = false;
}
/**
 * @brief update location of player bat
 * @param dt - time
*/
void Bat::update(sf::Time dtime)
{
	if (bMovingLeft)
	{
		position.x -= speed * dtime.asSeconds();
	}
	if (bMovingRight)
	{
		position.x += speed * dtime.asSeconds();
	}
	shape.setPosition(position);
}