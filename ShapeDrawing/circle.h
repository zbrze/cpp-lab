 #ifndef CIRCLE_H
 #define CIRCLE_H
  
 #include "shape.h"
  
 namespace Shapes
 {
 class Circle : public Shape
 {
     int radius;
 public:
     Circle(int xCenter, int yCenter, int radius) : Shape(xCenter, yCenter), radius{radius} {};
  
     auto getRadius() const {return radius;}
  
     bool isIn(int x, int y) const override;
 };
 } // namespace Shapes
  
 #endif // CIRCLE_H