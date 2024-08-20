#include "AgentManager.h"


void AgentManager::addAgent(const Vector2D& position, const Vector2D& velocity, const Vector2D& goalPosition) 
{
    Agent agent(position, velocity, goalPosition);
    agents.push_back(agent);
}

void AgentManager::updateAgents(double deltaTime) 
{
    // Pretty sure this is suboptimal. TODO: Analyze efficiency
    for (unsigned int i = 0; i < agents.size(); ++i) 
    {
        std::vector<Agent> otherAgents;
        for (unsigned int j = 0; j < agents.size(); ++j) 
        {
            if (i != j) 
            {
                otherAgents.push_back(agents[j]);
            }
        }
        agents[i].update(deltaTime, otherAgents);
    }
}
