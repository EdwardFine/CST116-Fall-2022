// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tgmath.h>

using namespace std;

using std::cout;
using std::cin;
using std::endl;
void convertToF(int *c);
float getChill(int speed, int chill);

int main()
{
    char temp = 'f';
    int degree=122;
    int windSpeed = 232;
    float windChill;
    cout << "Are you inputting temperature in celcius or fahrenheit? Type C/f? ";
    cin >> temp;
    if (temp == 'c' || temp == 'C') {
        while (degree < -62 || degree > 49.5) {
            cout << "What is your temperature in celcius from -62 to 49.5 degrees? ";
            cin >> degree;
        }
        convertToF(&degree);
    }
    else if (temp == 'f' || temp == 'F') {
        while (degree < -80 || degree > 121) {
            cout << "What is your temperature in fahrenheit from -80 to 121 degrees? ";
            cin >> degree;
        }
    }
    while (windSpeed < 0 || windSpeed > 231) {
        cout << "Please input the wind speed in MPH: ";
        cin >> windSpeed;
    }
    windChill = getChill(degree, windSpeed);
    cout << "The windchill for " << degree << " degrees Fahrenheit and " << windSpeed << " mph winds is " << windChill;
    
 
}
//this convertToF function serves to convert any celcius input to Fahrenheit by taking the input of the degree given and 
//performing an algebraic function to convert it. It returns no value because it overwrites the original variable's value.
void convertToF(int *c) {
    cout << "Converting Celcius to Farhrenheit..."<< endl;
    *c = 9 / 5 * *c + 32;
    return;
}
//This getChill function serves to calculate the windchill. I had seperated them all out into segments because I was having
//trouble calulating it right and though it was an order of operations issue, but it was a float issue. This has the inputs of
//the degree temp taken from the user and the wind speed given from the user and returns the calculated value.
float getChill(int temp, int speed) {
    cout << "Calculating windchill..."<< endl;
    float tempSpeed = pow(speed, .16);
    float temp1 = 35.74 + (.6215 * temp);
    float temp2 = 35.75 * tempSpeed;
    float temp3 = .4275 * temp * tempSpeed;
    float chill = temp1 - temp2 + temp3;
    return chill;
}

