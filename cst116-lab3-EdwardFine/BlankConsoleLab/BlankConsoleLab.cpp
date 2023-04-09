// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>	// For the files!!!!
#include <iomanip>	// For manipulators & formatting options
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ios;
using std::string;
using std::ifstream;
using std::ofstream;

const int MAX = 100;

int ReadData(ifstream& inFile, int pickUp[], int dropOff[], int passenger[], float
    dist[], float fare[], float toll[]);
void WriteOutputFile(ofstream& outFile, int pick[], int drop[], int
    psgr[], float dist[], float fare[], float toll[],
    int counter);
void PrintTotalsAndSummary(ofstream& out, int totalRecords);
float totalFare(float fare[], float toll[], int counter);
float cpm(float fare[], float dist[], int counter);
int main()
{
    int pickUp[MAX];
    int dropOff[MAX];
    int passenger[MAX];
    float dist[MAX];
    float fare[MAX];
    float toll[MAX];
    int record_counter(0);
    string outputLoc;
    string outputName;
    string inputLoc;
    string inputName;
    cout << "Where do you want the OUTPUT file to be saved?(C:\\.....) ";
    cin >> outputLoc;
    cout << endl << "What do you want the OUTPUT file to be called?(include .txt) ";
    cin >> outputName;
    cout << endl << "Where is your INPUT file saved?(C:\\....) ";
    cin >> inputLoc;
    cout << endl << "What is your INPUT file called?(include .txt) ";
    cin >> inputName;
    ifstream inFile;
    
    ofstream outFile(outputLoc + "\\" + outputName);

    inFile.open(inputLoc + "\\" + inputName);

    if (inFile.is_open())
    {
        record_counter = ReadData(inFile, pickUp, dropOff, passenger, dist, fare, toll);
        inFile.close();

        if (outFile.is_open())
        {
            WriteOutputFile(outFile, pickUp, dropOff, passenger, dist, fare, toll, record_counter);
            PrintTotalsAndSummary(outFile, record_counter);
            outFile.close();
        }
        else
        {
            cout << "Trouble Opening Output File";
            cout << "\n\n\t\t ** About to EXIT NOW! ** ";
        }
    }
    else
    {
        cout << "Trouble Opening Input File";
        cout << "\n\n\t\t ** About to EXIT NOW! ** ";
    }
    return 0;
}
int ReadData(ifstream& inFile, int pick[], int drop[], int psgr[], float
    dist[], float fare[], float toll[])
{
    int counter = 0;
    inFile >> pick[counter] >> drop[counter] >> psgr[counter] >>
        dist[counter] >> fare[counter] >> toll[counter]; // Priming Read
    while (!inFile.eof())
    {
        cout << setiosflags(ios::left) << setw(5)
            << pick[counter] << resetiosflags(ios::left)
            << setw(10) << drop[counter] <<
            resetiosflags(ios::left)
            << setw(12) << psgr[counter] <<
            resetiosflags(ios::left)
            << setw(14) <<
            dist[counter] << resetiosflags(ios::left)
            << setw(14) << fare[counter] <<
            resetiosflags(ios::left)
            << setw(14) << toll[counter]
            << endl;
        counter++;
        inFile >> pick[counter] >> drop[counter] >> psgr[counter]
            >> dist[counter] >> fare[counter] >> toll[counter];
    }
    return counter;
}
void WriteOutputFile(ofstream& outFile, int pickUp[], int dropOff[], int passenger[], float
    dist[], float fare[], float toll[], int counter)
{
    outFile << "   Here is the Output File" << endl;
    outFile << "Pickup " << setw(15) << "Dropoff " << setw(15) << "Passengers " << setw(15) << "Distance " << setw(15) << "Fare " << setw(15) << "Toll " << setw(15) <<
        "Total Fare " << setw(15) << "Cost per Mile "<< endl;
    cout.precision(2);
    for (int r = 0; r <= counter; r++)
    {
        outFile << setiosflags(ios::left) << setw(4)
            << pickUp[r] << resetiosflags(ios::left)
            << setw(15) << dropOff[r] 
            << setw(15) << passenger[r] 
            << setw(15) << dist[r]
            << setw(15) << fare[r]
            << setw(15) << toll[r] << setw(15)
            << totalFare(fare, toll, r)<< setw(15) <<
            cpm(fare, dist, r)<<
            endl;
    }
}
float totalFare(float fare[], float toll[], int counter) {
    float total = fare[counter] + toll[counter];
    return total;
}
float cpm(float fare[], float dist[], int counter) {
    float cpm;
    if (dist[counter] == 0) {
        cpm = 0;
    }
    else {
        cpm = fare[counter] / dist[counter];
    }
    return cpm;
}
void PrintTotalsAndSummary(ofstream& outFile, int totalRecords)
{
    // To screen
    cout << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";

    // To file
    outFile << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";
}

