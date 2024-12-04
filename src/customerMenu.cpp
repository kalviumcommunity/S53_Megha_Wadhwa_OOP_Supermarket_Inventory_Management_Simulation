#include "../headers/CustomerMenu.h"
#include <iostream>

void CustomerMenu::showMenu(Inventory* inventory) {
    int choice;
    do {
        std::cout << "\n--- Customer Menu ---\n";
        std::cout << "1. View Products\n";
        std::cout << "2. View Categories\n";
        std::cout << "3. Exit to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory->getProductManager().listProducts();
                break;
            case 2:
                inventory->getCategoryManager().listCategories();
                break;
            case 3:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

void CustomerMenu::exit() {
    std::cout << "Exiting Customer Menu.\n";
}
