#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

//Hashnode implementation. This Node comprises of each node in the HashTable
class HashNode {
    public:
    std::vector<int> lineList;
    string key;
    
    public: 
    HashNode() {
        key = "";
    }
};
/*
class HashTable{
   private:
   vector<list<pair<string, vector<int>>>> table;
   int size;

   // Store the return of this function as an unsigned long!
unsigned long djb2(string str) {
   const char *ptr = str.c_str();
   unsigned long hash = 5381;
   int c;
   while ((c = *ptr++)) {
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c 
   }
   return hash;
}

public:
//Constructor
HashTable(int tableSize){
   size = tableSize;
   table.resize(size);
}

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

void insert(string key, int line){
   unsigned long Value = djb2(key) % size;
   for(auto &pair : table[Value]){
      if(pair.first == key){
         pair.second.push_back(line);
         return;
      }
   }
   table[Value].push_back(make_pair(key,vector<int>(1,line)));
}

vector<int> search(string key){
   unsigned long Value = djb2(key) % size;
   for(auto &pair : table[Value]){
      if(pair.first == key){
         return pair.second;
      }
   }
   return vector<int>();
}

int getTotal(){
   int total = 0;
   for(const auto &list : table){
      for(const auto &pair : list){
         total += pair.second.size();
      }
   }
   return total;
}

int getUnique(){
   int unique = 0;
   for(const auto &list : table){
      unique += list.size();
   } 
   return unique;
}

int getCollisions(){
   int Collisions = 0;
   for(const auto &list : table){
      if(list.size() > 1){
         Collisions += list.size() - 1;
      }
   }
   return Collisions;
}
};
*/

int search(vector<HashNode> table, string key, int &collisions) {
    //search the table if found the key, return index. Else return -1
    
    int index = 0;
    vector<HashNode>::iterator it;
    for (it = table.begin(); it != table.end(); ++it, index++) {
        if(it->key == key){
            collisions++;
            return index;
        }
         
    }
    return -1;
}
    
void printHashTable (vector<HashNode> table) {
    //Prints the Hash Table
    
    // for(int i = 0; i < table.size(); i++){
    //     cout << table[i].key << " appears on lines [";
    //     for
    // }

    for(int i =0; i < table.size(); i++){
        cout << table[i].key << " appears on lines [";
        for(int j = 0; j < table[i].lineList.size(); j++){
            cout << table[i].lineList[j] << ",";
        }
        cout << "]" << endl;
    }
//    
//     vector<HashNode>::iterator it;
//     for (it = table.begin(); it != table.end(); ++it) {
//         cout <<"\n" << it->key << " appears on lines [";
//         vector<int>::iterator lineIt;
//         for (lineIt = it->lineList.begin(); lineIt != it->lineList.end(); ++lineIt) {
//             if (lineIt != it->lineList.begin()) {
//                 cout << ",";
//             }
//             //cout << *lineIt;
//         }
//         cout << "]";
//     }
//     return;
}

vector<string> splitString(string str) {
    vector<string> vct;
    string alpha;
    for (char c : str) {
        if (isalpha(c)) {
            alpha.push_back(tolower(c));
        } else if (!alpha.empty()) {
            vct.push_back(alpha);
            alpha.clear();
        }
    }
    if (!alpha.empty()) {
        vct.push_back(alpha);
    }
    return vct;
}

     // Store the return of this function as an unsigned long!
unsigned long djb2(string str) {
   const char *ptr = str.c_str();
   unsigned long hash = 5381;
   int c;
   while ((c = *ptr++)) {
      hash = ((hash << 5) + hash) + c;  hash * 33 + c ;
   }
   return hash;
   }
    
int main(int argc, char** argv) {

    //Creates the Hash Table list 
    vector<HashNode> hashTable;

    ifstream infile(argv[1]);

    string line;
    int lineNumber = 0;
    int totalWords = 0;
    int uniqueWords = 0;
    int collisions = 0;
    int size = stoi(argv[3]);

    for(int i = 0; i < size; i++){
        HashNode node;
        hashTable.push_back(node);
    }



     set<string> uniqueWordSet;

    // read the file line by line
    while(getline(infile, line)) {   
        
        lineNumber += 1 ;
        vector<string> keys = splitString(line);
        totalWords += keys.size();
        // go through all 

        vector<string>::iterator key;
        for (key = keys.begin(); key != keys.end(); ++key) {
            

            int index = search(hashTable, *key, collisions);
            
            if (index == -1) {
                //key not found, create a new entry in hashTable
                HashNode node;
                node.key = *key;
                node.lineList.push_back(lineNumber);

                unsigned long a = djb2(*key);
                int index = a % size;

                if(*key != hashTable[index].key){
                    collisions++;

                    if(argv[4] == "lp"){
                        for(int i = 1; i < size; i++){
                            index = (index + i) % size;
                            if(hashTable[index].key == ""){
                                hashTable[index] = node;
                                break;
                            }
                            collisions++;

                        }

                    }

                    else if(argv[4] == "dh"){
                        for(int i = 0; i < size; i++){
                            index = (index + (i * index)) % size;
                            if(hashTable[index].key == ""){
                                hashTable[index] = node;
                                break;
                            }
                            collisions++;
                        }
                    }

                    else if(argv[4] == "qp"){
                         for(int i = 1; i < size; i++){
                            index = (index + (i*i)) % size;
                            
                            if(hashTable[index].key == ""){
                                hashTable[index] = node;
                                break;
                            }
                            collisions++;

                        }


                    }
                }

                hashTable[index] = node;
                uniqueWordSet.insert(*key);
                uniqueWords++;
            } else {
                //key found. Add the line number to the lineList
                hashTable[index].lineList.push_back(lineNumber);
            }
        }
    }
    cout << "The number of words found in the file was " << totalWords << endl;
    cout << "The number of unique words found in the file was " << uniqueWords << endl;
    cout << "The number of collisions was " << collisions << endl;

    printHashTable(hashTable);

   /* cout << "The number of words found in the file was " << totalWords << endl;
    cout << "The number of unique words found in the file was " << uniqueWords << endl;
    cout << "The number of collisions was " << collisions << endl;
*/
    infile.close();
    return 0;

}


