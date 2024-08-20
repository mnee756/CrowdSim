#include "Agent.h"
#include "Vector2D.h"

const double Agent::v_max = 5.0;
const double Agent::v_pref = 2.5;
const double Agent::a_max = 2.0; 

Agent::Agent(const Vector2D& pos, const Vector2D& vel, const Vector2D& goalPos)
    : position(pos), velocity(vel), goalPosition(goalPos), shape(20) {  // Initialize circle with radius 20
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos.x, pos.y);  // Set position to initial agent position
}

void Agent::update(double deltaTime, std::vector<Agent>& otherAgents)
{   
    velocity = planVelocity(otherAgents);
    position = position + velocity * deltaTime;
    shape.setPosition(position.x, position.y);
}


std::vector<Agent> Agent::detectObstacles(std::vector<Agent>& otherAgents)
{

    return otherAgents;
}

Vector2D Agent::getRVO(std::vector<Agent>& otherAgents)
{
    std::vector<Agent> neighbors = detectObstacles(otherAgents);
    Vector2D rvo = Vector2D(0.0, 0.0); //needs to be a vector of RVO's
    return rvo;
}

void Agent::draw(sf::RenderWindow& window) const {
    window.draw(shape);  // Draw the circle shape
}

Vector2D Agent::planVelocity(std::vector<Agent>& otherAgents)
{
    Vector2D rvo = getRVO(otherAgents); //No idea what RVO looks like
    //whole bunch of optimization???
    Vector2D velocity = Vector2D(10.0, 10.0);
    return velocity;
}