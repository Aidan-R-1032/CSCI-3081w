#include <iostream>
#include <string>
using namespace std;
int main(){
    string password;
    int userAge;

    cout << "Enter a password: ";
    cin >> password;
    cout << endl;
    cout << "Enter your age: ";
    cin >> userAge;
    cout << endl;
    
    if(password.size() < 8){
        if(userAge < 18){
            cout << "Access denied.";
        }
        else{
            cout << "Password too short, access denied.";
        }
    }
    else{
        if(userAge < 18){
            cout << "Too young, access denied.";
        }
        else{
            cout << "Access granted.";
        }
    }
    cout << endl;
    return 0;
}
