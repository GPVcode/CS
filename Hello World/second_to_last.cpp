#include <iostream>

using namespace std;
// THis is how to extract the second to last number
int main(){

int number = 501;
int second_to_last;

second_to_last = (number / 10) % 10;


cout << "The second to last number is " << second_to_last << endl;

return 0;
}