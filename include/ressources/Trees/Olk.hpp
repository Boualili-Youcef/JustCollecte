#pragma once

#include "Tree.hpp"

class Olk : public Tree
{
public:
    Olk();
    Olk(string name, int quantity, double time_to_gather, int positionX, int positionY);
    
    ~Olk() = default;
};
