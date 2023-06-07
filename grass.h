#ifndef GRASS_H
#define GRASS_H

#include "coordinates.h"

class Grass
{
private:
    Coordinates position;
    int foodAmount;

public:
    Grass(Coordinates position, int foodAmount);
    Coordinates getPosition();
    int getFoodAmount();
};

#endif // GRASS_H
