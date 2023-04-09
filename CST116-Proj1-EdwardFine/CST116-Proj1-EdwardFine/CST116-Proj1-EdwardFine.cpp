//CST116, Project 1 Final, No Errors, Edward Fine & Lloyd Crawford. Recieved 10/19/2022

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using namespace std;
int age;
float income = 0.00;
float gpa = 0.00;
string name;

int main()
{
    //Part 1
    int w = 0;
    cout << fixed;
    cout.precision(2);
    for (int i = 0; i < 4; i++)
    {
        cout << "Give me a name: ";
        cin >> name;
        cout << endl;
        cout << "Hourly Income : ";
        cin >> income;
        cout << endl;
        cout << "Please input GPA: ";
        cin >> gpa;
        cout << endl;

        cout << setw(20) << "Name: " << setw(20) << "Income: "
            << setw(20) << "GPA: " << endl;
        cout << setw(20) << name << setw(20) << income
            << setw(20) << gpa << endl;
    }

    // Part 2
    while (w < 4) {
        cout << "Give me a name:";
        cin >> name;

        cout << "Hourly income: ";
        cin >> income;

        cout << "What's their age: ";
        cin >> age;

        cout.width(20);
        cout << "Name is: ";
        cout.width(20);
        cout << "Income is: ";
        cout.width(20);
        cout << "Age is " << endl;
        cout.width(20);
        cout << name;
        cout.width(20);
        cout << income;
        cout.width(20);
        cout << age << endl;

        w++;
    }
    
}
