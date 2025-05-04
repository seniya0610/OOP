#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("large_log.txt");
    if (!outfile)
    {
        cerr << "error opening file" << endl;
    }
    outfile << "This is the first part of the Log" << endl;
    outfile << "This is the second part of the Log" << endl;
    outfile << "And the third" << endl;
    outfile.close();

    ifstream infile;
    infile.open("large_log.txt");
    if (!infile)
    {
        cerr << "error" << endl;
    }
    char buffer[11];
    infile.read(buffer, 10);
    cout << "First 10 chars: " << buffer << endl;
    cout << "Current position: " << infile.tellg() << endl
         << endl;

    string line;
    getline(infile, line); // Reads rest of current line
    cout << "Next line: " << line << endl;
    cout << "Position after getline: " << infile.tellg() << endl
         << endl;

    infile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 chars: " << buffer << endl;
    cout << "Final position: " << infile.tellg() << endl;

    infile.close();
}