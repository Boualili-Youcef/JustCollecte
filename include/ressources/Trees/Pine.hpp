#pragma once

#include "Tree.hpp"

class Pine : public Tree
{
public:
    Pine();
    Pine(string name, int quantity, double time_to_gather, int positionX, int positionY);
    
    ~Pine() = default;
};
