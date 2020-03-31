#include "circle.h"
#include<stdexcept>
#include<iostream>
#include<cmath>

namespace Shapes
{

bool Circle :: isIn(int x, int y) const{
    float dist = sqrt(pow((this->getX() - x), 2) + pow((this->getY()- y), 2));
    int r = this->getRadius();
    return dist <= r;
}

}