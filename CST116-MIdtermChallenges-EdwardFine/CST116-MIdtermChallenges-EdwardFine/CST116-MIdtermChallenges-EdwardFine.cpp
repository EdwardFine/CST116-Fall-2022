// CST116-MIdtermChallenges-EdwardFine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int TOTAL_SCORES = 5;
void checkGrade(int average);

int main()
{
    int testScores[TOTAL_SCORES] = { 0 };
    int average;
    int loop = 1;
    while (loop == 1) {
        average = 0;
        cout << "Please input 5 tests scores : " << endl;
        for (int i = 0; i < TOTAL_SCORES; i++) {
            cin >> testScores[i];
            average += testScores[i];
        }
        average = average / TOTAL_SCORES;
        checkGrade(average);
        cout << endl << "Do you have anymore test scores to input? 1=Yes/0=No ....";
        cin >> loop;
    }
    cout << "Thank you for using the grade averager 3000, enjoy your day!" << endl;

}
void checkGrade(int average) {
    if (average >= 90) {
        cout << "Congratulations, you have an average score of " << average << "! You have a letter grade of A!"<< endl;
    }
    else if (average >= 80) {
        cout << "Exceptional, you have an average score of " << average << "! You have a letter grade of B!" << endl;
    }
    else if (average >= 70) {
        cout << "Stellar work, you have an average score of " << average << "! You have a letter grade of C!" << endl;
    }
    else if (average >= 60) {
        cout << "Great job, you have an average score of " << average << ". You have a letter grade of D." << endl;
    }
    else {
        cout << "Unfortunately, you have an average score of " << average << ". You have a letter grade of F." << endl;
    }
}
