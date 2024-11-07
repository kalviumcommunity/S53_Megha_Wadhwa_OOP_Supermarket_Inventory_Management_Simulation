#include <iostream>
#include "../headers/Main.h"
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include "../headers/Menu.h"
#include "../headers/Category.h"
#include "./menu.cpp"
#include "./product.cpp"
#include "./inventory.cpp"
#include "./category.cpp"

using namespace std;

int main() {
    Inventory *inventory = new Inventory();
    Menu *menu = new Menu();

    // Add sample categories
    Category dairy("Dairy", "Products made from milk such as milk, butter, cheese");
    Category bakery("Bakery", "Freshly baked goods like bread, cakes, etc.");
    Category fruits("Fruits", "Fresh fruits including apples, bananas, etc.");

    // Add categories to inventory
    inventory->addCategory(dairy);
    inventory->addCategory(bakery);
    inventory->addCategory(fruits);

    // Create an array of Product objects and associate them with categories
    const int NUM_PRODUCTS = 5;
    Product products[NUM_PRODUCTS] = {
        Product("Milk", "Dairy", 1.99, 100, "2025-12-31"),
        Product("Bread", "Bakery", 2.49, 50, "2024-11-30"),
        Product("Eggs", "Dairy", 3.99, 200, "2024-10-15"),
        Product("Butter", "Dairy", 4.99, 150, "2025-01-20"),
        Product("Apples", "Fruits", 2.99, 300, "2024-09-30")
    };

    // Add each product in the array to the inventory
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        inventory->addProduct(products[i]);
    }

    cout << "\n--- Welcome to Supermarket Inventory Management System ---\n";
    int option = menu->showMainMenu();
    switch (option) {
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
        option = menu->showMainMenu();
    }

    delete inventory;
    delete menu;

    return 0;
}