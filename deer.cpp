#include "deer.h"

Deer::Deer(Coordinates newPosition, int newVisionRadius) : Animal(newPosition, newVisionRadius){

}

Deer Deer::giveBirth(int visionRadius){

    return Deer(position, visionRadius);
}

int Deer::getFoodAmount() {
    return foodAmount;
}

void Deer::life(int dieAge, int mapWidth, int mapHeight, int birthPeriod,
                std::vector<Grass>& grassArray, std::vector<Deer>& population)
{

    if(age == dieAge || hungerLevel == 0){
        kill();
    }

    int foodIndex;

    if (isAlive == true){
        if(hungerLevel <= 70){
            foodIndex = findFood(grassArray);
            if (foodIndex == -1){
                moveInRandomSide(mapWidth, mapHeight);
            }
            else{
                moveTo(grassArray[foodIndex].getPosition());
                eat(grassArray[foodIndex].getFoodAmount());
                grassArray.erase(grassArray.begin()+foodIndex);
            }
        }
        else {
            moveInRandomSide(mapWidth, mapHeight);
        }
        if (age % birthPeriod == 0 && age < dieAge/2){
            population.push_back(giveBirth(mapWidth/10));
            moveInRandomSide(mapWidth, mapHeight);
        }
        age += 1;
    }
}
