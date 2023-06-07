#include "tiger.h"

Tiger::Tiger(Coordinates newPosition, int newVisionRadius) : Animal(newPosition, newVisionRadius){}

Tiger Tiger::giveBirth(int visionRadius){

    return Tiger(this->getPosition(), visionRadius);
}


void Tiger::life(int dieAge, int mapWidth, int mapHeight, int birthPeriod,
                 std::vector<Deer>& deersArray, std::vector<Tiger>& population)
{
    if(age == dieAge || hungerLevel == 0){
        kill();
    }
    int foodIndex;
    if (isAlive == true){
        if(hungerLevel <= 70){
            foodIndex = findFood(deersArray);
            if (foodIndex == -1){
                moveInRandomSide(mapWidth, mapHeight);
            }
            else {
                moveTo(deersArray[foodIndex].getPosition());
                eat(deersArray[foodIndex].getFoodAmount());
                deersArray.erase(deersArray.begin()+foodIndex);
            }
        }
        else {
            moveInRandomSide(mapWidth, mapHeight);
        }

        if (age % birthPeriod == 0){
            population.push_back(giveBirth(mapWidth/6));
            moveInRandomSide(mapWidth, mapHeight);
        }
        age += 1;
    }
}
