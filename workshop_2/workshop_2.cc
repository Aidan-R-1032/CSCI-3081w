using namespace std;
#include <math.h>

#include <iostream>
class MotorizedVehicle {
 public:
  void throttle() { cout << "speeds up" << endl; }
  virtual void refuel() { cout << "refueling" << endl; }
  virtual void display() { cout << "I am a MV" << endl; }
  virtual void brake() { cout << "slows down" << endl; }
};
class GasPowered : public MotorizedVehicle {
 public:
  void display() { cout << "I run on gas" << endl; };
};
class Hybrid : public MotorizedVehicle {
 public:
  void display() { cout << "I am a hybrid" << endl; }
  void brake() { cout << "battery charges as car slows" << endl; }
};
class Electric : public MotorizedVehicle {
 public:
  void display() { cout << "I am a EV" << endl; }
  void refuel() { cout << "EV is charging" << endl; }
};
class shape2D {
 protected:
  float width;
  float height;

 public:
  virtual float getArea() = 0;  // pure virtual- needed for extensibility;
                                // realization instead of inheritance
};
class Triangle : public shape2D {
 public:
  Triangle(float w, float h) {
    width = w;
    height = h;
  }
  float getArea() { return 0.5 * width * height; }
};
class Rectangle : public shape2D {
 public:
  Rectangle(float w, float h) {
    width = w;
    height = h;
  }
  float getArea() { return width * height; }
};
class Circle : public shape2D {
 public:
  Circle(float r) { width = r; }
  float getArea() { return pow(width, 2) * M_PI; }
};
int main() {
  MotorizedVehicle *mv = new Electric();
  mv->display();
  mv->refuel();
  mv->throttle();
  mv->brake();
  delete mv;
  GasPowered *g1 = new GasPowered();
  Hybrid *h1 = new Hybrid();
  Electric *e1 = new Electric();
  g1->display();
  g1->brake();
  g1->refuel();
  g1->throttle();
  h1->display();
  h1->brake();
  h1->refuel();
  h1->throttle();
  e1->display();
  e1->brake();
  e1->refuel();
  e1->throttle();
  delete g1;
  delete h1;
  delete e1;
  Triangle tri = Triangle(1, 1);
  cout << "Triangle area: " << tri.getArea() << endl;
  Rectangle rec = Rectangle(1, 1);
  cout << "Rectangle area: " << rec.getArea() << endl;
  Circle cir = Circle(1);
  cout << "Circle area: " << cir.getArea() << endl;
  // shape2D *s = new shape2D();
}