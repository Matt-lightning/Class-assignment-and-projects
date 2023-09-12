#include <iostream>
#include <cstring>
#include <fstream>

// Include any necessary libraries here.

using namespace std;

int main() {
ifstream textFile;
string fileName;

cin >> fileName;
textFile.open(fileName);

if(textFile.fail()){
   cout << "Could not open file." << endl;
}

while(!textFile.eof()){
   string file;
   getline(textFile, file);
   if(file.find("photo.jpg") != string::npos){
      file.replace(file.find("photo.jpg"), 9, "info.txt");
      cout << file << endl;
   }
   else{
      continue;
   }
}

   return 0;
}