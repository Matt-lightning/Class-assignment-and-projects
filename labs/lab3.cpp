/*Instructor note:
Assume all input will be provided on a single line.

Write a program that removes all non-alphabetic characters from the given input.

Ex: If the input is:

-Hello, 1 world$!
the output is:

Helloworld
Your program must define and call the following function that takes a string as a parameter and returns the string without any non-alphabetic characters.
string RemoveNonAlpha(string userString)
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* Define your function here */ 
string RemoveNonAlpha(string userString){
    string correct;
    for(int i = 0; i < userString.length(); i++ ){
        if(isalpha(userString[i])){
             correct += userString[i];

        }


    }

    userString = correct;
    return userString;
}

int main() {
    string userString;

    getline(cin, userString);

    userString = RemoveNonAlpha(userString);
    
   
   /* Type your code here. Your code must call the function.  */
   cout << userString << endl;

   return 0;
}