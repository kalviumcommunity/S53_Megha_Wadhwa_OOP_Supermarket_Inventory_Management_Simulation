#include "../headers/AdministratorMenu.h"
#include <iostream>

void AdministratorMenu::showMenu(Inventory* inventory) {
    int choice;
    do {
        std::cout << "\n--- Administrator Menu ---\n";
        std::cout << "1. Add Category\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Exit to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, description;
                std::cout << "Enter Category Name: ";
                std::cin >> name;
                std::cout << "Enter Category Description: ";
                std::cin >> description;
                inventory->getCategoryManager().addCategory(Category(name, description));
                std::cout << "Category added successfully!\n";
                break;
            }
            case 2: {
                std::string name, category, expiryDate;
                double price;
                int quantity;
                char perishable;

                std::cout << "Enter Product Name: ";
                std::cin >> name;
                std::cout << "Enter Category: ";
                std::cin >> category;
                std::cout << "Enter Price: ";
                std::cin >> price;
                std::cout << "Enter Quantity: ";
                std::cin >> quantity;
                std::cout << "Is it perishable? (y/n): ";
                std::cin >> perishable;

                if (perishable == 'y' || perishable == 'Y') {
                    std::cout << "Enter Expiry Date (YYYY-MM-DD): ";
                    std::cin >> expiryDate;
                    inventory->getProductManager().addProduct(
                        new PerishableProduct(name, category, price, quantity, expiryDate));
                } else {
                    inventory->getProductManager().addProduct(
                        new NonPerishableProduct(name, category, price, quantity));
                }
                std::cout << "Product added successfully!\n";
                break;
            }
            case 3:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

void AdministratorMenu::exit() {
    std::cout << "Exiting Administrator Menu.\n";
}
