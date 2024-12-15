#include "../include/ressources/Trees/Olk.hpp"

Olk::Olk() : Tree("Olk", 200000, 3.5, 5, 5) {}

Olk::Olk(string name, int quantity, double time_to_gather, int positionX, int positionY)
    : Tree(name, quantity, time_to_gather, positionX, positionY) {}
