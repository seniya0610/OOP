#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream someFile;
    someFile.open("vehicle.txt");

    if (!someFile.is_open())
    {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    int NumberOfLines = 0;

    while (getline(someFile, line))
    {
        NumberOfLines++;

        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        istringstream someObject(line);
        string type, id, name, yearStr, extraData, certification;
        int year;

        // Extract comma-separated values
        getline(someObject, type, ',');
        getline(someObject, id, ',');
        getline(someObject, name, ',');
        getline(someObject, yearStr, ',');
        year = stoi(yearStr);
        getline(someObject, extraData, ',');
        getline(someObject, certification);

        cout << "Record #" << NumberOfLines << ":\n";
        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;

        if (type == "AutonomousCar")
        {
            size_t colonpos = extraData.find(":");
            if (colonpos != string::npos)
            {
                string versionStr = extraData.substr(colonpos + 1);
                float softwareVersion = stof(versionStr);
                cout << "Software Version: " << softwareVersion << endl;
            }
        }
        else if (type == "ElectricVehicle")
        {
            size_t colonpos = extraData.find(":");
            if (colonpos != string::npos)
            {
                string capacity = extraData.substr(colonpos + 1);
                int BatteryCapacity = stoi(capacity);
                cout << "Battery Capacity: " << BatteryCapacity << endl;
            }
        }
        else if (type == "HybridTruck")
        {
            size_t colonpos = extraData.find(":");
            size_t pipepos = extraData.find("|");
            if (colonpos != string::npos && pipepos != string::npos)
            {
                string cargostr = extraData.substr(colonpos + 1, pipepos - colonpos - 1);
                int cargo = stoi(cargostr);

                size_t batterycolonpos = extraData.find(":", pipepos); //syntax imp for me
                if (batterycolonpos != string::npos)
                {
                    string batteryCapacity = extraData.substr(batterycolonpos + 1);
                    int BatteryCapacity = stoi(batteryCapacity);

                    cout << "Cargo Capacity: " << cargo << endl;
                    cout << "Battery Capacity: " << BatteryCapacity << endl;
                }
            }
        }
        else
        {
            cerr << "Error: Unknown vehicle type '" << type << "'" << endl;
        }

        cout << "Certification: " << certification << endl;
        cout << "-------------------" << endl;
    }

    someFile.close();
    cout << "Total lines processed: " << NumberOfLines << endl;
    return 0;
}
