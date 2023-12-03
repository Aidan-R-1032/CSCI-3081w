#include "duck.cc"
class Mallard : public Duck {
    public:
        void quack();
        void display();
        void fly();
};
void Mallard::display(){
    cout << "I am a Mallard duck!" << endl;
}
void Mallard::quack(){
    cout << "Quack!" << endl;
}
void Mallard::fly(){
    cout <<"I can fly!" << endl;
}