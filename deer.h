#ifndef DEER_H
#define DEER_H

#include "animal.h"
#include "grass.h"

class Deer : public Animal
{
private:
    int foodAmount = 20;

public:
    Deer(Coordinates newPosition, int newVisionRadius);
    int getFoodAmount();

    Deer giveBirth(int visionRadius);

    void life(int dieAge, int mapWidth, int mapHeight, int birthPeriod,
              std::vector<Grass>& grassArray, std::vector<Deer>& population);

};

#endif // DEER_H
