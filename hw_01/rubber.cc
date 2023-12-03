#include "duck.cc"
class Rubber : public Duck {
    public:
        void quack();
        void display();
        void fly();
};
void Rubber::display(){
    cout << "I am a Canvasback duck!" << endl;
}
void Rubber::quack(){
    cout << "Squeak!" << endl;
}
void Rubber::fly(){
    cout <<"I can't fly!" << endl;
}