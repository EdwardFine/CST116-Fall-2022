// MidtermDebug-CST116-Edward-Fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using namespace::std;

char swapval1(char val1, char val2);
char swapval2(char val1, char val2);
string reverseStr(string str);

int main()
{
    string str = "Simple string to test reverse.";
    str= reverseStr(str);
    cout << str;
    return 0;
}char swapval1(char val1, char val2) {
    char temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
    return val1;
}char swapval2(char val1, char val2) {
    char temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
    return val2;
}
string reverseStr(string str) {
    int n = str.length();
    char last;
    for (int i = 0; i <= (n/2); i++) {
        last = swapval2(str[i], str[n - i]);
    str[i]=swapval1(str[i], str[n - i]);
    str[n - i] = last;
    }
    return str;
}
/*Output: 
* .esrever tset ot gnirts elpmiS
*/
