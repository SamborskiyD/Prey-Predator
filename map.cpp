#include "map.h"

Map::Map(){
    mapWidth = 0;
    mapHeight = 0;
    mapDeerDieAge = 0;
    mapDeerBirthPeriod = 0;
    mapTigerDieAge = 0;
    mapTigerBirthPeriod = 0;
}

Map::Map(int newWidth, int newHeigth, int deerDieAge, int tigerDieAge,
         int deerBirthTime, int tigerBirthTime)
{
    mapWidth = newWidth;
    mapHeight = newHeigth;
    mapDeerDieAge = deerDieAge;
    mapDeerBirthPeriod = deerBirthTime;
    mapTigerDieAge = tigerDieAge;
    mapTigerBirthPeriod = tigerBirthTime;
}

void Map::start(int startDeersAmount, int startTigersAmount)
{
    int newX = 0, newY = 0;
    for (int i = 0; i < startDeersAmount; i++){

        newX = rand() % mapWidth;
        newY = rand() % mapHeight;
        deersPopulation.push_back(Deer({newX, newY}, mapWidth/10));
    }
    for (int i = 0; i < startTigersAmount; i++){

        newX = rand() % mapWidth;
        newY = rand() % mapHeight;
        tigersPopulation.push_back(Tiger({newX,newY}, mapWidth/6));
    }
    for (int i = 0; i < startDeersAmount*10; i++){

        newX = rand() % mapWidth;
        newY = rand() % mapHeight;
        grassArray.push_back(Grass({newX,newY}, 10));
    }
}

void Map::refresh()
{
    int newX, newY;
    for (int i = 0; i < deersPopulation.size(); i++)
    {
        deersPopulation[i].life(mapDeerDieAge, mapWidth, mapHeight, mapDeerBirthPeriod, grassArray, deersPopulation);
        if (deersPopulation[i].getLive() == false){
            deersPopulation.erase(deersPopulation.begin()+i);
            i--;
        }
    }
    for (int i = 0; i < tigersPopulation.size(); i++)
    {
        tigersPopulation[i].life(mapTigerDieAge, mapWidth, mapHeight, mapTigerBirthPeriod, deersPopulation, tigersPopulation);
        if (tigersPopulation[i].getLive() == false){
            tigersPopulation.erase(tigersPopulation.begin()+i);
            i--;
        }
    }
    for (int i = 0; i < deersPopulation.size()/3; i++){

        newX = rand() % mapWidth;
        newY = rand() % mapHeight;
        grassArray.push_back(Grass({newX,newY}, 10));
    }

}

int Map::getMapWidth()
{
    return mapWidth;
}

int Map::getMapHeight()
{
    return mapHeight;
}

std::vector<Grass>& Map::getGrassArray(){
    return grassArray;
}

std::vector<Deer>& Map::getDeersPopulation(){
    return deersPopulation;
}

std::vector<Tiger>& Map::getTigersPopulation(){
    return tigersPopulation;
}
