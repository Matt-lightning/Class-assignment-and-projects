#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){

    char c_str = "Hello";
    int len = strlen(c_str);

    string str= "world";
    cout << str << endl;
    cout << str.at(1) << " " << str[1] << endl;

    str += " ! fgfg";

    cout << str << endl;

    bool b = (str == "world! fgfg");
    cout << b << endl;

    for(int i = 0; i < str.length(); i++){
        cout << str[i] << " ";
    }
    cout << endl;

    string s2 = "fgfgjh";
    string s3 = str + s2;

    


}
