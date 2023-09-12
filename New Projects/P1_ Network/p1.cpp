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
    
    string sources[1000];
    string dests[1000];
    string bws[1000];
    string unique[1000];
    while (input >>  sources[i] >> dests[i] >> bws[i]){
       

        //cout << sources[i] << " " << dests[i] << " " << bws[i] << endl;
        i++;
    }
    
    // need every source and dest to be uppercase
    for(int i= 0 ; i < 1000; i++){
        if(sources[i] == ""){
            break;
        }
        if(islower(sources[i][0])){
            sources[i] = toupper(sources[i][0]);
        }
        
        cout << sources[i] << endl;
        
    }

    cout << "---------------------" << endl;

    for(int i= 0 ; i < 1000; i++){
        if(dests[i] == ""){
            break;
        }
        if(islower(dests[i][0])){
            dests[i] = toupper(dests[i][0]);
        }
        
        cout << dests[i] << endl;
        
    }

    cout << "---------------------" << endl;

    for(int i=0; i < sources[i].size(); i++){
        for(int j=0; j < dests[j].size(); j++){
            if(sources[i] == dests[j]){
                unique[i] = sources[i];
            }
            else if(sources[i] != sources[i+1]){
                unique[i] = sources[i];
            }   
            else if(dests[j] != dests[j+1]){
                unique[i] = dests[j];
            }
        }
        cout << unique[i] << endl;
    }

    input.close();
    output.close();






    return 0;
}