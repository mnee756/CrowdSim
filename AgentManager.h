#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include <vector>
#include "Agent.h"

class AgentManager {
public:
    std::vector<Agent> agents;
    void addAgent(const Vector2D& position, const Vector2D& velocity, const Vector2D& goalPosition, const double radius);
    void updateAgents(double deltaTime);
};

#endif // AGENTMANAGER_H

