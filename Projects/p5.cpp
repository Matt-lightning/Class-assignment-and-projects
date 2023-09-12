//created by Matthew Carter
/*You are to write a program that reads three text files given as command line parameters. The first file is an inorder traversal of a Huffman code tree and the second parameter is the levelorder traversal of the same tree. The third file is the encoded text, given as ASCII 0s and 1s.

Details
Your program should:

Compute the Huffman code tree from the two traversals.
Decode the text, writing the output to standard output (cout).
The format of the inorder and levelorder traversals will be integer values separated by whitespace. The leaves of the tree will be values < 128, representing the ASCII value of the letter. The internal nodes of the tree will be values 128 and greater.

Requirements:

You must use good object-based organization, i.e. use classes in an appropriate way.
You are allowed to use any data structure in the standard library: vector, list, stack, queue, etc.
You must use g++ -Wall -std=c++11 to compile.*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class HuffmanTree{
    public:
    int index;
    vector<int> data;
    HuffmanTree* left;
    HuffmanTree* right;
    HuffmanTree(vector<int> data){
        this->data = data;
        left = NULL;
        right = NULL;
    
    }
     HuffmanTree(int data){
        this->index = data;
        left = NULL;
        right = NULL;
    }

    



    // void BuildTrees(HuffmanTree* root, vector<int> data){
    //     if(root == NULL){
    //         root = new HuffmanTree(data);
    //         return;
    //     }
    //     if(data < root->data){
    //         if(root->left == NULL){
    //             root->left = new HuffmanTree(data);
    //             return;
    //         }
    //         BuildTrees(root->left, data);
    //     }
    //     else{
    //         if(root->right == NULL){
    //             root->right = new HuffmanTree(data);
    //             return;
    //         }
    //         BuildTrees(root->right, data);
    //     }
    // }

    

    // void InorderTraversal(HuffmanTree* root){
    // cout << "Inorder Traversal: ";
    // if(root == NULL){
    //     return;
    // }
    // InorderTraversal(root->left);
    // cout << root->data << " ";
    // InorderTraversal(root->right);
//}


};

HuffmanTree* BuildTree(vector<int> levelorder, vector<int> inorder){
        HuffmanTree* root = new HuffmanTree(levelorder[0]);
        queue<HuffmanTree*> p;
        p.push(root);

        for(int i =1; i < (int)levelorder.size(); i+=2){
            HuffmanTree* leftchild = new HuffmanTree(levelorder[i]);
            HuffmanTree* rightchild = new HuffmanTree(levelorder[i+1]);
            HuffmanTree* parent = p.front();
            p.pop();
            parent->left = leftchild;
            parent->right = rightchild;
            if(levelorder[i] >= 128){
                p.push(leftchild);
            } if( levelorder[i+1] >= 128){
                p.push(rightchild);
            }

        }
        return root;

    }

    void decode(string encoded, HuffmanTree* Comp){
        HuffmanTree* temp = Comp;
        for(int i = 0; i < (int)encoded.length(); i++){
            if(encoded[i] == '0'){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
            if(temp->left == NULL && temp->right == NULL){
                cout << (char)(temp->index);
                temp = Comp;
            }
        }
        
    }

    void test(HuffmanTree* curr){
        if(curr == NULL){
            return;
        }
        test(curr->left);
        cout << curr->index << " ";
        test(curr->right);
    }


// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };





int main(int argc, char** argv){
    ifstream inorder;
    ifstream levelorder;
    ifstream encoded;

    inorder.open(argv[1]);
    levelorder.open(argv[2]);
    encoded.open(argv[3]);

    // if(!inorder.is_open() || !levelorder.is_open() || !encoded.is_open()){
    //     cout << "Error opening file" << endl;
    //     return 0;
    // }

    vector<int> inorderdata;
    vector<int> levelorderdata;
    string encodeddata;
    int temp;

    while(inorder >> temp){
        
        inorderdata.push_back(temp);
    }
    while(levelorder >> temp){
        
        levelorderdata.push_back(temp);
    }

    //cout << levelorderdata.size() << endl;

    //HuffmanTree* root = new HuffmanTree(levelorderdata);

    HuffmanTree* Comp = BuildTree(levelorderdata, inorderdata);

    //test(Comp);
    //cout << endl;
    string line;
    while(encoded >> line){
        encodeddata += line;
    }

    decode(encodeddata, Comp);



    

    // for(int i = 0; i < inorderdata.size(); i++){
    //     cout<< inorderdata.front() << endl;
    // }

    // for(int i = 0; i < levelorderdata.size(); i++){
    //     cout<< levelorderdata.front() << endl;
    // }

    
    


    //void InorderTraversal(HuffmanTree* root);




    return 0;
    
}
