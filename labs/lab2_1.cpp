#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
   Triangle triangle1;
   Triangle triangle2;
   double base1;
   double base2;
   double height1;
   double height2;
   

   // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
   cin >> base1 >> height1;
   triangle1.SetBase(base1); 
   triangle1.SetHeight(height1);
      
   // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
   cin >> base2 >> height2;
   triangle2.SetBase(base1);
   triangle2.SetHeight(height2);
       
   cout << "Triangle with smaller area:" << endl;
   
   // TODO: Determine smaller triangle (use GetArea())  
   if(triangle1.GetArea() < triangle2.GetArea()){
       triangle1.PrintInfo();
   }
   else{
      triangle2.PrintInfo();
   }
   //       and output smaller triangle's info (use PrintInfo())
   
   
   return 0;
}