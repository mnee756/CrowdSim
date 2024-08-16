#ifndef AGENT_H
#define AGENT_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"

class Agent
{
private:
	
	
	

public:
	Agent(const Vector2D& pos, const Vector2D& vel); // Constructor
	static const double v_max;
	static const double v_pref;
	static const double a_max;
	sf::CircleShape shape;
	Vector2D position;
	Vector2D velocity;
	void update(double deltaTime, std::vector<Agent>& otherAgents);
	std::vector<Agent> detectObstacles(std::vector<Agent>& otherAgents);
	Vector2D getRVO(std::vector<Agent>& otherAgents);
	void draw(sf::RenderWindow& window) const;
	Vector2D planVelocity(std::vector<Agent>& otherAgents);


};
#endif // AGENT_H