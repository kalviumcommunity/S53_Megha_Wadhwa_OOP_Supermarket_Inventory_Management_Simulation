#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include "../headers/Menu.h"
#include "../headers/Category.h"
#include "../headers/PerishableProduct.h"
#include "../headers/NonPerishableProduct.h"
#include "../headers/CustomerMenu.h"
#include "../headers/AdministratorMenu.h"

#include "./menu.cpp"
#include "./product.cpp"
#include "./inventory.cpp"
#include "./category.cpp"
#include "./administratorMenu.cpp"
#include "./customerMenu.cpp"
#include "./nonPerishableProduct.cpp"
#include "./perishableProduct.cpp"

using namespace std;

int main()
{
    Inventory *inventory = new Inventory();

    // Add sample categories
    Category dairy("Dairy", "Products made from milk such as milk, butter, cheese");
    Category bakery("Bakery", "Freshly baked goods like bread, cakes, etc.");
    Category fruits("Fruits", "Fresh fruits including apples, bananas, etc.");

    // Add categories to inventory
    inventory->addCategory(dairy);
    inventory->addCategory(bakery);
    inventory->addCategory(fruits);

    // Create and add Perishable and Non-Perishable products to inventory
    const int NUM_PERISHABLE_PRODUCTS = 5;
    const int NUM_NON_PERISHABLE_PRODUCTS = 19;

    PerishableProduct perishableProducts[NUM_PERISHABLE_PRODUCTS] = {
        PerishableProduct("Milk", "Dairy", 1.99, 100, "2025-12-31"),
        PerishableProduct("Bread", "Bakery", 2.49, 50, "2024-11-30"),
        PerishableProduct("Eggs", "Dairy", 3.99, 200, "2024-10-15"),
        PerishableProduct("Butter", "Dairy", 4.99, 150, "2025-01-20"),
        PerishableProduct("Apples", "Fruits", 2.99, 300, "2024-09-30"),
    };

    NonPerishableProduct nonPerishableProducts[NUM_NON_PERISHABLE_PRODUCTS] = {
        NonPerishableProduct("Rice", "Grains", 1.8, 100),
        NonPerishableProduct("Flour", "Baking", 2.50, 150),
        NonPerishableProduct("Canned Beans", "Canned Goods", 0.99, 500),
        NonPerishableProduct("Pasta", "Baking", 1.20, 350),
        NonPerishableProduct("Sugar", "Baking", 1.50, 400),
        NonPerishableProduct("Salt", "Condiments", 0.75, 300),
        NonPerishableProduct("Tea", "Beverages", 3.99, 180),
        NonPerishableProduct("Coffee", "Beverages", 5.50, 120),
        NonPerishableProduct("Peanut Butter", "Snacks", 4.25, 250),
        NonPerishableProduct("Rice Krispies", "Snacks", 2.80, 150),
        NonPerishableProduct("Vegetable Oil", "Cooking", 3.00, 100),
        NonPerishableProduct("Canned Tomatoes", "Canned Goods", 1.20, 600),
        NonPerishableProduct("Crackers", "Snacks", 2.20, 220),
        NonPerishableProduct("Ketchup", "Condiments", 2.50, 350),
        NonPerishableProduct("Bottled Water", "Beverages", 0.99, 500),
        NonPerishableProduct("Instant Noodles", "Canned Goods", 1.00, 450),
        NonPerishableProduct("Canned Corn", "Canned Goods", 1.10, 500),
        NonPerishableProduct("Dry Lentils", "Grains", 2.00, 350),
        NonPerishableProduct("Oats", "Cereals", 3.10, 180)};

    // Add products to inventory
    for (int i = 0; i < NUM_PERISHABLE_PRODUCTS; i++)
    {
        inventory->addProduct(perishableProducts[i]);
    }

    for (int i = 0; i < NUM_NON_PERISHABLE_PRODUCTS; i++)
    {
        inventory->addProduct(nonPerishableProducts[i]);
    }


    PerishableProduct defaultPerishableProduct;
    inventory->addProduct(defaultPerishableProduct);

    NonPerishableProduct defaultNonPerishableProduct;
    inventory->addProduct(defaultNonPerishableProduct);


    cout << "\n--- Welcome to Supermarket Inventory Management System ---\n";

    // Choose the correct menu option
    int option;
    cout << "1. Customer\n";
    cout << "2. Administrator\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        CustomerMenu customerMenu;
        customerMenu.showMenu(inventory); // Pass inventory as an argument
        break;
    }
    case 2:
    {
        AdministratorMenu adminMenu;
        adminMenu.showMenu(inventory); // Pass inventory as an argument
        break;
    }
    case 3:
        cout << "Exiting the system. Thank you!\n";
        break;
    default:
        cout << "Invalid input. Please try again!" << endl;
        break;
    }

    delete inventory;
    return 0;
};