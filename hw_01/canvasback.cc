#include "duck.cc"
class Canvasback : public Duck {
    public:
        void quack();
        void display();
        void fly();
};
void Canvasback::display(){
    cout << "I am a Canvasback duck!" << endl;
}
void Canvasback::quack(){
    cout << "Quack!" << endl;
}
void Canvasback::fly(){
    cout <<"I can fly!" << endl;
}