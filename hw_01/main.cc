#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include "duck.cc"
#include "mallard.cc"
#include "rubber.cc"
#include "canvasback.cc"

bool compareDucks (Duck a_duck, Duck b_duck)
{
    return (a_duck > b_duck);
}
int main()
{
    // std::vector<Duck> ducks;
    // ducks.push_back(Duck(std::string("Fulvous Whistling Duck"), 8.6f, 1.6));
    // ducks.push_back(Duck(std::string("Domestic Duck"), 2.5f, 2.5));
    // ducks.push_back(Duck(std::string("CanvasBack"), 5.8f, 2.7));
    // ducks.push_back(Duck(std::string("Loon"), 10.0f, 10.0));
    // ducks.push_back(Duck(std::string("Mallard"), 7.6f, 2.5));
    // std::sort(ducks.begin(), ducks.end(), compareDucks);

    // TODO part A: sort the ducks based on coolness
    // Note: You may want to double check your work here by printing to standard output

    // for(int i = 0; i < ducks.size(); i++){
    //     Duck &currDuck = ducks.at(i);
    //    cout << currDuck.getName() << "Duck coolness: " << currDuck.getCoolness() << endl;
    // }

    // TODO part C: Create an instance of each of the children classes in the main function.
    // TODO part C: Comment out the ducks vector, all the push_backs, and sort from part A.
    
    Mallard *mallard_duck = new Mallard();
    mallard_duck->display();
    mallard_duck->quack();
    mallard_duck->swim();
    mallard_duck->fly();
    Canvasback *cback_duck = new Canvasback();
    cback_duck->display();
    cback_duck->quack();
    cback_duck->swim();
    cback_duck->fly();
    Rubber *rubber_duck = new Rubber();
    rubber_duck->display();
    rubber_duck->quack();
    rubber_duck->swim();
    rubber_duck->fly();

    // TODO part D: Demonstrate each one of your five defined functions.
    
    return 0;
}