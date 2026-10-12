
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

int main() {
    map<int, Product> inventory;
    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Calculate Total Inventory Value\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            Product p;

            cout << "Enter Product ID: ";
            cin >> id;

            if (inventory.count(id)) {
                cout << "Product ID already exists!\n";
                continue;
            }

            cin.ignore();
            cout << "Enter Product Name: ";
            getline(cin, p.name);

            cout << "Enter Price: ";
            cin >> p.price;

            cout << "Enter Quantity: ";
            cin >> p.quantity;

            if (p.price < 0 || p.quantity < 0) {
                cout << "Invalid price or quantity!\n";
                continue;
            }

            inventory[id] = p;
            cout << "Product added successfully!\n";
        }
        else if (choice == 2) {
            cout << fixed << setprecision(2);

            for (const auto &item : inventory) {
                cout << "\nProduct ID: " << item.first
                     << "\nName: " << item.second.name
                     << "\nPrice: Rs. " << item.second.price
                     << "\nQuantity: " << item.second.quantity
                     << "\nStock Value: Rs. "
                     << item.second.price * item.second.quantity
                     << "\n";
            }

            if (inventory.empty())
                cout << "Inventory is empty.\n";
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            auto it = inventory.find(id);

            if (it != inventory.end()) {
                cout << "Product Found!\n";
                cout << "Name: " << it->second.name << "\n";
                cout << "Price: Rs. " << it->second.price << "\n";
                cout << "Quantity: " << it->second.quantity << "\n";
            } else {
                cout << "Product not found!\n";
            }
        }
        else if (choice == 4) {
            int id, quantity;
            cout << "Enter Product ID: ";
            cin >> id;

            auto it = inventory.find(id);

            if (it == inventory.end()) {
                cout << "Product not found!\n";
                continue;
            }

            cout << "Enter quantity to add or remove (+/-): ";
            cin >> quantity;

            if (it->second.quantity + quantity < 0) {
                cout << "Insufficient stock!\n";
            } else {
                it->second.quantity += quantity;
                cout << "Stock updated successfully!\n";
            }
        }
        else if (choice == 5) {
            double total = 0;

            for (const auto &item : inventory) {
                total += item.second.price * item.second.quantity;
            }

            cout << fixed << setprecision(2);
            cout << "Total Inventory Value: Rs. "
                 << total << "\n";
        }
        else if (choice == 6) {
            cout << "Exiting Inventory System...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
