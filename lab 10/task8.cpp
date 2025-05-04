#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    ofstream outFile;
    outFile.open("config.txt", ios::out);
    outFile << "AAAAA" << "BBBBB" << "CCCCC";
    cout << "Original: "<<"AAAAABBBBBCCCCC" << endl;
    outFile.close();

    fstream file;
    file.open("config.txt", ios::out | ios::in);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    file.seekp(5);                                              // moves cursor to this position
    cout << "Current write position: " << file.tellp() << endl; // tells position

    file << "XXXXX";
    cout << "Block updated.\n";
    file.close();

    ifstream infile;
    string content;
    infile.open("config.txt", ios::in);
    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    getline(infile, content); // reads entire file
    cout << "content: " << content << endl;
    infile.close();

    // can altho its redundant
    //  ifstream infile;
    //  string line;
    //  while (getline(infile, line))
    //  {
    //      if (line.empty() || line[0] == '#')
    //      {
    //          continue;
    //      }
    //      string data;
    //      istringstream obj(line);
    //      getline(obj, data);
    //  }
}