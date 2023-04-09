// FinalChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
void displayMenu();
void processMenuChoice(int choice,int& result);
void binToDec();
void decToBin();
int main()
{
    int menu = 5;
    int result = 0;
    while (menu != 3) {
        displayMenu();
        cin >> menu;
        processMenuChoice(menu,result);
    }
}
void displayMenu() {
    cout << "Do you want to:" << endl
        << "1.Convert from binary to decimal? " << endl
        << "2.Convert from decimal to binary? " << endl
        << "3.End program" << endl << endl;
}
void processMenuChoice(int choice, int& result) {
    switch (choice) {
    case 1:
        binToDec();
        break;
    case 2:
        decToBin();
        break;
    case 3:
        break;
    }
}
void binToDec()
{
    int num;
    cout << "What binary number do you want to convert? ";
    cin >> num;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    cout << "The binary number " << num << " in decimal form is " << dec_value<< endl;
}
void decToBin() {
    int decimal=1050, binary = 0, remainder, product = 1;
    while (decimal > 1023 || decimal <0) {
        cout << "What decimal Number do you want to convert? (up to 1023) ";
        cin >> decimal;
    }
    while (decimal != 0) {
        remainder = decimal % 2;
        binary = binary + (remainder * product);
        decimal = decimal / 2;
        product *= 10;
    }
    cout << "The decimal number " << decimal << " in binary form is " << binary << endl;
    }