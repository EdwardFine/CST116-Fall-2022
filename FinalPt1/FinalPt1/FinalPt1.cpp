// FinalPt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
char* addCharSlashes(char* inCharArray);
string addStringSlashes(string inString);
char* removeCharSlashes(char* inCharArray);
string removeStringSlashes(string inString);
const int MAX_LENGTH = 70;
int main()
{
    char array[]="";
    char passThrough;
    string inString;
    cout << "Please input the test phrase for char array.(max 50 characters) ";
    cin >> array;
    cout << addCharSlashes(array)<< endl;
    cout << removeCharSlashes(array);
    return 0;
}
//Adds // when there's a ch.
char* addCharSlashes(char* inCharArray) {
    char temp1 = 'a';
    char temp2 = 'a';
    int n = sizeof(inCharArray);
    char newarray[] = "";
    for (int i = 0; i < n; i++) {
        temp1 = inCharArray[i];
        if (temp1 == 'c' || temp1 == 'C') {
            temp2 = inCharArray[i + 1];
            if (temp2 == 'h' || temp2 == 'H') {
                for (int j = n; j >-2; j--,n--) {
                    inCharArray[j+2] = inCharArray[n];
                }
                inCharArray[i] = ' ';
                inCharArray[i + 1] = ' ';
                inCharArray[i+2] = '/';
                inCharArray[i + 3] = '/';
                n = sizeof(inCharArray);
                for (int x = i + 2; x < n + 2; i++, x++) {
                    inCharArray[i] = inCharArray[x];
                }
            }
        }

        
    }
    return inCharArray;
}
//Adds // when there's a ch
string addStringSlashes(string inString) {
    return "a";
}
//removes //
char* removeCharSlashes(char* inCharArray) {
    char temp1 = 'a';
    char temp2 = 'a';
    int n = sizeof(inCharArray);
    char newarray[] = "";
    for (int i = 0; i < n; i++) {
        temp1 = inCharArray[i];
        if (temp1 == '/') {
            temp2 = inCharArray[i + 1];
            if (temp2 == '/') {
                for (int j = i+2; j<n+2; i++, j++) {
                    inCharArray[i] = inCharArray[j];
                }
            }
        }
    }
    return inCharArray;
}
//removes //
string removeStringSlashes(string inString) {
    return "a";
}

