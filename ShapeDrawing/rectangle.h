 #ifndef RECTANGLE_H
 #define RECTANGLE_H
  
 #include "shape.h"
  
 namespace Shapes
 {
 class Rectangle : public Shape
 {
     int xTo;
     int yTo;
 public:
     Rectangle(int xFrom, int yFrom, int xTo, int yTo);
  
     bool isIn(int x, int y) const override;
  
     int getXTo() const{return xTo;};
     int getYTo() const{return yTo;};
 };
 } // namespace Shapes

 #endif 