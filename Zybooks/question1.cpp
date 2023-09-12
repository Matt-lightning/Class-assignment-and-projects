#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
   istringstream inSS;      // Input string stream
   string lineString;       // Holds line of text
   int    areaCode;         // Area code (3 digits)
   int    officeCode;       // Central office code (3 digits)
   int    stationNum;       // Station number (4 digits)
   char   dummyChar1;
   char   dummyChar2;
   bool   isValidNumber;
   
   cout << "Enter a 10-digit phone number (or -1 to exit):" << endl;
   getline(cin, lineString);
   
   while (lineString != "-1") {
      isValidNumber = false; // Set to false before extracting phone number
      dummyChar1 = ' '; // Reset dummy chars to character other than - and (
      dummyChar2 = ' ';

      // Copy input to inSS's string buffer
      inSS.clear();
      inSS.str(lineString);
      
      // Try extracting area code.
      inSS >> areaCode;
      if (inSS.good()) {
         // Number format should be ###-###-####
         inSS >> dummyChar1 >> officeCode >> dummyChar2 >> stationNum;
         
         if (inSS.eof() && dummyChar1 == '-' && dummyChar2 == '-') {
            isValidNumber = true;
         }
      }
      else {
         // Number format should be (###) ###-####

         // Clear inSS state, and try extracting with area code in ()
         inSS.clear();
         inSS >> dummyChar1 >> areaCode >> dummyChar2;
         if (inSS.good()  && dummyChar1 == '(' && dummyChar2 == ')') {
            // Extract office code, then -, and then station number
            inSS >> officeCode >> dummyChar1 >> stationNum;
            if (inSS.eof() && dummyChar1 == '-') {
               isValidNumber = true;
            }
         }
      }

      if (isValidNumber) {
         cout << "   Standardized format: (" << areaCode << ") "
              << officeCode << "-" << stationNum << endl << endl;
      }
      else {
         cout << "   Invalid phone number." << endl << endl;
      }
      
      // Get next user input
      getline(cin, lineString);
   }
   
   return 0;
}