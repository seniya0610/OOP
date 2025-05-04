#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ofstream outfile;
    outfile.open("sensor_log.txt", ios::out);
    if (!outfile){
        cerr << "Error" << endl;
    }
    streampos pos = outfile.tellp();
    //cout << "start position: " << pos << endl;

    outfile << "Sensor 1: 25.5C\n";
    pos = outfile.tellp();
    //cout << "After first write: " << pos << endl;

    outfile << "Sensor 2: 98. 1 %RH\n" << endl;
    pos = outfile.tellp();
    //cout << "After second write: " << pos << endl;
}