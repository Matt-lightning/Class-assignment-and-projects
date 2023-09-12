#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/*void openfiles(ifstream& input, ofstream& output, string inputfile, string outputfile){
    inputfile = argv[1];
    outputfile = argv[2];
    input.open(inputfile);
    output.open(outputfile);
    if(input.fail()){
        cout << "COULD NOT OPEN FILE" << endl;
        return;
    }
    if(output.fail()){
        cout << "COULD NOT OPEN FILE" << endl;
        return;
    }
    return;
}*/

int main(int argc, char* argv[]){

    if (argc != 3){
        cout << "Usage: ./p1 <inputfile> <outputfile>" << endl;
        return 0;
    }

    ifstream input;
    ofstream output;
    string inputfile;
    string outputfile;

   // openfiles(input, output, inputfile, outputfile);
    
    
    inputfile = argv[1];
    outputfile = argv[2];
    input.open(inputfile);
    output.open(outputfile);

    if(input.fail()){
        cout << "COULD NOR OPEN FILE" << endl;
        return 0;
    }
    if(output.fail()){
        cout << "COULD NOR OPEN FILE" << endl;
        return 0;
    }
    
    int i = 0;
    //string inputarray[1000];
    string sources[1000];
    string dests[1000];
    string bws[1000];
    while (input >>  sources[i] >> dests[i] >> bws[i]){
        cin >> sources[i] >> dests[i] >> bws[i];

        cout << sources[i] << " " << dests[i] << " " << bws[i] << endl;

        
        
        i++;
    }

    input.close();
    output.close();






    return 0;
}