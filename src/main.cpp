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
    Inventory inventory;
    Menu menu;

    inventory.addProduct( Product(1, "Milk", "Dairy", 1.99, 100, "2025-12-31"));
    inventory.addProduct( Product(2, "Bread", "Bakery", 2.49, 50, "2024-11-30"));

    cout << "\n--- Welcome to Supermarket Inventory Management System ---\n";
    int option = menu.showMainMenu();
    switch (option)
    {
    case 1:
        menu.showCustomerMenu(inventory);
        break;

    case 2:
        menu.showAdministratorMenu(inventory);
        break;

    case 3:
        menu.exit();
        return 0;

    default:
        cout << "Invalid input. Please try again!" << endl;
        menu.showMainMenu();
    }

    return 0;
}
