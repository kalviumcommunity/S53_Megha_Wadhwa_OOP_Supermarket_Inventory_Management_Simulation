#include "../headers/CustomerMenu.h"
#include <iostream>

using namespace std;

void CustomerMenu::showMenu(Inventory* inventory) {
    int option;
    string categoryName;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. View All Products\n";
        cout << "2. View Categories\n";
        cout << "3. Buy Product\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                inventory->listProducts();
                break;

            case 2:
                cout << "\nAvailable Categories:\n";
                inventory->listCategories();

                cout << "Enter the category name to view products: ";
                cin.ignore();
                getline(cin, categoryName);
                inventory->listProductsByCategory(categoryName);
                break;

            case 3: {
                int productID, quantity;
                cout << "Enter Product ID to buy: ";
                cin >> productID;
                cout << "Enter quantity: ";
                cin >> quantity;

                Product* product = inventory->findProduct(productID);
                if (product && product->isAvailable(quantity)) {
                    product->updateQuantity(-quantity);
                    cout << "Purchased " << quantity << " units of " << product->getDetails().productName << endl;
                } else {
                    cout << "Sorry, not enough stock available or product not found.\n";
                }
                break;
            }

            case 4:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid input. Please try again!" << endl;
        }
    } while (option != 4);
}

void CustomerMenu::exit() {
    cout << "Exiting the Customer Menu. Thank you!\n";
}
