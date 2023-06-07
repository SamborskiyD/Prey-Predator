#ifndef TIGER_H
#define TIGER_H

#include "animal.h"
#include "deer.h"

class Tiger : public Animal
{


public:
    Tiger(Coordinates newPosition, int newVisionRadius);
    Tiger giveBirth(int visionRadius);

    void life(int dieAge, int mapWidth, int mapHeight, int birthPeriod,
              std::vector<Deer>& grassArray, std::vector<Tiger>& population);
};

#endif // TIGER_H
