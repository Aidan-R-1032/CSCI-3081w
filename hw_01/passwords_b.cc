#include <iostream>
#include <string>
using namespace std;
int main(){
    string p1;
    string p2;
    string output;
    cout << "Enter password: ";
    cin >> p1;
    cout << endl << "Re-Enter password for confirmation: ";
    cin >> p2;
    cout << endl;
    output = (p1 == p2) ? "passwords match" : "passwords do not watch";
    cout << output << endl;
    return 0;
}