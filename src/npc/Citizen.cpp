#include "../include/npc/Citizen.hpp"

Citizen::Citizen(string name, int positionX, int positionY, int health, int attack, int speed, int gatheringSpeed, int carryingCapacity)
    : Unit(name, positionX, positionY, health, attack, speed), gatheringSpeed(gatheringSpeed), carryingCapacity(carryingCapacity) {}

void Citizen::gatherResources(Ressource &ressource)
{
    if (getPositionX() != ressource.getPositionX() || getPositionY() != ressource.getPositionY())
    {
        cout << getName() << " is not at the resource position and cannot gather resources." << endl;
        return;
    }

    cout << getName() << " is gathering resources at speed " << gatheringSpeed << " and has a carrying capacity of " << carryingCapacity << " units." << endl;

    int collected = 0;

    while (ressource.getQuantity() > 0 && carryingCapacity > collected)
    {
        // Attente avant de récolter (calculée en fonction de la vitesse de collecte)
        cout << getName() << " is waiting for " << gatheringSpeed << " seconds before gathering." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(gatheringSpeed)); // Attente avant de commencer à récolter

        // Collecte de ressources
        int toCollect = gatheringSpeed; // Quantité de ressources collectées dans ce cycle
        if (ressource.getQuantity() < toCollect)
        {
            toCollect = ressource.getQuantity(); // Ne pas dépasser la quantité disponible
        }

        // Réduire la quantité de ressources et augmenter la quantité collectée
        ressource.setQuantity(ressource.getQuantity() - toCollect);
        collected += toCollect;

        // Afficher l'état après la récolte
        cout << getName() << " has gathered " << toCollect << " units. Remaining resources: " << ressource.getQuantity() << "." << endl;

        // Si l'unité est à pleine capacité, arrêter la récolte
        if (collected >= carryingCapacity)
        {
            cout << getName() << " has reached carrying capacity." << endl;
            break;
        }

        if (ressource.getQuantity() == 0)
        {
            cout << "Resource depleted." << endl;
            break;
        }
    }
}

int Citizen::getGatheringSpeed() const { return gatheringSpeed; }

int Citizen::getCarryingCapacity() const { return carryingCapacity; }
