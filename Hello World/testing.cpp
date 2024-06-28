#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

cout << "Values: ";

int x;
x = 3;
int y;
y = 8;
string str = "C++ Program";

cout << "Average: " << fixed << setprecision(2) << (x + y) / 2.0 << endl;
cout << str.substr(0, 1) << str.substr(str.length() - 1, 1);
return 0;
};