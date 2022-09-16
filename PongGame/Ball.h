#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::Vector2f position;
	sf::RectangleShape shape;
	
	float speed = 1500.f;
	float directionX = .2f;
	float directionY = .2f;
public:
	//constructor
	Ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	float getXVelocity();

	void boundsSides();
	void boundsBatOrTop();
	void boundsBottom();

	void update(sf::Time dTime);
};

