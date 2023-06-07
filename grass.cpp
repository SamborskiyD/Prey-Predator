#include "grass.h"

Grass::Grass(Coordinates newPosition, int newFoodAmount)
{
    position = newPosition;
    foodAmount = newFoodAmount;
}

Coordinates Grass::getPosition(){
    return position;
}

int Grass::getFoodAmount(){
    return foodAmount;
}
