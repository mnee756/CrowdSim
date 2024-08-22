#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "Vector2D.h"

class Agent
{
private:
	
	
	

public:
	Agent(const Vector2D& pos, const Vector2D& vel, const Vector2D& goalPos, const double rad); // Constructor
	static const double v_max;
	static const double v_pref; //preferred velocity
	static const double a_max;
	Vector2D position;
	Vector2D velocity;
	Vector2D goalPosition;
	double radius;
	void update(double deltaTime, std::vector<Agent>& otherAgents);
	std::vector<Agent> detectObstacles(std::vector<Agent>& otherAgents, double neighbor_radius);
	bool isInRVO(Vector2D velocity,std::vector<Agent>& otherAgents);
	Vector2D planVelocity(std::vector<Agent>& otherAgents);
};
#endif // AGENT_H