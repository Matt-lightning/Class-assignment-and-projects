#include <iostream>

using namespace std;

// Store the return of this function as an unsigned long!
unsigned long djb2(string str) {
   const char *ptr = str.c_str();
   unsigned long hash = 5381;
   int c;
   while ((c = *ptr++)) {
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
   }
   return hash;
}

int main() {

   return 0;
}
