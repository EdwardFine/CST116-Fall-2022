/********************************************************************
* File: CST116-Ch6-Debugging.cpp
*
* General Instructions: Complete each step before proceeding to the
* next.
*
* Debugging Exercise 1
*
* 1) On the lines indicated in the code below, insert a breakpoint.
* 2) Run to the breakpoint.
* 3) Put watches on both Fahrenheit and Celsius.
* 4) When asked for a temperature, enter 212.
* 5) Verify that the value you entered is stored correctly.
* 6) Step over the conversion calculation. What is the value
*    in Celsius? Is that the correct value? No.
* 
* No, the value for celcius has been put in as -32, when it should be 100
* 
* 7) Remember your order of precedence. Put parentheses around
*    Fahrenheit - 32. This needs to be done before the multiplication.
* 8) Stop debugging and recompile.
*
* Debugging Exercise 2
*
* 1) Run to Breakpoint 1.
* 2) When asked for a temperature, enter 212.
* 3) Verify that the value you entered is stored correctly.
* 4) Step over the conversion calculation. What is the value
*    in Celsius? Is that the correct value? No.
* Celsius is now being stored as 0
* 5) Look at the division. This is integer division. Therefore,
*    5 / 9 = 0. This is not the result we are looking for.
* 6) Modify the calculation so that it does floating point division.
*    There are three different ways we have discussed:
*           a) use the F suffix on the literals
*           b) type cast the literals
*           c) replace the 5 with 5.0 and the 9 with 9.0
* 7) Stop debugging, recompile and run to verify that it now works
*    correctly.
********************************************************************/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    float fahrenheit = 0;
    float celcius = 0;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    // Breakpoint 1
    // Put a breakpoint on the following line
    celcius = 5.0F / 9.0F * ( fahrenheit - 32);

    cout << fahrenheit << " degrees F = "
        << celcius << " degrees C" << endl;

    return 0;
}
