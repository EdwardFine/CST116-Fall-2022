// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float GetArea(float length, float width);
float getMass(float area);
float getGrav(float mass);
const int gravConst = 6674300;
const int earthMass = 59720000;
const int massMeter = 135;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    float length=0;
    float width=0;
    int correct = 0;
    float area;
    float gravPull;
    float aspectRatio;
    int goodRatio = 0;
    float mass;
    while (goodRatio == 0) {
        while (correct == 0) {
            cout << "Please provide dimensions for your kite between 1 and 400 centimeters." << endl;
            cout << "How long is your kite in centimeters? ";
            cin >> length;
            cout << endl << "How wide is your kite in centimeters? ";
            cin >> width;
            cout << endl << "Your kite is " << length << "cm long and " << width << " cm wide? 1=Yes/ 0=No ";
            cin >> correct;
            if (width < 1 || width >400) {
                cout << "Your width isn't a proper size, please reenter a width between 1 and 400 cm." << endl;
                correct = 0;
            }if (length < 1 || length >400) {
                cout << "Your length isn't a proper size, please reenter a width between 1 and 400 cm." << endl;
                correct = 0;
            }
            cout << endl;
        }
        cout << "Calculating area in square meters..." << endl;
        area = GetArea(length, width);
        cout << "Your Kite's area is " << area << " meters squared." << endl;
        aspectRatio = (width / length);
        if (aspectRatio >= 1) {
            cout << "*Warning* You have a low aspect ratio of " << aspectRatio<< ". A lower aspect ratio would provide better stability for your kite, try haing a smaller width." << endl<<endl;
            correct = 0;
        }
        else {
            goodRatio = 1;
            cout << "You have a good aspect ratio of " << aspectRatio << endl;
        }
    }
    mass = getMass(area);
    cout << "You kite has a mass of " << mass << " kilograms." << endl;
    gravPull = getGrav(mass);
    cout << "Your kite has a gravitational pull to the Earth of " << gravPull << "N at 200 m in the sky." << endl;
}
float GetArea(float length, float width) {
    float area = 0;
    area = (length * width) / 2.0;
    area = area / 10000;
    return area;
}
float getMass(float area) {
    float mass = 0;
    mass = area * massMeter;
    mass = mass / 1000;
    return mass;
}float getGrav(float mass) {
    float gravPull = 0;
    gravPull = gravConst * ((mass * earthMass) / 200);
    return gravPull;
}


