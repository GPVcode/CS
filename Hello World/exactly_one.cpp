#include <iostream>

using namespace std;

int main(){

    cout << "Enter x: " << endl;
    int x = 2;
    // cin >> x;
    cout << "enter y: " << endl;
    int y = 1;
    // cin >> y;

    // this is how to choose exactly 1
    if( x != 0 && y == 0 || x == 0 && y != 0 ){
      cout << "Exactly one of " << x << " and " << y << " is zero.";
    } else {
        cout << "Neither or both of " << x << " and " << y << " are zero.";
    }


};