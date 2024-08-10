// CrowdSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Moving Left and Right");

    // Create a circle shape
    sf::CircleShape circle(50); // Radius of 50 pixels
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375, 275); // Start in the middle of the window

    // Movement variables
    sf::Vector2f direction(1.0f, 0.0f); // Initially move right
    float moveSpeed = 200.0f; // Pixels per second
    sf::Clock clock; // Clock to measure time

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the elapsed time since the last frame
        sf::Time deltaTime = clock.restart();

        // Move the circle
        circle.move(direction * moveSpeed * deltaTime.asSeconds());

        // Check for boundary collisions and reverse direction if needed
        if (circle.getPosition().x <= 0 || (circle.getPosition().x + circle.getRadius() * 2) >= window.getSize().x) {
            direction.x *= -1.0f; // Reverse direction on X axis
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the circle
        window.draw(circle);

        // Display what was drawn
        window.display();
    }

    return 0;
}
