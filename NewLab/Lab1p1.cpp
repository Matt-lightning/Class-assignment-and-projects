#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

   int total = 0;

   cin >> total ;
total = total +1;
   vector<int> array(total);
   
   for(int i = 0; i < total; i++){
      cin >> array[i];
   }

   for(int i = 0; i < total - 1; i++){
    if(array[i] < array[total - 1]){
      cout << array[i] << "," ;
      }
   }
   cout << endl;



   return 0;
}


