#include <iostream>
#include "../headers/Main.h"
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include "../headers/Menu.h"
#include "./menu.cpp"
#include "./product.cpp"
#include "./inventory.cpp"

using namespace std;

int main()
{
    Inventory* inventory = new Inventory();
    Menu* menu = new Menu();

    // Create an array of Product objects
    const int NUM_PRODUCTS = 5;
    Product products[NUM_PRODUCTS] = {
        Product(1, "Milk", "Dairy", 1.99, 100, "2025-12-31"),
        Product(2, "Bread", "Bakery", 2.49, 50, "2024-11-30"),
        Product(3, "Eggs", "Dairy", 3.99, 200, "2024-10-15"),
        Product(4, "Butter", "Dairy", 4.99, 150, "2025-01-20"),
        Product(5, "Apples", "Fruit", 2.99, 300, "2024-09-30")
    };

    // Add each product in the array to the inventory
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        inventory->addProduct(products[i]);
    }

    cout << "\n--- Welcome to Supermarket Inventory Management System ---\n";
    int option = menu->showMainMenu();
    switch (option)
    {
    case 1:
        menu->showCustomerMenu(inventory);
        break;

    case 2:
        menu->showAdministratorMenu(inventory);
        break;

    case 3:
        menu->exit();
        return 0;

    default:
        cout << "Invalid input. Please try again!" << endl;
        menu->showMainMenu();
    }

    delete inventory;
    delete menu;

    return 0;
}
