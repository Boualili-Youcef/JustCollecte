#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <thread>
#include "../include/npc/Citizen.hpp"
#include "../include/ressources/Trees/Olk.hpp"

void moveAndGather(std::shared_ptr<Citizen> citizen, Olk& olkResource, sf::RectangleShape& citizenShape) {
    int targetX = olkResource.getPositionX();
    int targetY = olkResource.getPositionY();
    bool moving = true;

    while (moving) {
        int deltaX = targetX - citizen->getPositionX();
        int deltaY = targetY - citizen->getPositionY();

        double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        if (distance < citizen->getSpeed()) {
            citizen->setPosition(targetX, targetY);
            moving = false;
        } else {
            double moveX = (deltaX / distance) * citizen->getSpeed();
            double moveY = (deltaY / distance) * citizen->getSpeed();

            citizen->setPosition(citizen->getPositionX() + static_cast<int>(moveX), citizen->getPositionY() + static_cast<int>(moveY));
        }

        citizenShape.setPosition(citizen->getPositionX(), citizen->getPositionY());

        // Add a small delay to make the movement visible
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Start gathering resources
    while (true) {
        citizen->gatherResources(olkResource);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Citizen Gathering Resources");

    // Create Citizens and an Olk resource
    std::vector<std::shared_ptr<Citizen>> citizens = {
        std::make_shared<Citizen>("Youcef", 50, 50, 100, 10, 5, 2, 50),
        std::make_shared<Citizen>("Rudolf", 50, 5, 100, 10, 5, 2, 50),
        std::make_shared<Citizen>("King", 150, 58, 100, 10, 5, 2, 50)
    };

    Olk olkResource("Olk", 2000, 3.5, 400, 300);

    // Create shapes to represent the Citizens and the Olk resource
    std::vector<sf::RectangleShape> citizenShapes;
    for (const auto& citizen : citizens) {
        sf::RectangleShape shape(sf::Vector2f(20, 20));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(citizen->getPositionX(), citizen->getPositionY());
        citizenShapes.push_back(shape);
    }

    sf::CircleShape olkShape(10);
    olkShape.setFillColor(sf::Color::Green);
    olkShape.setPosition(olkResource.getPositionX(), olkResource.getPositionY());

    // Create threads for each Citizen
    std::vector<std::thread> threads;
    for (size_t i = 0; i < citizens.size(); ++i) {
        threads.emplace_back(moveAndGather, citizens[i], std::ref(olkResource), std::ref(citizenShapes[i]));
    }

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the Citizens and the Olk resource
        for (const auto& shape : citizenShapes)
        {
            window.draw(shape);
        }
        window.draw(olkShape);

        // Display the contents of the window
        window.display();

        // Add a small delay to make the movement visible
        sf::sleep(sf::milliseconds(100));
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}