#include "Agent.h"
#include "Vector2D.h"
#include <iostream>

const double Agent::v_max = 15.0;
const double Agent::v_pref = 10.0;
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

        double combinedRadius = (this->radius + neighbor.radius) * 5;
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

Vector2D Agent::hookeJeeves(Vector2D pref_vel, Vector2D curr_vel, std::vector<Agent>& neighbors, double step, double tolerance)
{
    Vector2D best_vel     = Vector2D(0.0, 0.0);
    Vector2D new_vel      = Vector2D(0.0, 0.0);
    Vector2D current_vel  = Vector2D(0.0, 0.0);

    //2D optimization function for velocity. Being in RVO is considered infinite penalty for now.
    while (step > tolerance)
    {
        for (int i = 0; i < 2; i++)
        {  
            new_vel = current_vel;
            new_vel[i] += step;
            if ((new_vel.distanceBetween(pref_vel) < best_vel.distanceBetween(pref_vel)) && !isInRVO(new_vel, neighbors))
            {
                best_vel = new_vel;
            }
            new_vel[i] -= 2 * step;
            if ((new_vel.distanceBetween(pref_vel) < best_vel.distanceBetween(pref_vel)) && !isInRVO(new_vel, neighbors))
            {
                best_vel = new_vel;
            }
        }
        if (current_vel != best_vel)
        {
            current_vel = best_vel;
        }
        else
        {
            step *= 0.5;
        }
    }

    return current_vel;
}

Vector2D Agent::planVelocity(std::vector<Agent>& otherAgents)
{
    //no path planning. optimal velocity is the vector directly to the goal at the preferred velocity
    Vector2D pref_vel = (goalPosition - position).normalize() * v_pref;
    
    std::vector<Agent> neighbors = detectObstacles(otherAgents, 25.0);
    double step_size = v_max;
    double tolerance = 0.25; // step size tolerance. 
    Vector2D optimal_vel = hookeJeeves(pref_vel, velocity, neighbors, step_size, tolerance);
    
    

    return optimal_vel;
}