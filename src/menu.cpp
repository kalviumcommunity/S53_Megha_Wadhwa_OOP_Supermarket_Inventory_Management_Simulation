#include <iostream>
#include "../headers/Menu.h"
#include "../headers/Inventory.h"
#include "../headers/Product.h"

using namespace std;

int Menu::showMainMenu()
{
    cout << "1. Customer \n";
    cout << "2. Administrator \n";
    cout << "3. Exit \n";
    cout << "Enter your choice: ";
    cin >> this->choice;
    return this->choice;
}

void Menu::showCustomerMenu(Inventory* inventory)
{
    int option;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. View Products\n";
        cout << "2. Buy Product\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            inventory->listProducts();
            break;

        case 2:
        {
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

        case 3:
            cout << "Returning to Main Menu...\n";
            showMainMenu();
            break;

        default:
            cout << "Invalid input. Please try again!" << endl;
        }
    } while (option != 3);
}

void Menu::showAdministratorMenu(Inventory* inventory)
{
    int option;
    do {
        cout << "\n--- Administrator Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. View All Products\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            int id, qty;
            double price;
            string name, category, expiry;

            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Category: ";
            cin >> category;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Expiry Date: ";
            cin >> expiry;

            inventory->addProduct(Product(id, name, category, price, qty, expiry));
            cout << "Product added successfully.\n";
            break;
        }

        case 2:
        {
            int productID;
            cout << "Enter Product ID to remove: ";
            cin >> productID;
            inventory->removeProduct(productID);
            cout << "Product removed successfully.\n";
            break;
        }

        case 3:
            inventory->listProducts();
            break;

        case 4:
            cout << "Returning to Main Menu...\n";
            showMainMenu();
            break;

        default:
            cout << "Invalid input. Please try again!" << endl;
        }
    } while (option != 4);
}

void Menu::exit()
{
    cout << "Exiting the system. Thank you!\n";
}
