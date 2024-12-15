#pragma once

#include <iostream>

using namespace std;

class Ressource
{
private:
    string name;
    int quantity;
    double time_to_gather;
    int positionX, positionY;  // Position de l'unité sur une carte

public:
    Ressource(string name, int quantity, double time_to_gather, int positionX, int positionY) ;
    virtual ~Ressource() = default;

    const string &getName() const;
    int getQuantity() const;
    double getTimeToGather() const; 
    int getPositionX() const;
    int getPositionY() const;

    void setQuantity(int quantity);

};