#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
Part A

Prompt: We have given you specifications for a Duck class that has a few attributes (shown below).
Your job is to complete the Duck class and
finish the main method so that the ducks get ordered based on their coolness.
Hint: Look at C++ standard library sort function

DUCK:

variables:
1. name: string - the name of the duck
2. coolness: float - how cool the duck is (float from 1-10)
3. weight: double - average weight of the duck in pounds

functions:
1. default constructor
2. constructor with paramaters
3. getName: returns string
4. getCoolness: returns float
5. getWeight: returns double
*/

/**
Part B

Add the big three to your Duck class: destructor, copy constructor, copy assignment operator.
Add comments explaining what each one does, how they differ from one other, 
and differences between each of these and the default constructor.
*/

/**
Part C

We will now refactor our Duck class to be an abstract parent class (Duck) with child classes (Mallard, Canvasback, and Rubber).
    Each class should be its own file (duck.cc, mallard.cc, canvasback.cc, and rubber.cc)
The parent class will have the following pure virtual methods added:
    quack: void
    display: void
    swim: void
    fly: void
The child classes have the following behavior:
    Mallard
        quack: prints “Quack!”
        display: prints “I am a Mallard Duck!”
        swim: prints “I can swim!”
        fly: prints “I can fly!”
    Canvasback
        quack: prints “Quack!”
        display: prints “I am a Canvasback Duck!”
        swim: prints “I can swim!”
        fly: prints “I can fly!”
    Rubber
        quack: prints “Squeak!”
        display: prints “I am a Rubber Duck!”
        swim: prints “I can swim!”
        fly: prints “I can’t fly!”
1. One of these four added functions can be refactored such that it is not pure virtual anymore. Refactor that function accordingly.
2. Create an instance of each of the children classes in the main function.
3. You'll also have to comment out the ducks vector, all the push_backs, and sort from part A.
Why?
[Response here]
*/

/**
Part D

Create five functions that take in two ducks and output something. 
You get to define the functions however you want. 
Feel free to add new variables to the ducks in order to complete wanted functionality. 
In addition to writing the code, comments are required. 
Comments should not only detail the logic behind the code, 
but also explain how the different classes and methods interact to create an interesting experience. 
In the main method, demonstrate each one of your five functions in action.
This is your chance to have fun!

*/

// TODO part A: Duck class goes here
class Duck{
    public:
        Duck();
        Duck(string duckName, float duckCoolness, double duckWeight);
        string getName();
        float getCoolness();
        double getWeight();
        ~Duck();
        Duck(const Duck& originalDuck);
        Duck& operator=(const Duck& originalDuck);
        bool operator>(const Duck& originalDuck);
        virtual void quack();
        virtual void display();
        void swim();
        virtual void fly();
    private:
        string name;
        float coolness;
        double weight;
};
Duck::Duck(){
    name = "NA";
    coolness = 0;
    weight = 0.0;
}
Duck::Duck(string duckName, float duckCoolness, double duckWeight){
    name = duckName;
    coolness = duckCoolness;
    weight = duckWeight;
}
string Duck::getName(){
    return name;
}
float Duck::getCoolness(){
    return coolness;
}
double Duck::getWeight(){
    return weight;
}
// TODO part B: add the big three
// A destructor is a class member function that is automatically called when an object of the class is destroyed
Duck::~Duck(){
    cout << "Deallocating duck object: " << name << "(coolness: " << coolness << ", weight: " << weight << ")" << endl;
}
// A copy constructor is another version of a constructor that can be called with a single pass by reference argument
Duck::Duck(const Duck& originalDuck){
    name = originalDuck.name;
    coolness = originalDuck.coolness;
    weight = originalDuck.weight;
}
//The assignment operator "=" can be overloaded for a class via a member function, 
//known as the copy assignment operator, that overloads the built-in function "operator=", 
//the member function having a reference parameter of the class type and returning a 
//reference to the class type.
Duck& Duck::operator=(const Duck& originalDuck){
    if(this != &originalDuck){
        name = originalDuck.name;
        coolness = originalDuck.coolness;
        weight = originalDuck.weight;
    }
    return *this;
}
bool Duck::operator>(const Duck& originalDuck){
    return coolness > originalDuck.coolness;
}
void Duck::swim(){
    cout << "I can swim!" << endl;
}
// TODO part C: refactor Duck class and create a few new classes (separate files)
// TODO part D: 5 added functions and corresponding comments go here (or in your child class files depending on how you want to implement it)