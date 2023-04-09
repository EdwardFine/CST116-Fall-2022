// Midterm-CST116-Edward-Fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin; 
const int MAX_INPUTS = 10;//Easy way to change amount of inputs for the whole program without rewritting everything.
using namespace std;// to use setw
void writeOutputs(int num[], char name[], float gpa[], int inputs);//Sets up the function that's built upon later.
void resetCin();
int main()
{
	cout << std::fixed;
	cout.precision(2);//allows gpa to always be printed with 2 points after decimal.
	float gpa[MAX_INPUTS];
	char name[MAX_INPUTS];
	int num[MAX_INPUTS];
	int cancel = 1;
	int inputs;

	//This for loop will get all of the inputs and assign them to the correct arrays until the user breaks it or 
	//reaches the maximum number of inputs.
	for (int i = 0; i < MAX_INPUTS;i++) {
		inputs = i;
		cout << "What is your class number? ";
		cin >> num[i];
		resetCin();
		cout << "What is the first letter of your last name? ";
		cin >> name[i];
		resetCin();
		cout << "What is your GPA? ";
		cin >> gpa[i];
		resetCin();
		if (i != MAX_INPUTS -1) {
			//I found that if you entered a string into an int, it zeros it out so you can enter any letter, or 0 to get through the if statement.
			cout << "Do you want to end? Enter Done or 0. Otherwise input any other number ";
			cin >> cancel;
			if (cancel == 0) {
				break;
			}
		}
	}
	writeOutputs(num, name, gpa, inputs);
  }
// The way I have it set up, you could throw this function anywhere in the program, even in the for loop after the inputs value gets applied
// and the program will output what has been inputted, even if it's below the max input values.
void writeOutputs(int num[], char name[], float gpa[], int inputs) {
	cout << setw(15) << "Class number" << setw(15) << "Last Name" << setw(15) << "GPA" << endl;
	for (int j = 0; j <= inputs; j++) {
		cout << setw(15) << num[j] << setw(15) << name[j] << setw(15) << gpa[j] << endl;
	}
};
//This function prevents an infinite loop if a char is applied to one of the int strings.
void resetCin() {
	cin.clear();
cin.ignore(100, '\n');
}
/*PseudoCode:
* Prompt the user and ask them to input their class number and store this number into the 0th position of the array num.
* Prompt the user and ask them to input the first letter of their last name  and store this character into the 0th position of the array name.
* Prompt the user and ask them to input their gpa and store this number into the 0th position of the array gpa.
* Once all three values have been submitted, ask the user if they want to add more or end the program.
* If the user wishes to end the program, have them enter 0 or done.
* Otherwise, go through the three variables again and apply the inputs to the array+1 of last position.
* Once the user ends manually or gets to the max inputs, output the inputs in a neat vertical chart with headers.
*/
/*Command prompt output for 10 inputs:
* What is your class number? 123
What is the first letter of your last name? A
What is your GPA? 2
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 456
What is the first letter of your last name? B
What is your GPA? 4
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 789
What is the first letter of your last name? C
What is your GPA? 3.75
Do you want to end? Enter Done or 0. Otherwise input any other number 4
What is your class number? 963
What is the first letter of your last name? D
What is your GPA? 3.2
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 852
What is the first letter of your last name? E
What is your GPA? 3.6532569
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 741
What is the first letter of your last name? F
What is your GPA? 2.85
Do you want to end? Enter Done or 0. Otherwise input any other number 2
What is your class number? 159
What is the first letter of your last name? G
What is your GPA? 3.65
Do you want to end? Enter Done or 0. Otherwise input any other number 2
What is your class number? 951
What is the first letter of your last name? H
What is your GPA? 4
Do you want to end? Enter Done or 0. Otherwise input any other number 3
What is your class number? 753
What is the first letter of your last name? I
What is your GPA? 1.85
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 357
What is the first letter of your last name? J
What is your GPA? .5
   Class number      Last Name            GPA
            123              A           2.00
            456              B           4.00
            789              C           3.75
            963              D           3.20
            852              E           3.65
            741              F           2.85
            159              G           3.65
            951              H           4.00
            753              I           1.85
            357              J           0.50
*/
/*Output for <10 inputs:What is your class number? 123
What is the first letter of your last name? A
What is your GPA? 4
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 456
What is the first letter of your last name? B
What is your GPA? 3.56
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 789
What is the first letter of your last name? C
What is your GPA? 2.85
Do you want to end? Enter Done or 0. Otherwise input any other number 0
   Class number      Last Name            GPA
            123              A           4.00
            456              B           3.56
            789              C           2.85
*/
/*Incorrect data for each types of data in data set:
* What is your class number? Test
What is the first letter of your last name? 56
What is your GPA? Wrong
Do you want to end? Enter Done or 0. Otherwise input any other number 1
What is your class number? 123
What is the first letter of your last name? B
What is your GPA? 4
Do you want to end? Enter Done or 0. Otherwise input any other number 0
   Class number      Last Name            GPA
              0              5           0.00
            123              B           4.00

So for the class number and GPA, those get values of 0 if an input is wrong and the char just gets the number.
*/