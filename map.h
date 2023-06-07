#ifndef MAP_H
#define MAP_H
#include <vector>
#include "grass.h"
#include "deer.h"
#include "tiger.h"

class Map {

private:
    int mapWidth;
    int mapHeight;
    int mapDeerDieAge;
    int mapTigerDieAge;
    int mapDeerBirthPeriod;
    int mapTigerBirthPeriod;
    std::vector<Grass> grassArray;
    std::vector<Deer> deersPopulation;
    std::vector<Tiger> tigersPopulation;

public:

    Map();
    Map(int newWidth, int newHeigth, int deerDieAge, int tigerDieAge,
        int deerBirthTime, int tigerBirthTime);

    void start(int startDeersAmount, int startTigersAmount);

    void refresh();

    int getMapWidth();
    int getMapHeight();

    std::vector<Grass>& getGrassArray();
    std::vector<Deer>& getDeersPopulation();
    std::vector<Tiger>& getTigersPopulation();

};

#endif // MAP_H
