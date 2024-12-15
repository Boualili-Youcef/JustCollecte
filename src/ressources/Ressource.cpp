#include "../include/ressources/Ressource.hpp"

Ressource::Ressource(string name, int quantity, double time_to_gather, int positionX, int positionY)
    : name(name), quantity(quantity), time_to_gather(time_to_gather), positionX(positionX), positionY(positionY)
{
}

const string &Ressource::getName() const
{
    return name;
}

int Ressource::getQuantity() const
{
    return quantity;
}

double Ressource::getTimeToGather() const
{
    return time_to_gather;
}

int Ressource::getPositionX() const
{
    return positionX;
}
int Ressource::getPositionY() const
{
    return positionY;
}

void Ressource::setQuantity(int quantity)
{
    if (quantity >= 0)
    {
        this->quantity = quantity;
    }
    else
    {
        cout << "Quantity cannot be negative!" << endl;
    }
}
