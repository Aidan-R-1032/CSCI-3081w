#include <iostream>

using namespace std;

class personHeight{
    public:
        double height_in_inches(){
            return (feet * 12) + inches;
        }
        personHeight(int feet, double inches){
            this->feet = feet;
            this->inches = inches;
        }
        personHeight(){
            feet = 0;
            inches = 0.0;
        }
    private:
        int feet;
        double inches;
};
/*
Creates an instance of the personHeight class named Shonal with a height set to  6 feet and 0 inches.

Creates an instance of the personHeight class named Libby with a height set to 5 feet and 5 inches.

Creates an instance of the personHeight class named VeryShort with the default values (so no parameters are passed to the constructor).

Prints out Shonal’s height in inches.

Prints out Libby’s height in inches.

Prints out VeryShort’s height in inches.
*/
int main()
{
    personHeight Shonal = personHeight(6, 0.0);
    personHeight Libby = personHeight(5, 5.0);
    personHeight VeryShort = personHeight();
    cout << "Shonal height in inches: " << Shonal.height_in_inches() << endl;
    cout << "Libby height in inches: " << Libby.height_in_inches() << endl;
    cout << "VeryShort height in inches: " << VeryShort.height_in_inches() << endl;
    return 0;
}
