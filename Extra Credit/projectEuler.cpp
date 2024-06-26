/*
Multiples of 3 or 5
Problem 1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9. 
The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
using namespace std;


int main(){

    // variable counting sum of numbers;
    int sum;

    // loop through 1-1000
        // if the number is divisible by 3 or 5, add it to the sum variable.
    for(int i = 0; i < 1000; i++){
       if(i % 3 == 0 || i % 5 == 0){
        sum += i;
        cout << i << " is divisible by 3 or 5" << endl;
       }
    }

    cout << "the sum total of values lower that 100 divisible by 5 or 3 are:" << endl;
    cout << sum << endl;

    return 0;
};