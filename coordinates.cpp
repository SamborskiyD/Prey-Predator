#include "coordinates.h"
#include <cmath>

Coordinates::Coordinates() {
    x = 0;
    y = 0;
}

Coordinates::Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

double Coordinates::distance (Coordinates secontPoint) {
    return sqrt(pow(x - secontPoint.getX(), 2) + pow(y - secontPoint.getY(), 2));
}


int Coordinates::getX()
{
    return x;
}

int Coordinates::getY()
{
    return y;
}

void Coordinates::setX(int newX)
{
    x = newX;
}

void Coordinates::setY(int newY)
{
    y = newY;
}
