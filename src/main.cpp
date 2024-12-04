#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/CustomerMenu.h"
#include "../headers/AdministratorMenu.h"
#include "../headers/PerishableProduct.h"
#include "../headers/NonPerishableProduct.h"
#include "../headers/Category.h"
#include "../headers/CustomerMenu.h"
#include "../headers/AdministratorMenu.h"
#include "../headers/Product.h"

#include "category.cpp"
#include "product.cpp"
#include "nonPerishableProduct.cpp"
#include "perishableProduct.cpp"
#include "inventory.cpp"
#include "categoryManager.cpp"
#include "productManager.cpp"
#include "customerMenu.cpp"
#include "administratorMenu.cpp"

int main() {
    Inventory inventory;

    inventory.getCategoryManager().addCategory(Category("Dairy", "Products made from milk"));
    inventory.getCategoryManager().addCategory(Category("Bakery", "Freshly baked goods"));

    Product* milk = new PerishableProduct("Milk", "Dairy", 1.99, 100, "2025-12-31");
    inventory.getProductManager().addProduct(milk);

    Product* rice = new NonPerishableProduct("Rice", "Grains", 2.50, 50);
    inventory.getProductManager().addProduct(rice);


    int userChoice;
    do {
        std::cout << "Welcome to Inventory Management System\n";
        std::cout << "1. Customer Menu\n";
        std::cout << "2. Administrator Menu\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userChoice;

        switch (userChoice) {
            case 1: {
                CustomerMenu customerMenu;
                customerMenu.showMenu(&inventory);
                break;
            }
            case 2: {
                AdministratorMenu adminMenu;
                adminMenu.showMenu(&inventory);
                break;
            }
            case 3:
                std::cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (userChoice != 3);

    return 0;
}
