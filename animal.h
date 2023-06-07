#ifndef ANIMAL_H
#define ANIMAL_H

#include "coordinates.h"
#include <cstdlib>
#include <vector>
#include <cmath>


class Animal
{
protected:
    int visionRadius;
    bool isAlive;
    Coordinates position;
    int hungerLevel;
    int age = 1;

public:
    Animal(Coordinates position, int newVisionRadius);
    Coordinates getPosition();
    bool getLive();
    void kill();
    void moveTo(Coordinates newPosition);
    void moveInRandomSide(int mapWidth, int mapHeight);
    void eat(int foodAmount);

    template <typename T>
    int findFood(std::vector<T>& foodArray) {
        int indexOfFood = 0;

        for (int i = 0; i < foodArray.size(); i++) {
            double distance = position.distance(foodArray[i].getPosition());
            if (distance <= visionRadius) {
                indexOfFood = i;
                return indexOfFood;
            }
        }
        return -1;
    }

};

#endif // ANIMAL_H
