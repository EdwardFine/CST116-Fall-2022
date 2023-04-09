// CST-Proj2-Edward-Fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace::std;
using std::cout;
using std::cin;
using std::endl;
void displayMenu();
int readInput();
int getData();
void processMenuChoice(int, int);
void isPosNeg(int);
void isOddEven(int);
void findNumDigits(int);
void findDigitAtPosition(int);
void displayAdditionTable(int);
void displayMultiplicationTable(int);
int main()
{
int menuSelection = 0;
	while (menuSelection != 7)
{
		displayMenu();
		menuSelection = readInput();
		int data = getData();
		processMenuChoice(menuSelection, data);
}
}
void displayMenu()
{
	cout << "What do you want to do with your number to test? Please enter number." << endl;
	cout << "1. Check if the number is positive or negative." << endl;
	cout << "2. Check if the number is even or odd." << endl;
	cout << "3. Find the number of digits in the number." << endl;
	cout << "4. Find the digit at a certain position." << endl;
	cout << "5. Display an addition table from 0-10. " << endl;
	cout << "6. Display a multiplication table from 0-10." << endl;
	cout << "7. End program." << endl;
	return;
}
int readInput()
{
int choice = 1;
cout << "Enter your choice: ";
cin >> choice;
return choice;
}
int getData() {
	int data = 0;
	cout << "What number do you want to test? ";
	cin >> data;
	return data;
}
void processMenuChoice(int menuChoice, int data) {
	switch (menuChoice) {
	case 1:
		isPosNeg(data);
		break;
	case 2:
		isOddEven(data);
		break;
	case 3:
		findNumDigits(data);
		break;
	case 4:
		findDigitAtPosition(data);
		break;
	case 5:
		displayAdditionTable(data);
		break;
	case 6:
		displayMultiplicationTable(data);
		break;
	case 7:
		break;
	}
}
void isPosNeg(int val1)
{
	if (val1 < 0) {
		cout<< "Your number is negative."<< endl;
	}
	else if (val1 > 0) {
		cout << "Your number is positive."<< endl;
	}
	else {
		cout << "Your number is 0, therefore not positive or negative."<< endl;
	}
	return;
}
void isOddEven(int val1)
{
// ...
}
void findNumDigits(int val1)
{
// ...
}
void findDigitAtPosition(int val1)
{
// ...
}
void displayAdditionTable(int val1) {

}void displayMultiplicationTable(int val1) {

}