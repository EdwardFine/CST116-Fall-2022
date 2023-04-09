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

const int MAX = 10;

int ReadData(ifstream& inFile, string dep[], string people[], string budget[]);
void WriteOutputFile(ofstream& outFile, string dep[], string people[], string budget[], int counter);
void PrintTotalsAndSummary(ofstream& out, int totalRecords);
int main()
{
    string dept[MAX];
    string people[MAX];
    string budget[MAX];
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
        record_counter = ReadData(inFile, dept, people, budget);
        inFile.close();

        if (outFile.is_open())
        {
            WriteOutputFile(outFile, dept, people, budget, record_counter);
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
// Reads the input file and attaches the inputs into a string.
int ReadData(ifstream& inFile, string dep[], string people[], string budget[])
{
    int counter = 0;
    inFile >> dep[counter] >> people[counter] >> budget[counter];
    while (!inFile.eof())
    {
        cout << setiosflags(ios::left) << setw(10)
            << dep[counter] << resetiosflags(ios::left)
            << setw(12) << people[counter] <<
            resetiosflags(ios::left)
            << setw(14) << budget[counter]<< endl;
        counter++;
        inFile >> dep[counter] >> people[counter] >> budget[counter];
    }
    return counter;
}
//Writes the inputs backwards into an output file.
void WriteOutputFile(ofstream& outFile, string dep[], string people[], string budget[], int counter)
{
    outFile << "   Here is the Output File" << endl;
    outFile << "Budget " << setw(15) << "# of People " << setw(15) << "Department " << endl;
    cout.precision(2);
    for (int r = 0; r <= counter; r++)
    {
        outFile << setiosflags(ios::left) << setw(4)
            << budget[r] << resetiosflags(ios::left)
            << setw(15) << people[r]
            << setw(15) << dep[r] << endl;
    }
}
//Prints total records into the output file and console at the bottom.
void PrintTotalsAndSummary(ofstream& outFile, int totalRecords)
{
    // To screen
    cout << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";

    // To file
    outFile << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";
}

