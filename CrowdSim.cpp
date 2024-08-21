#include "matplotlibcpp.h"
#include <iostream>
#include "AgentManager.h"
#include "Vector2D.h"
#include <cmath>
#include <chrono>

void plotCircle(double centerX, double centerY, double radius, int numPoints = 100);

namespace plt = matplotlibcpp;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



int main() {
    std::cout << "Starting Sim\n";
    AgentManager manager;
    manager.addAgent(Vector2D(0.0, 0.0), Vector2D(20.0, 20.0), Vector2D(200.0, 400.0));
    manager.addAgent(Vector2D(250.0, 250.0), Vector2D(10.0, 10.0), Vector2D(400.0, 200.0));
    
    auto lastTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> frameTime(1.0 / 60.0); // Target 60 FPS

    while (true) {
        // Measure elapsed time
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Update agents
        manager.updateAgents(deltaTime.count());

        // Collect agent positions for plotting
        std::vector<double> x_positions, y_positions;
        for (const auto& agent : manager.agents) {
            x_positions.push_back(agent.position.x);
            y_positions.push_back(agent.position.y);
        }

        // Clear the plot
        plt::clf();

        // Plot agent positions
        for (int i = 0; i < x_positions.size(); ++i) {
            plotCircle(x_positions[i], y_positions[i], 10.0);
        }

        // Set plot limits (adjust as needed)
        plt::xlim(0, 800);  // X-axis limits
        plt::ylim(0, 600);  // Y-axis limits

        // Draw the plot
        plt::pause(0.01);  // Pause briefly to update the plot
    }
    return 0;
}

void plotCircle(double centerX, double centerY, double radius, int numPoints) {
    std::vector<double> x_circle, y_circle;

    // Generate points around the circumference of the circle
    for (int i = 0; i < numPoints; ++i) {
        double angle = 2 * M_PI * i / numPoints;
        x_circle.push_back(centerX + radius * cos(angle));
        y_circle.push_back(centerY + radius * sin(angle));
    }

    // Close the circle by repeating the first point
    x_circle.push_back(x_circle.front());
    y_circle.push_back(y_circle.front());

    // Plot the circle
    plt::plot(x_circle, y_circle, "b-");  // 'b-' for blue line
}