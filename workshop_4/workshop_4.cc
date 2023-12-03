#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
class Duck {
 protected:
  float cost;
  float tax;

 public:
  float getCost();
  float getTotalCost();
  float getTax();
};
float Duck::getCost() { return cost; }
float Duck::getTotalCost() { return cost * (1 + tax); }
float Duck::getTax() { return tax; }
class Mallard : public Duck {
 public:
  Mallard() { this->cost = 12.61; }
  Mallard(float tax) {
    this->tax = tax;
    this->cost = 12.61;
  }
};
class WoodDuck : public Duck {
 public:
  WoodDuck() { this->cost = 150.00; }
  WoodDuck(float tax) {
    this->tax = tax;
    this->cost = 150.00;
  }
};
class RubberDuck : public Duck {
 public:
  RubberDuck() { this->cost = 0.01; }
  RubberDuck(float tax) {
    this->tax = tax;
    this->cost = 0.01;
  }
};
class MNMallard : public Mallard {
  MNMallard() { this->tax = 0.06875; }
};
class MNWoodDuck : public WoodDuck {
  MNWoodDuck() { this->tax = 0.06875; }
};
class MNRubberDuck : public RubberDuck {
  MNRubberDuck() { this->tax = 0.06875; }
};
class CAMallard : public Mallard {
  CAMallard() { this->tax = 0.0725; }
};
class CAWoodDuck : public WoodDuck {
  CAWoodDuck() { this->tax = 0.0725; }
};
class CARubberDuck : public RubberDuck {
  CARubberDuck() { this->tax = 0.0725; }
};
class NYMallard : public Mallard {
  NYMallard() { this->tax = 0.045; }
};
class NYWoodDuck : public WoodDuck {
  NYWoodDuck() { this->tax = 0.045; }
};
class NYRubberDuck : public RubberDuck {
  NYRubberDuck() { this->tax = 0.045; }
};
class MN : public Duck {
 public:
  MN(Duck *duck) {
    this->cost = duck->getCost();
    this->tax = 0.06875;
  }
};
class CA : public Duck {
 public:
  CA(Duck *duck) {
    this->cost = duck->getCost();
    this->tax = 0.0725;
  }
};
class NY : public Duck {
 public:
  NY(Duck *duck) {
    this->cost = duck->getCost();
    this->tax = 0.045;
  }
};
class IFactory {
 public:
  virtual Mallard *createMallard() = 0;
  virtual WoodDuck *createWoodDuck() = 0;
  virtual RubberDuck *createRubberDuck() = 0;
};
class MNFactory : public IFactory {
 public:
  Mallard *createMallard() {
    Mallard *newMallard = new Mallard();
    Duck *mnMallard = new MN(newMallard);
    return (Mallard *)mnMallard;
  }
  WoodDuck *createWoodDuck() {
    WoodDuck *newMallard = new WoodDuck();
    Duck *mnWD = new MN(newMallard);
    return (WoodDuck *)mnWD;
  }
  RubberDuck *createRubberDuck() {
    RubberDuck *newRD = new RubberDuck();
    Duck *mnRD = new MN(newRD);
    return (RubberDuck *)mnRD;
  }
};
class CAFactory : public IFactory {
 public:
  Mallard *createMallard() {
    Mallard *newMallard = new Mallard();
    Duck *mnMallard = new CA(newMallard);
    return (Mallard *)mnMallard;
  }
  WoodDuck *createWoodDuck() {
    WoodDuck *newMallard = new WoodDuck();
    Duck *mnWD = new CA(newMallard);
    return (WoodDuck *)mnWD;
  }
  RubberDuck *createRubberDuck() {
    RubberDuck *newRD = new RubberDuck();
    Duck *mnRD = new CA(newRD);
    return (RubberDuck *)mnRD;
  }
};
class NYFactory : public IFactory {
 public:
  Mallard *createMallard() {
    Mallard *newMallard = new Mallard();
    Duck *mnMallard = new NY(newMallard);
    return (Mallard *)mnMallard;
  }
  WoodDuck *createWoodDuck() {
    WoodDuck *newMallard = new WoodDuck();
    Duck *mnWD = new NY(newMallard);
    return (WoodDuck *)mnWD;
  }
  RubberDuck *createRubberDuck() {
    RubberDuck *newRD = new RubberDuck();
    Duck *mnRD = new NY(newRD);
    return (RubberDuck *)mnRD;
  }
};
class Facade {
 private:
  MNFactory *mnf;
  CAFactory *caf;
  NYFactory *nyf;
  std::string state;
  std::string type;

 public:
  Facade() {
    mnf = new MNFactory();
    caf = new CAFactory();
    nyf = new NYFactory();
  }
  ~Facade() {
    delete mnf;
    delete caf;
    delete nyf;
  }
  void run() {
    query();
    Duck *userDuck = createDuck();
    std::cout << "The cost of a " << this->state << " " << this->type << " is "
              << std::fixed << std::setprecision(2) << userDuck->getTotalCost()
              << "." << std::endl;
  }
  Duck *createDuck() {
    Duck *placeholder;
    if (this->state == "MN") {
      if (this->type == "rubber") {
        placeholder = mnf->createRubberDuck();
      } else if (this->type == "wood") {
        placeholder = mnf->createWoodDuck();
      } else {
        placeholder = mnf->createMallard();
      }
    } else if (this->state == "CA") {
      if (this->type == "rubber") {
        placeholder = caf->createRubberDuck();
      } else if (this->type == "wood") {
        placeholder = caf->createWoodDuck();
      } else {
        placeholder = caf->createMallard();
      }
    } else {
      if (this->type == "rubber") {
        placeholder = nyf->createRubberDuck();
      } else if (this->type == "wood") {
        placeholder = nyf->createWoodDuck();
      } else {
        placeholder = nyf->createMallard();
      }
    }
    return placeholder;
  }
  void query() {
    std::string userIn = "";
    while (userIn != "MN" && userIn != "CA" && userIn != "NY") {
      std::cout << "Please enter a valid state (MN, CA, or NY): " << std::endl;
      std::cin >> userIn;
    }
    this->state = userIn;
    while (userIn != "rubber" && userIn != "wood" && userIn != "mallard") {
      std::cout << "Please enter a duck type (rubber, wood, mallard): "
                << std::endl;
      std::cin >> userIn;
    }
    this->type = userIn;
  }
};
int main() {
  Facade *f = new Facade();
  f->run();
  delete f;
}
