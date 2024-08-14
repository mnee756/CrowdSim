#ifndef AGENT_H
#define AGENT_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"

class Agent
{
private:
	
	
	

public:
	Agent(const Vector2D& pos, const Vector2D& vel); // Constructor
	static const double max_speed;
	sf::CircleShape shape;
	Vector2D position;
	Vector2D velocity;
	void update(double deltaTime);
	void detectObstacles();
	void draw(sf::RenderWindow& window) const;



};
#endif // AGENT_H