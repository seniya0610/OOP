#include <iostream>
#include <string>
using namespace std;

struct Product {
    string ID;
    string Name;
    int quantity;
    float price;
};

Product* AddProduct(Product* products, int& count, Product newProduct) {
    Product* newProducts = new Product[count + 1];
    for (int i = 0; i < count; i++) {
        newProducts[i] = products[i];
    }
    newProducts[count] = newProduct;
    count++;
    delete[] products;
    return newProducts;
}

Product* RemoveProduct(Product* products, int& count, string productID) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (products[i].ID == productID) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Product not found. No changes made." << endl;
        return products;
    }
    Product* newProducts = new Product[count - 1];
    int newIndex = 0;
    for (int i = 0; i < count; i++) {
        if (i != index) {
            newProducts[newIndex] = products[i];
            newIndex++;
        }
    }
    count--;
    delete[] products;
    return newProducts;
}

void UpdateProduct(Product* products, int count, string productID) {
    for (int i = 0; i < count; i++) {
        if (products[i].ID == productID) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, products[i].Name);
            cout << "Enter new quantity: ";
            cin >> products[i].quantity;
            cout << "Enter new price: ";
            cin >> products[i].price;
            cout << "Product updated successfully.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void DisplayProducts(Product* products, int count) {
    if (count == 0) {
        cout << "No products in inventory.\n";
        return;
    }
    cout << "\nProduct List:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << products[i].ID << ", ";
        cout << "Name: " << products[i].Name << ", ";
        cout << "Quantity: " << products[i].quantity << ", ";
        cout << "Price: $" << products[i].price << "\n";
    }
}

float CalculateInventoryValue(Product* products, int count) {
    float totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += products[i].price * products[i].quantity;
    }
    return totalValue;
}

int main() {
    int count = 5;
    Product* inventory = new Product[count]{
        {"P001", "Laptop", 10, 750.5},
        {"P002", "Mouse", 50, 25.3},
        {"P003", "Keyboard", 30, 45.7},
        {"P004", "Monitor", 20, 150.0},
        {"P005", "Printer", 15, 200.9}
    };

    int choice;
    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Product\n";
        cout << "4. Display Products\n";
        cout << "5. Calculate Total Inventory Value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Product newProduct;
                cout << "Enter Product ID: ";
                cin >> newProduct.ID;
                cin.ignore();
                cout << "Enter Product Name: ";
                getline(cin, newProduct.Name);
                cout << "Enter Quantity: ";
                cin >> newProduct.quantity;
                cout << "Enter Price: ";
                cin >> newProduct.price;
                inventory = AddProduct(inventory, count, newProduct);
                cout << "Product added successfully!\n";
                break;
            }
            case 2: {
                string removeID;
                cout << "Enter Product ID to remove: ";
                cin >> removeID;
                inventory = RemoveProduct(inventory, count, removeID);
                break;
            }
            case 3: {
                string updateID;
                cout << "Enter Product ID to update: ";
                cin >> updateID;
                UpdateProduct(inventory, count, updateID);
                break;
            }
            case 4: {
                DisplayProducts(inventory, count);
                break;
            }
            case 5: {
                float totalValue = CalculateInventoryValue(inventory, count);
                cout << "Total Inventory Value: $" << totalValue << endl;
                break;
            }
            case 6: {
                cout << "Exiting program...\n";
                delete[] inventory;
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
