#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
   ifstream teamFS;
   string teamName; 
   int numWins;
   int numLosses;

   teamFS.open("teams.txt");

   if (!teamFS.is_open()) {
      cout << "Could not open file teams.txt." << endl;
      return 1;
   }

   // Read first team name
   getline(teamFS, teamName);

   // Read until end-of-file 
   while (!teamFS.fail()) {
      // Attempt to read wins
      teamFS >> numWins;

      if (teamFS.fail()) {
         // Win/loss line missing
         cout << teamName << " has no wins or losses" << endl;                        
      }
      else {
         // Attempt to read losses
         teamFS >> numLosses;

         if (teamFS.fail()) {
            // No losses provided
            cout << teamName << " has " << numWins << " wins" << endl;
         }
         else {
            // Win and losses provided
            cout << teamName << " win average is " 
                 << static_cast<double>(numWins) / (numWins + numLosses) << endl;
         }

         // Remove newline
         teamFS.ignore();                        
      }

      // Clear the error state
      teamFS.clear();

      // Attempt to read next team
      getline(teamFS, teamName);
   }

   teamFS.close();

   return 0;
}