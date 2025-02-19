#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;

public:
    Product()
    {
        id = 0;
        name = " ";
        price = 0.00;
    }

    Product(int ID, string n, double p)
    {
        id = ID;
        name = n;
        price = p;
    }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
};

class Inventory
{
private:
    string name;
    Product *list;
    int count;
    int max = 100;

public:
    Inventory(string s)
    {
        name = s;
        count = 0;
        list = new Product[max];
    }

    void add(Product &p)
    {
        if (count < max)
        {
            list[count] = p;
            count++;
        }
        else
        {
            cout << "inventory cannot hold more objects" << endl;
        }
    }

    void sortbyprice()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (list[i].getPrice() < list[j].getPrice())
                {
                    Product temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }

    void searchbyname(string n)
    {
        bool found;
        for (int i = 0; i < max; i++)
        {
            if (list[i].getName() == n)
            {
                cout << "Product found: ";
                list[i].display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Product not found." << endl;
        }
    }

    void display()
    {
        cout << "Inventory: " << name << endl;
        for (int i = 0; i < count; i++)
        {
            list[i].display();
        }
    }
    
    ~Inventory()
    {
        delete[] list;
    }
};

int main()
{
    Inventory inv1("Department Store Inventory");

    Product p1(1, "Laptop", 1200.50);
    Product p2(2, "Smartphone", 800.75);
    Product p3(3, "Tablet", 500.25);
    Product p4(4, "Headphones", 150.00);
    Product p5(5, "Mouse", 25.99);

    inv1.add(p1);
    inv1.add(p4);
    inv1.add(p2);
    inv1.add(p3);
    inv1.add(p5);

    //sorting
    cout << "Initial Inventory:" << endl;
    inv1.display();
    inv1.sortbyprice();
    cout << "\nInventory sorted by price:" << endl;
    inv1.display();

    //searching
    cout << "\nSearching for product 'Tablet':" << endl;
    inv1.searchbyname("Tablet");
    cout << "\nSearching for product 'Monitor':" << endl;
    inv1.searchbyname("Monitor");    

}
