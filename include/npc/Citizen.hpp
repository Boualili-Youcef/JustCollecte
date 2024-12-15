#pragma once

#include "Unit.hpp"
#include "../ressources/Ressource.hpp"


class Citizen : public Unit {
private:
    int gatheringSpeed;  // Vitesse de collecte des ressources
    int carryingCapacity;  // Capacité de transport des ressources

public:
    // Constructeur
    Citizen(string name, int positionX, int positionY, int health, int attack, int speed, int gatheringSpeed, int carryingCapacity);

    // Méthode pour collecter des ressources
    void gatherResources(Ressource &ressource);

    // Getter pour la vitesse de collecte et la capacité de transport
    int getGatheringSpeed() const;
    int getCarryingCapacity() const;
};
