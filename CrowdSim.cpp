// CrowdSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "AgentManager.h"
#include "Vector2D.h"
#include <chrono>

int main() {

    AgentManager manager;
    manager.addAgent(Vector2D(0.0, 0.0), Vector2D(20.0, 20.0), Vector2D(200.0, 400.0));
    manager.addAgent(Vector2D(250.0, 250.0), Vector2D(10.0, 10.0), Vector2D(400.0, 200.0));

    auto lastTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> frameTime(1.0 / 60.0); // Target 60 FPS

    sf::RenderWindow window(sf::VideoMode(800, 600), "CrowdSim");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Measure elapsed time
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Update agents
        manager.updateAgents(deltaTime.count());

        // Clear the window
        window.clear();

        // Draw agents
        for (const auto& agent : manager.agents) {
            agent.draw(window);
        }

        // Display the window contents
        window.display();
    }
    return 0;
}
