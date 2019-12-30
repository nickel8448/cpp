#include <iostream>

class Shape {
  public:
    virtual void getShapeKind() = 0;
    virtual void drawShape() = 0; 
};

class Circle : public Shape {
  public:
    virtual void getShapeKind() {
      std::cout << "Circle shape";
    } 
    virtual void drawShape() {
      std::cout << "Drawing cicle";
    }
};

int main() {
  Shape* circle = new Circle;  
  circle->getShapeKind();
}
