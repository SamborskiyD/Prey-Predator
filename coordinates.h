#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
private:
    int x;
    int y;
public:
    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);
    Coordinates();
    Coordinates(int x, int y);
    double distance(Coordinates secondPoint);
};

#endif // COORDINATES_H
