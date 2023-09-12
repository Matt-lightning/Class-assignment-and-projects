#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemoveNonAlpha(string userString){
   string allAlpha = "";
   for(int i = 0; i < userString.length(); i++){
      if(isalpha(userString[i])){
         allAlpha += userString[i];
      }
   }

   
   return allAlpha;
}

int main() {
   
   string userString;

   getline(cin,userString);


   cout << RemoveNonAlpha(userString) << endl;


   return 0;
}