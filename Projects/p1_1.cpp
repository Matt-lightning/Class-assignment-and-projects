/*Suppose that we are trying to crack a substitution cipher (wiki link), and that we have some partial information that should help us be able to decode the encoded text. Write a C++ program that operates as described below.

Name your program p1.cpp. Your program should accept three command line arguments. Argument 1 and 2 are filenames and argument 3 is a string containing a word.

The first file will contain exactly two lines that represent a way to encode text. The first line will be a subset of the letters A-Z, and the corresponding characters on the second line will represent the encoding. For example, in the file shown below, the code letter for an A would be a P and the code for an E would be an X. This means that in an encoded piece of text, the letter X would represent an E in the original text. Note that because we only have partial information not all of the letters A…Z will necessarily appear on the first line.

ABCDEF…
PLMAXY…
The second file will be an encoded text. Only the letters A…Z will be encoded. All other whitespace or punctuation will be unchanged.

Since not all of the letters appear in file1, there may be a letter in the encoded text that you do not know how to decode. This is where the third argument is used. The third argument will be a word that is known to appear in the source text.

Your job is to try assigning corresponding letters to the parts of the cipher that are unknown until the word in the third argument appears in the decoded text.

Example
file1:

ABCFGHIJKLMNPQRSTUVWXYZ
PDFZATMEBYOCSWINVXLJRUQ
file2:

VTK GHA EXOSKG HLKI VTK ZKCFK
Run with:

./p1 file1 file2 DOG

THE DOG JUMPED OVER THE FENCE
Notes
The word given in the third argument must appear standalone. If the third argument word appears inside another word but does not appear standalone, then the mapping is incorrect. For example, if the word is HAT, and if a mapping makes the word WHAT appear but HAT does not appear as a standalone word as well, then the mapping is incorrect.
Anything that is not A-Z counts as punctuation and should separate words.
HOW+ARE should be viewed as the words HOW and ARE.
HELLO, HOW should be viewed as the words HELLO and HOW.
All spaces, newlines, and characters must be present in the decrypted text. For example, if the text was:
VTK GHA EXOSKG, HLKI+VTK
ZKCFK.!12@ TK
then the decrypted text should be

THE DOG JUMPED, OVER+THE
FENCE.!12@ HE
After the word is found in the text, only 0 or 1 characters may still need mapping. An additional mapping must be assigned and decrypted.
There will be only 1 valid solution. Your program will not be tested against any input that can create multiple correct answers.
The alphabet in file1 does not have to be in order from A-Z
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool decodeText(string file1, string file2, string target) {
    map<char, char> cipher;
    ifstream inputFile1(file1);
    string list1, list2;

    if (inputFile1.is_open()) {
        getline(inputFile1, list1);
        getline(inputFile1, list2);
        //cout << list1 << endl << endl<< list2 << endl;
        inputFile1.close();
    }

    // Check if the first line and second line have the same length
    if (list1.length() != list2.length()) {
        cout << "Error: Mapping is not one-to-one." << endl;
        return false;
    }

    // Check if the mapping is one-to-one
    for (size_t i = 0; i < list1.length(); i++) {
        for (size_t j = i + 1; j < list2.length(); j++) {
            if (list1[i] == list1[j] || list2[i] == list2[j]) {
                cout << "Error: Mapping is not one-to-one." << endl;
                return false;
            }
        }
        cipher[list2[i]] = list1[i];
    }

    ifstream inputFile2(file2);
    string encodedText, decodedText = "";

    if (inputFile2.is_open()) {
        getline(inputFile2, encodedText, '\0');
        //cout << encodedText << endl;
        inputFile2.close();
    }

      // Check if all characters in the encoded text have a mapping
      for (size_t i = 0; i < encodedText.length(); i++) {
    char c = encodedText[i];
    if (cipher.count(c) == 0) {
        if (c == ' ') {
            decodedText += ' ';
        } else {
            cout << "Error: Character " << c << " has no mapping." << endl;
            return false;
        }
    } else {
        decodedText += cipher[c];
    }
}
    /*for (size_t i = 0; i < encodedText.length(); i++) {
        if (cipher.count(encodedText[i]) == 0 && encodedText[i] != ' ' && (encodedText[i] < 'A' || encodedText[i] > 'Z')) {
            //decodedText += (cipher.count(encodedText[i]) > 0) ? cipher[encodedText[i]] : ' ';
            decodedText += cipher[encodedText[i]];
            //cout << decodedText << "    if statement" << endl << endl;
            //return false;
        } else{
            decodedText += (cipher.count(encodedText[i]) > 0) ? cipher[encodedText[i]] : encodedText[i];
            //cout << decodedText << "      else statement" << endl << endl;
        }
    }
    */

    // Check if the target word appears in the decoded text
    //cout << "Decoded text: " << decodedText << endl;
    //cout << "Target word: " << target << endl;

    cout << "Mapping: " << endl;
    for (auto& [encoded, decoded] : cipher) {
        cout << encoded << " -> " << decoded << endl;
    }

    if (decodedText.find(target) == string::npos) {
        cout << "Error: Target word not found in decoded text." << endl;
        return false;
    }

    cout << "Decoded text: " << decodedText << endl;
    return true;
}


int main(int argc, char* argv[4]) {

   string file1 = argv[1];
   string file2 = argv[2];
   string target = argv[3];
    
    if(argc != 4){
        cout << endl << "Not enough arguments" << endl; 
        return 1;
    }

   if (!decodeText(argv[1], argv[2], argv[3])) {
  cout << "Solution could not be found." << endl;
  return -1;
  
}



return 0;

}

/*

    ifstream inDecoder;
    ifstream inCipher;

    string list1,list2,text,word;

    inDecoder.open(argv[1]);
    if (inDecoder.is_open()) {
        getline(inDecoder, list1);
    } else {
        cout << "Error: Unable to open list1" << endl;
        return 1;
    }

    if (inDecoder.is_open()) {
        getline( inDecoder,list2);
        //getline(file1, str2);
    } else {

    inCipher.open(argv[2]);

    /*if(inDecoder.fail()){
        cout << endl << "file 1 is not opening"<< endl;
    }

    if(inCipher.fail()){
        cout << endl << "file 2 is not opening" << endl;
    }

    //file.get(inCipher);
    cin >> inCipher;

    





















    inDecoder.close();
    inCipher.close();
*/