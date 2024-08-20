#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include <vector>
#include "Agent.h"

class AgentManager {
public:
    std::vector<Agent> agents;
    void addAgent(const Vector2D& position, const Vector2D& velocity, const Vector2D& goalPosition);
    void updateAgents(double deltaTime);
};

#endif // AGENTMANAGER_H

