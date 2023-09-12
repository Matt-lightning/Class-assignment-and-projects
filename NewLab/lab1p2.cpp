#include <iostream>
using namespace std;

void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4){
    int temp;
    temp = userVal1;
    userVal1 = userVal2;
    userVal2 = temp;
    temp = userVal3;
    userVal3 = userVal4;
    userVal4 = temp;

    cout << userVal1 << " " << userVal2 << " " << userVal3 << " " << userVal4 << endl;


}

int main() {
   
   int userVal1 = 0;
   int userVal2 = 0;
    int userVal3 = 0;
    int userVal4 = 0;

    cin >> userVal1 >> userVal2 >> userVal3 >> userVal4;
    
    SwapValues(userVal1, userVal2, userVal3, userVal4);

   return 0;
}