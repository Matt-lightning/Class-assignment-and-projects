#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
   double sampleValue1 = 0.2;
   double sampleValue2 = 0.3;
   double sampleValue3 = 0.7;
   double sampleValue4 = 0.0;
   double sampleValue5 = 0.25;
   
   
   cout << "sampleValue1 using just cout: " 
        << sampleValue1 << endl;

   cout << setprecision(25)
        << "sampleValue1 is " << sampleValue1 << endl
        << "sampleValue2 is " << sampleValue2 << endl
        << "sampleValue3 is " << sampleValue3 << endl
        << "sampleValue4 is " << sampleValue4 << endl
        << "sampleValue5 is " << sampleValue5 << endl;
   
   return 0;
}