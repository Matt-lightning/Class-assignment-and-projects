#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <list>


using namespace std;

class HashTable{
   private:
   vector<int>* table;
   string* refTable;
   int size;
   string strat;
   int a;
   int unique = 0;
   int totalCollisions = 0;
   int searchCollisions = 0;

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

public:
//Constructor
HashTable(int tableSize, string strat, int a){
   size = tableSize;
   table = new vector<int>[tableSize];
   refTable = new string[tableSize];
   this->strat = strat;
   this->a = a;
}
/*
// Linear probing
   int linearProbing(int Value, int i, int size) {
      return (Value + i) % size;
   }

   // Quadratic probing
   int quadraticProbing(int Value, int i, int size) {
      return (Value + i * i) % size;
   }

   // Double hashing
   int doubleHashing(int Value, int i, int size, int a) {
      return (Value + i * (a - (Value % a))) % size;
   }
*/
void insert(string key, int value){
   //cout << "inserting " << key << " " << value << endl;
   unsigned long ogIndex = djb2(key) % size;
   int index = ogIndex;
   int i = 1;
   while (table[index].empty() == false && refTable[index].compare(key) != 0) {
      if (strat.compare("lp") == 0)
         index = (ogIndex + i) % size;
      else if (strat.compare("qp") == 0)
         index = (ogIndex + (i * i)) % size;
      else if (strat.compare("dh") == 0)
         index = (ogIndex + i * (a - (djb2(key) % a))) % size;
      i++;
   }
   if (table[index].empty() == true)
      unique++;
   totalCollisions += i - 1;
   table[index].push_back(value);
   refTable[index] = key;
}

vector<int> search(string key){
   //cout << "searching " << key << endl;
   unsigned long ogIndex = djb2(key) % size;
   int index = ogIndex;
   int i = 1;
   while (table[index].empty() == false && refTable[index].compare(key) != 0) {
      if (strat.compare("lp") == 0)
         index = (ogIndex + i) % size;
      else if (strat.compare("qp") == 0)
         index = (ogIndex + (i * i) )% size;
      else if (strat.compare("dh") == 0)
         index = (ogIndex + i * (a - (djb2(key) % a))) % size;
      i++;
   }
   searchCollisions = i - 1;
   return table[index];
}

int getUnique(){
   return unique;
}

int getCollisions(){
   return totalCollisions;
}

int getSearchCollisions(){
   return searchCollisions;
}

void printTable() {
   for(int i =0; i < size; i++){
      cout << i <<": " << refTable[i] << endl;
   }
}

};



int main(int argc, char* argv[]) {

//  string inputfile = argv[1];
//    string queryfile = argv[2];
   int table_size = stoi(argv[3]);
   string collision = argv[4];
   int a = 1;
   if (argc == 6) {
     a = stoi(argv[5]);
   }

   fstream inputfile(argv[1]);
   fstream queryfile(argv[2]);
   if(!inputfile.is_open()){
      cout << "Failed to open input file." << endl;
      return 0;
   }
   if(!queryfile.is_open()){
      cout << "Failed to open query file." << endl;
      return 0;
   }
   string word;
   
   HashTable hash_table(table_size, collision, a);

   //cout << "The size of the hash table is " << table_size << endl;

   string line;
   int total_words = 0;
//insert words in the hash table while keeping up with total words and line numbers
   int line_number = 1;
  while(getline(inputfile, line)){
   for(int i = 0; i < line.length(); i++){
      if(!isalpha(line[i])){
         line[i] = ' ';
      }
      else if(isupper(line[i])){
         line[i] = tolower(line[i]);
      }
   }
      //cout << "in while loop inserting" << endl;
      istringstream iss(line);
      string word;
      while(iss >> word){
         hash_table.insert(word, line_number);
         total_words++;
      }
      line_number++;
      
   }
   

   // Print the total and unique word counts, and the total collisions
   cout << "The number of words found in the file was " << total_words << endl;
   cout << "The number of unique words found in the file was " << hash_table.getUnique() << endl;
   cout << "The number of collisions was " << hash_table.getCollisions() << endl;

   // Search for words in the query file
   while(queryfile >> word){
     // cout << "in while loop searching" << endl;
     cout << endl;
      vector<int> lines = hash_table.search(word);
      int num_collisions = hash_table.getSearchCollisions();
      cout << word << " appears on lines ";
      if (lines.empty()) {
         cout << "[]" << endl;
      } else {
         cout << "[";
         for (size_t i = 0; i < lines.size(); i++) {
            cout << lines[i];
            if (i < lines.size() - 1) {
               cout << ",";
            }
         }
         cout << "]" << endl;
      }
      cout << "The search had " << num_collisions << " collisions" << endl;
   }


   //hash_table.printTable();


   return 0;
}


   












   
   
   // int total_words = 0;
   // int unique_words = 0;
   // int collisions = 0;
  
   
   // ifstream query_file_stream(queryfile);
   // if (query_file_stream.is_open()) {
   //    while (query_file_stream >> word) {
   //       total_words++;
   //       vector<int> lines = hash_table.search(word);
   //       int num_collisions = hash_table.getCollisions();
   //       collisions += num_collisions;
   //       cout << word << " appears on lines ";
   //       if (lines.empty()) {
   //          cout << "[]" << endl;
   //       } else {
   //          cout << "[";
   //          for (size_t i = 0; i < lines.size(); i++) {
   //             cout << lines[i];
   //             if (i < lines.size() - 1) {
   //                cout << ",";
   //             }
   //          }
   //          cout << "]" << endl;
   //       }
   //       cout << "The search had " << num_collisions << " collisions" << endl;
   //    }
   //    query_file_stream.close();
   // } else {
   //    cout << "Failed to open query file." << endl;
   // }

   // // Print the total and unique word counts, and the total collisions
   // cout << "The number of words found in the file was " << total_words << endl;
   // cout << "The number of unique words found in the file was " << unique_words << endl;
   // cout << "The number of collisions was " << collisions << endl;