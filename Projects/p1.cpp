#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int TempText(string temp, char *text)
{
    unsigned int x = 0;
    for (unsigned int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == text[i])
            x++;
        else if (temp[i] == '?')
            x++;
    }
    if (x == strlen(text))
        return 1;
    else
        return 0;
}

void decode(string &list1, string &list2, char *text, string tempword, string tempstring)
{
    for (unsigned int i = 0; i < tempword.size(); i++)
    {
        if (tempstring[i] == '?')
        {
            if (list2.find(tempword[i]) == string::npos)
            {
                list1 += text[i];
                list2 += tempword[i];
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    string list1, list2, str, tempword, tempstring;
    char text[50];
    ifstream myfile1(argv[1]);
    getline(myfile1, list1);
    getline(myfile1, list2);

    ifstream myfile2(argv[2]);
    getline(myfile2, str);

    strcpy(text, argv[3]);

    myfile1.close();
    myfile2.close();

    if (list1.at(list1.size() - 1) == '\r')
        list1.erase(list1.size() - 1);

    if (list2.at(list2.size() - 1) == '\r')
        list2.erase(list2.size() - 1);

    if (str.at(str.size() - 1) == '\r')
        str.erase(str.size() - 1);

    unsigned int x = str.size();
    int v, j = 0;
    int u = strlen(text);

    for (unsigned int i = 0; i < x; i++)
    {
        if (isalpha(str[i]))
        {
            j++;
            if (list2.find(str[i]) != string::npos)
            {
                tempstring.push_back(list1[list2.find(str[i])]);
                tempword.push_back(list1[list2.find(str[i])]);
            }
            else
            {
                tempstring.push_back('?');
                tempword.push_back(str[i]);
            }
        }
        else
        {
            v = tempword.size();
            if (v == u)
            {
                if (TempText(tempstring, text) == 1)
                {
                    decode(list1, list2, text, tempword, tempstring);
                    break;
                }
                else
                {
                    tempword.clear();
                    tempstring.clear();
                    j = 0;
                }
            }
            else
            {
                tempword.clear();
                tempstring.clear();
                j = 0;
            }
        }
    }

    char unknownChar1, unknownChar2;
    for (unsigned int a = 0; a < 25; a++)
    {
        for (unsigned int b = 0; b < list1.size(); b++)
        {
            if (list2[a] == list1[b])
                break;
            else if (b == list1.size() - 1)
                unknownChar1 = list2[a];
        }
    }
    list1 += unknownChar1;

    for (unsigned int c = 0; c < 25; c++)
    {
        for (unsigned int d = 0; d < list2.size(); d++)
        {
            if (list1[c] == list2[d])
                break;
            else if (d == list2.size() - 1)
                unknownChar2 = list1[c];
        }
    }
    list2 += unknownChar2;

    for (unsigned int i = 0; i < x; i++)
    {
        if (isalpha(str[i]))
        {
            j++;
            if (list2.find(str[i]) != string::npos)
            {
                cout << list1[list2.find(str[i])];
            }
            else
            {
                cout << str[i];
            }
        }
        else
        {
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}