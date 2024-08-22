#include "Agent.h"
#include "Vector2D.h"
#include <iostream>

const double Agent::v_max = 5.0;
const double Agent::v_pref = 2.5;
const double Agent::a_max = 2.0; 

Agent::Agent(const Vector2D& pos, const Vector2D& vel, const Vector2D& goalPos, const double rad)
    : position(pos), velocity(vel), goalPosition(goalPos), radius(rad) {  // Initialize circle with radius 20
}

void Agent::update(double deltaTime, std::vector<Agent>& otherAgents)
{   
    velocity = planVelocity(otherAgents);
    position = position + velocity * deltaTime;
}


std::vector<Agent> Agent::detectObstacles(std::vector<Agent>& otherAgents, double neighbor_radius)
{
    std::vector<Agent> neighbors;
    for (const auto& agentB : otherAgents) 
    {
        if ((agentB.position - this->position).magnitude() < neighbor_radius)
        {
            neighbors.push_back(agentB);
        }
    }

    return neighbors;
}

bool Agent::isInRVO(Vector2D velocity, std::vector<Agent>& neighbors)
{  
    for (const auto& neighbor : neighbors) {
        // Get the relative position and relative velocity
        Vector2D relativePosition = neighbor.position - this->position;
        Vector2D relativeVelocity = this->velocity - neighbor.velocity;

        double combinedRadius = this->radius + neighbor.radius;
        double distance = relativePosition.magnitude();

        // Calculate the cone half angle
        double theta = atan(combinedRadius / distance);

        // Normalize the relative position to get the direction of the cone
        Vector2D direction = relativePosition.normalize();
        double heading = velocity.angleBetween(relativePosition);
        if (heading < theta)
        {
            return true;
        }
    } 
    return false;
}

Vector2D Agent::planVelocity(std::vector<Agent>& otherAgents)
{
    //no path planning. optimal velocity is the vector directly to the goal at the preferred velocity
    Vector2D optimalVel = (goalPosition - position).normalize() * v_pref;
    
    std::vector<Agent> neighbors = detectObstacles(otherAgents, 25.0);
    bool rvo = isInRVO(velocity, neighbors); 
    std::cout << rvo;

    
    

    Vector2D velocity = optimalVel;
    return velocity;
}