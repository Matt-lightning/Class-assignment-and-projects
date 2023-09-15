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
    
    int size = 0;
    
    string sources[1000];
    string dests[1000];
    string bws[1000];
    string unique[1000];
    string leafs[1000];
    while (input >>  sources[size] >> dests[size] >> bws[size]){
       

        //cout << sources[i] << " " << dests[i] << " " << bws[i] << endl;
        size++;
    }
    
    // cout << "Sources" << endl;
    // cout << "---------------------" << endl;
    for(int i= 0 ; i < size; i++){
        if(sources[i] == ""){
            break;
        }
        for (long unsigned int j = 0; j < sources[i].size(); j++){
            if(islower(sources[i][j])){
                sources[i][j] = toupper(sources[i][j]);
            }
        }
        
       // cout << sources[i] << endl;
        
    }
    // cout << "---------------------" << endl;
    // cout << "Dests" << endl;

    // cout << "---------------------" << endl;

    for(int i= 0 ; i < size; i++){
        if(dests[i] == ""){
            break;
        }

         for (long unsigned int j = 0; j < dests[i].size(); j++){
            if(islower(dests[i][j])){
                dests[i][j] = toupper(dests[i][j]);
            }
        }
        
        // cout << dests[i] << endl;
        
    }

    // cout << "---------------------" << endl;
    // cout << "Uniques" << endl;

    // cout << "----------------------" << endl;

    int uniqueSize = 2;
    unique[0] = sources[0];
    unique[1] = dests[0];
    for(int i=1; i < size; i++){ // This loop sorts through the sources and dests and adds them to the unique array
        bool here = false;
         
        for(int j=1; j < size; j++){ // This loop checks if the source and dests is already in the unique array
            if(sources[i] == unique[j]){
                here = true;
            }
            }
            if(here == false){
                unique[uniqueSize] = sources[i];
                uniqueSize++;
            } 
            here = false;
            for(int j=1; j < size; j++){ // This loop checks if the source and dests is already in the unique array
            if(dests[i] == unique[j]){
                here = true;
            }
            }
            if(here == false){
                unique[uniqueSize] = dests[i];
                uniqueSize++;
            }

        }
        //cout << unique[i] << endl;
    

    //cout << "here" << endl;

    for (int i = 0; i < uniqueSize; i++) {
        cout << unique[i] << endl;
    }
    cout << endl;
    cout << endl;

    // //leafs
    int leafSize = 0;
    // for(int i=0; i < size; i++){
    //     // if(leafs[i] == ""){
    //     //     break;
    //     // }
    //     for( int j=0; j < size; j++){
    //         if(unique[i] == sources[j] && unique[i] == dests[j]){
    //             leafs[leafSize] = unique[i];
    //             leafSize++;
    //         }
    //     }
    // }
    for(int i=1; i < size; i++){ 
        bool here = false;
         
        for(int j=1; j < size; j++){ 
            if(leafs[i] == unique[j]){
                here = true;
            }
            }
            if(here == false){
                unique[uniqueSize] = sources[i];
                uniqueSize++;
            } 
            here = false;
            for(int j=1; j < size; j++){ 
            if(dests[i] == unique[j]){
                here = true;
            }
            }
            if(here == false){
                unique[uniqueSize] = dests[i];
                uniqueSize++;
            }

        }

    for (int i = 0; i < leafSize; i++) {
        cout << leafs[i] << endl;
    }

    input.close();
    output.close();






    return 0;
}