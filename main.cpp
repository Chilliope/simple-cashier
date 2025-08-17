#include <iostream>
#include <vector>
#include <iomanip>
#include <ranges>

using namespace std;

struct Product {
    string name;
    int amount;
    double price;
};

void showReceipt(vector<Product>& carts) {
    double total = 0;

    cout << "\n==== Shopping Receipt ====\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price"
         << setw(10) << "Total"
         << endl;

    for (auto &b : carts) {
        double subtotal = b.price * b.amount;
        total += subtotal;
        cout << left << setw(20) << b.name
             << setw(10) << b.amount
             << setw(10) << b.price
             << setw(10) << subtotal << endl;
    }

    cout << "\nTotal Price: Rp " << total << endl;
}

int main() {
    vector<Product> carts;
    int option;

    do {
        cout << "\n===-Cashier Menu====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Show Receipt" << endl;
        cout << "3. Quit" << endl;
        cout << "Select an option: ";
        cin >> option;

        if (option == 1) {
            int n;
            cout << "Please enter the number of products you entered: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                Product p;
                cout << "Enter Name: ";
                cin >> ws;
                getline(cin, p.name);
                cout << "Enter Price: ";
                cin >> p.price;
                cout << "Enter Amount: ";
                cin >> p.amount;

                carts.push_back(p);
                cout << "Product " << i+1 << " Added" << endl;
            }
        } else if (option == 2) {
            if (carts.empty()) {
                cout << "\nNo Products Found!";
            } else {
                showReceipt(carts);
            }
        } else if (option == 3) {
            cout << "\nQuitting...";
        } else {
            cout << "\nInvalid Input!";
        }
    } while (option != 3);

    return 0;
}