#include <iostream>
#include <vector>
using namespace std;

int main() {

   int amount = 0;
   int sort[amount];
   int thresh;
   int gd = 0;
   int output[gd];
   

   cin >> amount;


   for(int i = 0; i < amount; i++){
    cin >> sort[i];
   }

   cin >> thresh;

   for(int i = 0; i < amount; i++){
    if(sort[i] <= thresh){
        output[i] = sort[i];
        gd++;
    }
   }

   for(int i = 0; i < gd; i++){
    cout << output[i] << ",";

   }

   cout << endl;



   return 0;
}