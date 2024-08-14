#include "AgentManager.h"


void AgentManager::addAgent(const Vector2D& position, const Vector2D& velocity) 
{
    Agent agent(position, velocity);
    agents.push_back(agent);
}

void AgentManager::updateAgents(double deltaTime) 
{
    for (auto& agent : agents) {
        agent.update(deltaTime);
    }
}
