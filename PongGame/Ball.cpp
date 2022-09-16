#include "Ball.h"

//constructor
Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	shape.setSize(sf::Vector2f(10, 10));
	shape.setPosition(position);
}
sf::FloatRect Ball::getPosition()
{
	return shape.getGlobalBounds();
}
sf::RectangleShape Ball::getShape()
{
	return shape;
}
void Ball::SetSpeedMultiplied(float multiplier)
{
	speed *= 1.1;
}
void Ball::resetSpeed()
{
	speed = baseSpeed;
}
float Ball::getXVelocity()
{
	return directionX;
}

void Ball::boundsSides()
{
	directionX = -directionX;
}
void Ball::boundsBatOrTop()
{
	directionY = -directionY;
}
void Ball::boundsBottom()
{
	position.y = 0;
	position.x = 500;
	directionY = -directionY;
}

/**
 * @brief update the ball position on the screen
 * @param dTime time to calculate movement
*/
void Ball::update(sf::Time dTime)
{
	position.y += directionY * speed * dTime.asSeconds();
	position.x += directionX * speed * dTime.asSeconds();

	//moving the ball
	shape.setPosition(position);
}