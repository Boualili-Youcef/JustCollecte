#include "../include/ressources/Trees/Pine.hpp"

Pine::Pine() : Tree("Pine", 20000, 1.0, 5, 5) {}

Pine::Pine(string name, int quantity, double time_to_gather, int positionX, int positionY)
    : Tree(name, quantity, time_to_gather, positionX, positionY) {}
