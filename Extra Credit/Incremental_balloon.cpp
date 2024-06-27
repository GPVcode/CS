/* task is to design a program that models inflating a spherical balloon. First the balloon is inflated to have a certain diameter (which is provided as an input). Then inflate the balloon so that the diameter grows by an inch, and display the amount the volume has grown. Repeat that step: grow the diameter by another inch and show the growth of the volume.
Hint: The volume of a sphere is 4/3
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   const double PI = 3.14159265358979323846;

   /* Your code goes here */
   float diameter;
   cin >> diameter;
   double volume_1 = PI * diameter * diameter * diameter / 6;
   diameter++;
   double volume_2 = PI * diameter * diameter * diameter / 6;
   float growth_1 = volume_2 - volume_1;
   cout << "Increase: " << fixed << setprecision(0) << growth_1  << endl;
   /* Your code goes here */
   diameter++;
   double volume_3 = PI * diameter * diameter * diameter / 6;
   double growth_2 = volume_3 - volume_2;
   cout << "Increase: " << fixed << setprecision(0) << growth_2 << endl;

   return 0;
}