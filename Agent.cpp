#include "Agent.h"
#include "Vector2D.h"

const double Agent::max_speed = 5.0;
Agent::Agent(const Vector2D& pos, const Vector2D& vel)
    : position(pos), velocity(vel), shape(20) {  // Initialize circle with radius 20
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos.x, pos.y);  // Set position to initial agent position
}

void Agent::update(double deltaTime) {
    position = position + velocity * deltaTime;
    shape.setPosition(position.x, position.y);
}

void Agent::detectObstacles() {
    
}

void Agent::draw(sf::RenderWindow& window) const {
    window.draw(shape);  // Draw the circle shape
}