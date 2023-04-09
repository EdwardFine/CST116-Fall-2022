// Midterm2-CST116-Edward-Fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
float sum (float one, float two);
float diff(float one, float two);
float pro(float one, float two);
void clearCin();

//Asks the user to input 2 ints and 2 floats and finds the sum, difference and product of them.
int main()
{
    cout << std::fixed;
    cout.precision(2);
    //Lots of variables, 2 for inputs, 3 for calculations to prevent decimals from showing up for ints.
    int first, second, intsum, intdiff, intpro;
    float third, fourth;
    int repeat = 1;
    while (repeat == 1) {
        cout << "Enter your first integer ";
        cin >> first;
        clearCin();
        cout << "Enter your second integer ";
        cin >> second;
        clearCin();
        cout << "Enter your first float ";
        cin >> third;
        cout << "Enter your second float ";
        cin >> fourth;
        //Having intsum and the others make sure that the ints won't be given 2 decimals since the functions are floats.
        intsum = sum(first, second);
        intdiff = diff(first, second);
        intpro = pro(first, second);
        cout << setw(15) << "Sum" << setw(15) << "Difference" << setw(15) << "Product" << endl;
        cout << "Int" << setw(12) << intsum << setw(15) << intdiff << setw(15) << intpro << endl;
        cout << "Float" << setw(10) << sum(third, fourth) << setw(15) << diff(third, fourth) << setw(15) << pro(third, fourth) << endl;
        cout << "Would you like to go again? 1=Yes, 0=No ";
        cin >> repeat;
    }

}
//All functions are using float because you can put an int into a float but not a float into an int.
//This takes two numbers and adds them together and returns the sum.
float sum(float one, float two) {
    float sum = one + two;
    return sum;

}
//This takes two numbers and find the difference between the first and the second and returns it.. (first-second)
float diff(float one, float two) {
    float diff = one - two;
    return diff;

}
//This takes two numbers and find the product and returns it.
float pro(float one, float two) {
    float pro = one * two;
    return pro;
}
// This function prevents an infinate loop if a float is inputted into an int and drops the decminal for it.
void clearCin() {
    cin.clear();
    cin.ignore(100, '\n');
}
/*PseudoCode:
* Ask the user to input 2 intergers and 2 float values.
* find the sum, difference, and product of the ints with each other and the floats with each other.
* Print out sum, difference and product in neat vertical columns.
* Ask the user if they want to input more numbers, if yes then repeat code, if no then end code.
*/
/*Test run with correct inputs:
Enter your first integer 10
Enter your second integer 5
Enter your first float 23.6
Enter your second float 15.2
            Sum     Difference        Product
Int          15              5             50
Float     38.80           8.40         358.72
Would you like to go again? 1=Yes, 0=No 0
*/
/*Test run with wrong inputs:
Enter your first integer 5.6
Enter your second integer 4.3
Enter your first float 6
Enter your second float 3
            Sum     Difference        Product
Int           9              1             20
Float      9.00           3.00          18.00
Would you like to go again? 1=Yes, 0=No 0
*/