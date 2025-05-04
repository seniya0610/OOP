#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    ofstream outFile("data_records.txt");
    outFile << "Record 1\n"  // 8 bytes (7 chars + \n)
            << "Record 2\n"  // 8 bytes
            << "Record 3\n"  // 8 bytes (this is our target)
            << "Record 4\n"; // 8 bytes
    outFile.close();

    // Open for reading
    ifstream inFile("data_records.txt");
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    inFile.seekg(20, ios::beg);
    cout << "Current position: " << inFile.tellg() << endl;

    string line;
    getline(inFile, line);
    cout << "Third record: " << line << endl;

    inFile.close();
}