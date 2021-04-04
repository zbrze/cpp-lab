#include "rectangle.h"

#include<stdexcept>
#include<iostream>
#include<cmath>

namespace Shapes
{
    Rectangle :: Rectangle(int xFrom, int yFrom, int xTo, int yTo) : Shape(xFrom, yFrom), xTo{xTo}, yTo{yTo}{};
    
    bool Rectangle :: isIn(int x, int y) const {
        return ((x >= this->getX() && x <= this->getXTo()) && (y>= this->getY() && y<= this->getYTo()));
}

}