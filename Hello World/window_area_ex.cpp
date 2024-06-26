#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

   // Prompt for and read the width and height
   // and the number of windows
   // float width = 2;
   // float height = 3;
   // int num_windows;
   // cin >> num_windows;
   // int area_of_windows = width * height * num_windows;
   // Compute and print the area of the wall without the windows
   const int WINDOW_SIZE = 6;
   float wall_height;
   float wall_width;
   float num_windows;
   cin >> wall_height;
   cin >> wall_width;
   cin >> num_windows;
   float window_area = num_windows * WINDOW_SIZE;
   cout << "Wall width: " << endl;
   cout << "Wall height: " << endl;
   cout << "Number of windows: " << endl;
   cout << "Area: " << fixed << setprecision(2) << wall_height * wall_width - window_area << endl;
   
   return 0;
}