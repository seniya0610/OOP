#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class InventoryItem
{
    int itemID;
    char itemName[20];

public:
    InventoryItem(int id = 0, string name = "")
    {
        itemID = id;
        int i = 0;
        for (; i < name.length() && i < 19; i++)
        {
            itemName[i] = name[i];
        }
        itemName[i] = '\0';
    }

    void display()
    {
        cout << "Item ID: " << itemID << endl;
        cout << "Name: " << itemName << endl;
    }
};

int main()
{
    InventoryItem item1(1001, "MobilePhone");
    item1.display();

    // write to file
    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile)
    {
        cerr << "Error creating file!" << endl;
        exit(1);
    }
    outFile.write((char *)&item1, sizeof(item1));
    outFile.close();

    // read into a diff object
    ifstream infile;
    InventoryItem item2;
    infile.open("inventory.dat", ios::binary);
    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        exit(1);
    }
    infile.read((char *)&item2, sizeof(item2));
    infile.close();

    cout << "\nLoaded Item:" << endl;
    item2.display();

    return 0;
}
