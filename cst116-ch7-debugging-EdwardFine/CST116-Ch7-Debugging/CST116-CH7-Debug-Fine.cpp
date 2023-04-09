/********************************************************************
* File: CST116-Ch7-Debugging.cpp
*
* General Instructions: Complete each step before proceeding to the
* next.
*
* Debugging Exercise 1
*
* 1) Insert a breakpoint on the lines indicated in the code.
* 2) Run to Breakpoint 1.
* 3) When prompted, enter your age.
* 4) When the execution stops, add a watch on age and verify that
*    the value in age is what you typed in.
* 5) Step over the if statement.
* 6) Why did the value in age change?
* The value in age changed because the if statement should be checking if
* age is 1 with age==1, however the program only has one = sign so the program
* assigns age the value of 1.
* 7) Fix the problem and repeat Steps 2 – 5 to verify the
*    problem was corrected.
* 8) Stop debugging.
*
* Debugging Exercise 2
*
* 1) Run to Breakpoint 1.
* 2) When prompted, enter the value 25 for your age.
* 3) Step over the if statement. Execution of the program should
*    continue on the else if statement.
* 4) Verify that 25 is still stored in age.
* 5) Step over the else if.
* 6) Why is the program going to print "Teenager" for an age of 25?
* The program is going to print Teenager because the program goes in order 
* and the first check it does is if the number is equal to 1 and after that it checks
* if the number is more than 12 or less than 19. I believe the intention is 
* to check if the age is greater than 12 and less than 19, but since 25 is 
* greater than 12, it passes the elseif gate. Changing the || gate to an && 
* gate should fix the problem.
* 7) Fix the problem and repeat Steps 1 – 5 to verify the
*    problem was corrected.
* 8) Stop debugging.
* 9) Remove Breakpoint1.
*
* Debugging Exercise 3
*
* 1) Run the program without debugging.
* 2) When prompted, enter the value of 10 for your age.
* 3) Why does the program print both "Child" and "Adult"?
* 4) Re-run the program this time with debugging and run to
*    Breakpoint 2.
* 5) Why is the action with the else executing?
* The else is being skipped over because there is a semicolon that shows the 
* end of the action. Then the program moves to the next line which is to print 
* adult, even if something was printed before.
* 6) Fix the problem and re-run to verify the problem was corrected.
********************************************************************/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int age = 0;

    cout << "Enter your age: ";
    cin >> age;

    // Breakpoint 1
    // Put a breakpoint on the following line
    if (age == 1)
        cout << "First Birthday" << endl;
    else if (age >= 12 && age <= 19)
        cout << "Teenager" << endl;
    else if (age < 12)
        cout << "Child" << endl;
    else if (age > 62)
        cout << "Senior" << endl;
    // Breakpoint 2
    // Put a breakpoint on the following line
    else
    cout << "Adult" << endl;

    return 0;
}