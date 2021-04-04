#ifndef SHAPE_H
#define SHAPE_H

#include <utility> // std::pair<>

 namespace Shapes
 {
 typedef std::pair<int,int> Point;
  
 class Shape
 {
 protected:
     Point lowerLeftPoint;
  
 public:
     Shape(int x, int y) : lowerLeftPoint(x, y) {}
     virtual ~Shape() = default;
     virtual bool isIn(int x, int y) const = 0;
  
     auto getX() const
     {
         return lowerLeftPoint.first;
     }
     auto getY() const
     {
         return lowerLeftPoint.second;
     }
     void setX(int newX)
     {
         lowerLeftPoint.first = newX;
     }
     void setY(int newY)
     {
         lowerLeftPoint.second = newY;
     }
 };
 } // namespace Shapes
  
 #endif // SHAPE_H
