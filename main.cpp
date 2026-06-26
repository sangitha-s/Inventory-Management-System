#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(int i, string n, int q, double p) {
        id = i;
        name = n;
        quantity = q;
        price = p;
    }

    int getId() { return id; }
    string getName() { return name; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }

    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }

    void display() {
        cout << left << setw(5) << id
             << setw(20) << name
             << setw(10) << quantity
             << setw(10) << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        int id, qty;
        string name;
        double price;

        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price: ";
        cin >> price;

        products.push_back(Product(id, name, qty, price));
        cout << "Product Added Successfully!\n\n";
    }

    void displayAll() {
        if (products.empty()) {
            cout << "Inventory is empty!\n\n";
            return;
        }
        cout << "\n----- Inventory List -----\n";
        cout << left << setw(5) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Qty"
             << setw(10) << "Price" << endl;
        cout << "--------------------------------------------\n";
        for (auto &p : products) {
            p.display();
        }
        cout << "\n";
    }

    void searchProduct() {
        int id;
        cout << "Enter Product ID to search: ";
        cin >> id;

        for (auto &p : products) {
            if (p.getId() == id) {
                cout << "\nProduct Found:\n";
                cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Qty" << setw(10) << "Price" << endl;
                p.display();
                cout << "\n";
                return;
            }
        }
        cout << "Product not found!\n\n";
    }

    void updateStock() {
        int id, newQty;
        cout << "Enter Product ID to update stock: ";
        cin >> id;

        for (auto &p : products) {
            if (p.getId() == id) {
                cout << "Current Quantity: " << p.getQuantity() << endl;
                cout << "Enter New Quantity: ";
                cin >> newQty;
                p.setQuantity(newQty);
                cout << "Stock Updated!\n\n";
                return;
            }
        }
        cout << "Product not found!\n\n";
    }

    void deleteProduct() {
        int id;
        cout << "Enter Product ID to delete: ";
        cin >> id;

        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getId() == id) {
                products.erase(it);
                cout << "Product Deleted!\n\n";
                return;
            }
        }
        cout << "Product not found!\n\n";
    }
};

int main() {
    Inventory inv;
    int choice;

    do {
        cout << "===== Inventory Management System =====\n";
        cout << "1. Add Product\n2. Display All\n3. Search Product\n";
        cout << "4. Update Stock\n5. Delete Product\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: inv.addProduct(); break;
            case 2: inv.displayAll(); break;
            case 3: inv.searchProduct(); break;
            case 4: inv.updateStock(); break;
            case 5: inv.deleteProduct(); break;
            case 6: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice!\n\n";
        }
} while(choice != 6);

    return 0;
}
