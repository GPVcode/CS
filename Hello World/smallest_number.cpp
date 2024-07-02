#include <iostream>
using namespace std;

int main() {
   int smallest_number = 0;
   int input1, input2, input3;
   
   cin >> input1 >> input2 >> input3;
   
   smallest_number = input1;
   
   if (input2 < smallest_number){
      smallest_number = input2;
   }
   if (input3 < smallest_number){
      smallest_number = input3;
   }
   
   cout << smallest_number << endl;
   
   return 0;
}