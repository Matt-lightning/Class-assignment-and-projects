#include <iostream>
#include <fstream>

using namespace std;
int main(){

    string filename = "out.txt";

    //ofstream outfile("out.txt");
    ofstream outfile;
    outfile.open("outfile");

    outfile << "Hello World" << endl;

    outfile.close();

    

   ifstream input("out.txt");
    
    if(!input){
        cout << "COULD NOR OPEN FILE" << endl;
        return 0;
    } 

    int val;
    while (input >> val){
        cout << "Read: " << val << endl;

    }
    cout << "No more input" << endl;

    input.close();


    return 0;
}