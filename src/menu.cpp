#include <iostream>
#include "../headers/Menu.h"
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include "../headers/Category.h"
using namespace std;


int Menu::showMainMenu() {
    cout << "1. Customer\n";
    cout << "2. Administrator\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void Menu::showCustomerMenu(Inventory* inventory) {
    int option;
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

            case 2: {
                cout << "\nAvailable Categories:\n";
                inventory->listCategories();

                string categoryName;
                cout << "Enter the category name to view products: ";
                cin.ignore();
                getline(cin, categoryName);
                inventory->listProductsByCategory(categoryName);
                break;
            }

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

void Menu::showAdministratorMenu(Inventory* inventory) {
    int option;
    do {
        cout << "\n--- Administrator Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Add Category\n";
        cout << "3. Remove Product\n";
        cout << "4. View All Products\n";
        cout << "5. View All Categories\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                string name, category, expiry;
                double price;
                int qty;

                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Category: ";
                cin >> category;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Expiry Date: ";
                cin >> expiry;

                inventory->addProduct(Product(name, category, price, qty, expiry));
                cout << "Product added successfully.\n";
                break;
            }

            case 2: {
                string name, description;

                cout << "Enter Category Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Description: ";
                getline(cin, description);

                inventory->addCategory(Category(name, description));
                cout << "Category added successfully.\n";
                break;
            }

            case 3: {
                int productID;
                cout << "Enter Product ID to remove: ";
                cin >> productID;
                inventory->removeProduct(productID);
                cout << "Product removed successfully.\n";
                break;
            }

            case 4:
                inventory->listProducts();
                break;

            case 5:
                inventory->listCategories();
                break;

            case 6:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid input. Please try again!" << endl;
        }
    } while (option != 6);
}

void Menu::exit() {
    cout << "Exiting the system. Thank you!\n";
}