/********************************************************************
* File: CST116-Ch10-Debugging-EdwardFine.cpp
*
* General Instructions: Complete each step before proceeding to the
* next.
*
* Debugging Exercise 1
*
* 1)	Build and run the program.
* 2)	Examine the code and the output and notice the use of
*	parallel arrays.
* 3)	Insert breakpoints at Breakpoint 1, Breakpoint 2, and Breakpoint
*	3.
* 4)	Run to Breakpoint 1.
* 5)	Place a watch on varX, varY and varZ.  Click on the '+' in the
*	watch window to see the individual elements associated with each
*	of the arrays.
* 6)	Continue running your program to Breakpoint 2.
* 7)	Add a watch on the array called name.  Again, click on the '+'
*	symbol.  Notice how a multidimensional array is shown in the
*	debugger, the null terminating characters location, and how a
*	character is represented within each element of the array.
* 0x000000e88a58fac8 "Edward", 0x000000e88a58fadc "Fine"}
* 8)	Continue running the program to Breakpoint 3.
* 9)	Notice the contents of varX and varY now that you are back in the
* 	main function.
* varX has 0 1 2 3 4 and varY has 100 101 102 103 104
* 10)	Clear all the breakpoints.
* 11)	Stop debugging.
*
* Debugging Exercise 2
*
* 1) 	Change the constant SIZE from 5 to 10.
* 2) 	Change any literal containing a 5 to the constant SIZE.
*     Notice the usefulness of the constant when changes need
*     to be made to your code.
* 3) 	Set a breakpoint at Breakpoint 4. Now on this breakpoint
*  	set the necessary condition so the loop breaks when x hits 8.
*	(Hint:  If you need help setting breakpoints based upon a
*	condition refer to Chapter 8).
* 4)  Run to Breakpoint 4.
* 5)	Continue stepping into the remainder of the for loop until the
*	flow returns back to main.
* 6) 	Make sure your Watch window is visible and notice the contents
* 	of varY and varZ now that you are back in main.
* varY has the same values and more counted from last time: 100 101 102 103 104 105 106 107 108 109, but we haven't assigned any values to varZ yet so
* there is still just 10 placeholder numbers.
* 7) 	Stop debugging.
* 8) 	Disable all breakpoints.
* 9)	Rebuild and execute the program and verify the results.
*  x       y       z

          0      100     100
          1      101     102
          2      102     104
          3      103     106
          4      104     108
          5      105     110
          6      106     112
          7      107     114
          8      108     116
          9      109     118
  Results are accurate when adding the two variables together.
*
* Debugging Exercise 3
*
* 1)	Just before the call to the PrintFunction in main, add an
*	assignment statement to change the first element in the
*	array varZ to -99.
* 2)	Build and execute your code, verifying that the calculations
*	are correct in relation to element 0 of varZ.
* 3)	Add a line to assign the contents of the second element of
*	varX to 99 in FunctionTwo.
* 4)  Rebuild your program.
* 5	Obviously there is a problem.  Remove the const from the
*     function declaration and header for varX.
* 5)	Now you should be able to build and execute your code.  Do it.
* 6)	Set a breakpoint on Breakpoint 2.
* 7)	Re-enable Breakpoint 2.
* 8)  Run to Breakpoint 2 and make sure you have a watch on the
*	variable name.
* 9)	Click on the '+'.  Once you see all the elements
*	within the array, change the 'Value' (in the Value field)
*	for the first element of the array directly within the Watch
*	window to the character 'Z'.  Notice how the value is updated
*	by displaying the new ASCII value too.
* 10)	Stop debugging.
* 11)	Disable all breakpoints.
*
********************************************************************/
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

void GetAndDisplayWelcomeInfo();
void FunctionOne(int varX[], int varY[]);
void FunctionTwo(int varX[], const int varY[], int varZ[]);
void PrintFunction(const int varX[], const int varY[],
    const int varZ[]);

const int SIZE = 10;

int main()
{
    int varX[SIZE];
    int varY[SIZE];
    int varZ[SIZE];	// Notice how we used the const here!

    // Breakpoint 1
        // Put breakpoint on the following line 
    GetAndDisplayWelcomeInfo();
    FunctionOne(varX, varY);

    // Breakpoint 3
        // Put breakpoint on the following line 
    FunctionTwo(varX, varY, varZ);
    varZ[0] = -99;
    PrintFunction(varX, varY, varZ);

    return 0;
}
void GetAndDisplayWelcomeInfo()
{
    char name[2][20]; // First name in row 0, last name in row 1

    cout << "Please enter your first name: ";
    cin >> name[0];

    cout << "\nPlease enter your last name: ";
    cin >> name[1];

    // Breakpoint 2
    // Put breakpoint on the following line 
    cout << "\n\n\tWelcome " << name[0] << " " << name[1]
        << "!\n\t   Hope all is well \n\n";
}
void FunctionOne(int varX[], int varY[])
{
    for (int x = 0; x < SIZE; x++)	// NOTICE '<' NOT <= 
        // Breakpoint 4
        // Put breakpoint on the following line 
        varX[x] = x;

    for (int x = 0; x < SIZE; x++)
        varY[x] = x + 100;
}
void FunctionTwo(int varX[], const int varY[], int varZ[])
{
    varX[1] = 99;
    for (int x = 0; x < SIZE; x++) // Notice the const SIZE here
        varZ[x] = varX[x] + varY[x];
}
void PrintFunction(const int varX[20], const int varY[20],
    const int varZ[20])
{
    int x;

    cout << " \t  x \t  y  \t  z\n\n";

    for (x = 0; x < SIZE; x++)
        cout << "\t" << setw(3) << varX[x]
        << "\t " << varY[x]
        << "\t " << varZ[x] << endl;
}
