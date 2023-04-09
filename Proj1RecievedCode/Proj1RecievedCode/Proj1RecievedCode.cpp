#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using namespace std;


int main()
{
    int sum=0, number=0;

    do {
        sum += number;

        // take input from the user 
        cout << "Enter a number: ";
        cin >> number;
    } while (number >= 0);

}