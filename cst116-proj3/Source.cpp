#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

// I stole this from the internet and I have basically no idea how it works,
// but it lets you cout to both the console and a text file at the same time,
// and all you have to do is pass everything to the Tee object instead of cout.
// Very useful since now I don't have to copy-paste the console every time I need to store my output somewhere.
class Tee
{
private:
    std::ostream& os1, & os2;
public:
    Tee(std::ostream& os1, std::ostream& os2) : os1(os1), os2(os2) {}
    template <typename T>
    Tee& operator<<(const T& thing)
    {
        os1 << thing;
        os2 << thing;

        return *this;
    }


    // function that takes a custom stream, and returns it
    typedef Tee& (*TeeManipulator)(Tee&);

    // take in a function with the custom signature
    Tee& operator<<(TeeManipulator manip)
    {
        // call the function, and return it's value
        return manip(*this);
    }

    // define the custom endl for this stream.
    // note how it matches the `TeeManipulator`
    // function signature
    static Tee& endl(Tee& stream)
    {
        // print a new line
        stream << std::endl;

        // do other stuff with the stream
        // std::cout, for example, will flush the stream
        stream << "Called Tee::endl!" << std::endl;

        return stream;
    }

    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    Tee& operator<<(StandardEndLine manip)
    {
        // call the function, but we cannot return its value
        manip(std::cout);

        return *this;
    }
};

// Here's how I'm storing each matrix.
vector<vector<int> > m1 = {
    {-57, 82, 43},
    {17, -93, 89},
    {-2, 53, 17}
};
vector<vector<int> > m2 = {
    {-23, 87, -3},
    {-5, 72, 50},
    {59, 29, -35}
};
//Used to assign product and sum
vector<vector<int>> total = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

int dotProduct(vector<int> r1, vector<int> r2);
void displayMenu();
void processMenuChoice(int menuChoice);
void printVector(vector<vector<int>> m);
vector<vector<int>> getNewMatrix();
vector<vector<int>> addMatrix(vector<vector<int>> m1, vector<vector<int>> m2);
vector<vector<int> > multiplyMatrix(vector<vector<int> > m1, vector<vector<int> > m2);

int main()
{
    // The path to the log file. The ./ makes it a relative path,
    // so it starts at the root folder of the project.
    // If you right-click on the very top file in the Solution Explorer
    // and click "Open folder in File Explorer", it should take you there.
    // IF YOU WANT TO SAVE A SECOND LOG FILE, YOU MUST CHANGE THIS FILENAME.
    // If you don't change it and run the code a second time,
    // it will destroy the first log.
    ofstream logFile("./logs/test-log.txt");
    Tee teeOut(std::cout, logFile); // Creates a new Tee named teeOut. Now all you have to do is use teeOut instead of cout (so, "cout << "Hello, world!" << endl;" becomes "teeOut << "Hello, world!" << endl;").
    cout << "Please input data for the first matrix."<< endl;
    m1 = getNewMatrix();
    cout << endl<< "Please input data for the second matrix."<< endl;
    m2 = getNewMatrix();
    cout << endl;
    int menuChoice = 0;
    while (menuChoice != 5) {
        displayMenu();
        cin >> menuChoice;
        processMenuChoice(menuChoice);
        cout << endl;
    }
    return 0;
    
    
    logFile.close(); // Closes the log file because you should always close your files. Make sure this is the very last line in main.
}
//Prints out all menu options for the user to choose from
void displayMenu() {
    cout << "What do you want to do with your matrixes?" << endl
        << "1. Enter a new matrix 1." << endl
        << "2. Enter a new matrix 2." << endl
        << "3. Add matrixes." << endl
        << "4. Multiply matrixes" << endl
        << "5. End program."<< endl;
}
//Cycles through each spot in the matrix and asks the user to assign a value to fill the 3x3 matrix.
vector<vector<int>> getNewMatrix() {
    vector<vector<int>> m3 = {};
    vector<int> row = {};
    int temp;
    for (int r = 0; r < 3; r++)
    {
        row = {};
        for (int c = 0; c < 3; c++)
        {
            cout << "What do you want to put in row " << r << " column " << c << "? ";
            cin >> temp;
            row.push_back(temp);
        }
        m3.push_back(row);
    }
    return m3;
}
//Takes the menu choice given by the user and either assigns new values for each matrix, adds the matrixes and assigns the sum to total,
//multiplies the matrixes and assigns the product to total or ends breaks the while loop in the main function to end the program.
void processMenuChoice(int menuChoice) {
    switch (menuChoice) {
    case 1:
        m1 = getNewMatrix();
        break;
    case 2:
        m2 = getNewMatrix();;
        break;
    case 3:
        total=addMatrix(m1,m2);
        cout << "Adding Matrixes:" << endl;
        printVector(total);
        break;
    case 4:
        total=multiplyMatrix(m1,m2);
        cout << "Multiplying Matrixes:" << endl;
        printVector(total);
        break;
    case 5:
        break;
    }
}
//Prints the matrix in a 3x3 format, used to nicely show products and sums.
void printVector(vector<vector<int>> m) {
    for (int r = 0; r < size(m); r++) {
        for (int c = 0; c < size(m); c++) {
            cout << m[r][c]<< ", ";
        }
        cout << endl;
    }
}
//Part of the multiplying matrixes step. Gets the row of the first matrix and the corresponding collumn of the second matrix and returns the value
//to the multiply matrix function.
int dotProduct(vector<int> r, vector<int> c)
{
    int p=0;
    for (int i = 0; i < size(r); i++)
    {
        p += r[i]* c[i];
    }
    return p;
}
//Just as the name suggests, this function adds the two matrixes together into a newly defined matrix and returns the matrix.
vector<vector<int>> addMatrix(vector<vector<int>> m1, vector<vector<int>> m2) {
    
    vector<vector<int>> m3 = {};
    vector<int> row = {};
    for (int r = 0; r < size(m1); r++)
    {
        row = {};
        for (int c = 0; c < size(m1); c++)
        {
            row.push_back(m1[r][c] + m2[r][c]);
        }
        m3.push_back(row);
    }
    return m3;
}
//The second part of the multiplyMatrix function where is seperates the matrixes into rows and columns and sends those to
//the dotproduct function for the proper algorithm and returns it here where it's put into a seperate matrix and returned.
vector<vector<int> > multiplyMatrix(vector<vector<int> > m1, vector<vector<int> > m2)
{
    vector<vector<int> > rows = { m1[0], m1[1], m1[2] };

    // To multiply the matrices you have to divide one into rows and one into columns.
    // Rows are easy since that's how the matrices are stored. Columns are...less easy.
    vector<vector<int> > columns = {
        {m2[0][0], m2[1][0], m2[2][0]},
        {m2[0][1], m2[1][1], m2[2][1]},
        {m2[0][2], m2[1][2], m2[2][2]},
    };

    vector<vector<int> > m3 = {};
    vector<int> row = {};
    for (int r = 0; r < 3; r++)
    {
        row = {};
        for (int c = 0; c < 3; c++)
        {
            row.push_back(dotProduct(rows[r], columns[c]));
        }
        m3.push_back(row);
    }
    return m3;
}