#include "animal.h"

Animal::Animal(Coordinates newPosition, int newVisionRadius)
{
    position.setX(newPosition.getX());
    position.setY(newPosition.getY());
    isAlive = true;
    hungerLevel = 100;
    visionRadius = newVisionRadius;
}

Coordinates Animal::getPosition(){
    return position;
}


bool Animal::getLive(){
    return isAlive;
}

void Animal::kill(){
    isAlive = false;
}

void Animal::moveTo(Coordinates newPosition){
    position.setX(newPosition.getX());
    position.setY(newPosition.getY());
    hungerLevel -= 20;
}

void Animal::moveInRandomSide(int mapWidth, int mapHeight){
    int randSide, newX, newY;
    do
    {
        randSide = rand()%8 + 1;
        switch(randSide)
        {
            case 1:
                newX = position.getX() + visionRadius;
                newY = position.getY();
                break;
            case 2:
                newX = position.getX() - visionRadius;
                newY = position.getY();
                break;
            case 3:
                newY = position.getY() + visionRadius;
                newX = position.getX();
                break;
            case 4:
                newY = position.getY() - visionRadius;
                newX = position.getX();
                break;
            case 5:
                newY = position.getY() - visionRadius;
                newX = position.getX() - visionRadius;
                break;
            case 6:
                newY = position.getY() + visionRadius;
                newX = position.getX() - visionRadius;
                break;
            case 7:
                newY = position.getY() - visionRadius;
                newX = position.getX() + visionRadius;
                break;
            case 8:
                newY = position.getY() + visionRadius;
                newX = position.getX() + visionRadius;
                break;
        }
    }while((newX < 0 && newX > mapWidth) && (newY < 0 && newY > mapHeight));
    position.setX(newX);
    position.setY(newY);
    hungerLevel -= 10;
    return;
}


void Animal::eat(int foodAmount) {
    hungerLevel += foodAmount;
}



