


/*bool Balanced(string input){
    stack<char> BD();

    for(int i = 0; i < input.size(); i++ ){
        //string move = input[i];
        
        if(input[i] < input[i+2])

    }


    return BD.isEmpty();
}*/
#include <iostream>
//#include <stack>
#include <list>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    string input= argv[1];

    list<char> B;
    //stack<char> B;


    cout << "Stack:" << endl;

    for(char exp : input){

        

        cout << "character: " << exp << endl;
        if(exp != '(' && exp != ')' && exp != '[' && exp != ']' && exp != '{' && exp != '}' && exp != '<' && exp != '>'){
            cout << "Error: Invalid character " << exp << endl;
            return 0;
        }
        if(exp == '(' || exp == '[' || exp == '{' || exp == '<'){

            B.push_back(exp);
            //B.push(exp);
            cout << "Push" << endl;
            cout << "Stack: " /*<< exp << endl*/;

            for(char next : B){
                cout << next << " ";
            }
            cout << endl;
        }
        else if(exp == ')' || exp == ']' || exp == '}' || exp == '>'){
            if(B.empty()){
                cout << "Error: unmatched right symbol " << exp << endl;
                
                return 0;
            }
            else{
                char match = B.back();
                B.pop_back();
                if((match == '(' && exp == ')') || (match == '[' && exp == ']') || (match == '{' && exp == '}') || (match == '<' && exp == '>')){
                     cout << "Matching " << match << " and " << exp << endl;
                    cout << "Pop" << endl;
                    cout << "Stack: ";
                    for(char next : B){
                        cout << next << " ";
                    }
                    cout << endl;
                    
                }
                else{
                     cout << "Error: Mismatched Pair" << match << " and " << exp << endl;
                     return 0;
                }
            }
        }
       
    }
    if(!B.empty()){
        char match = B.back();
        cout << "Reached end of string" << endl;
        cout << "Error: unmatched left symbol " << match << endl;
        return 0;
        
    }

    cout << "Reached end of string" << endl;
    cout << "String is properly balanced" << endl; 

    



    
}