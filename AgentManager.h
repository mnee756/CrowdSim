#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include <vector>
#include "Agent.h"

class AgentManager {
public:
    std::vector<Agent> agents;
    void addAgent(const Vector2D& position, const Vector2D& velocity);
    void updateAgents(double deltaTime);
};

#endif // AGENTMANAGER_H

