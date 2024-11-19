#include "../headers/AdministratorMenu.h"
#include <iostream>
#include <cmath>
using namespace std;

// void AdministratorMenu::showMenu(Inventory *inventory)
// {
//     int option;
//     do
//     {
//         cout << "\n--- Administrator Menu ---\n";
//         cout << "1. Add Product\n";
//         cout << "2. Add Category\n";
//         cout << "3. Remove Product\n";
//         cout << "4. View All Products\n";
//         cout << "5. View All Categories\n";
//         cout << "6. Back to Main Menu\n";
//         cout << "Enter your choice: ";
//         cin >> option;

//         switch (option)
//         {
//         case 1:
//         {
//             string name, category, expiry;
//             double price;
//             int qty;

//             cout << "Enter Product Name: ";
//             cin.ignore(); // Clear the input buffer
//             getline(cin, name);
//             cout << "Enter Category: ";
//             getline(cin, category); // Use getline to read full category name
//             cout << "Enter Price: ";
//             cin >> price;
//             cout << "Enter Quantity: ";
//             cin >> qty;
//             cout << "Enter Expiry Date (Leave empty for non-perishable products): ";
//             cin.ignore();         // Clear the input buffer
//             getline(cin, expiry); // Allow empty expiry

//             Product *newProduct;
//             if (expiry.empty())
//             { // Check if expiry date is empty
//                 newProduct = new NonPerishableProduct(name, category, price, qty);
//             }
//             else
//             {
//                 newProduct = new PerishableProduct(name, category, price, qty, expiry);
//             }
//             inventory->addProduct(*newProduct);
//             delete newProduct; // Don't forget to free the memory!
//             cout << "Product added successfully.\n";
//             break;
//         }

//         case 2:
//         {
//             string name, description;

//             cout << "Enter Category Name: ";
//             cin.ignore(); // Clear the input buffer
//             getline(cin, name);
//             cout << "Enter Description: ";
//             getline(cin, description);

//             inventory->addCategory(Category(name, description));
//             cout << "Category added successfully.\n";
//             break;
//         }

//         case 3:
//         {
//             int productID;
//             cout << "Enter Product ID to remove: ";
//             cin >> productID;
//             inventory->removeProduct(productID);
//             cout << "Product removed successfully.\n";
//             break;
//         }

//         case 4:
//             inventory->listProducts();
//             break;

//         case 5:
//             inventory->listCategories();
//             break;

//         case 6:
//             cout << "Returning to Main Menu...\n";
//             break;

//         default:
//             cout << "Invalid input. Please try again!" << endl;
//         }
//     } while (option != 6);
// }

void AdministratorMenu::showMenu(Inventory *inventory)
{
    int option;
    do
    {
        cout << "\n--- Administrator Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Add Category\n";
        cout << "3. Remove Product\n";
        cout << "4. View All Products\n";
        cout << "5. View All Categories\n";
        cout << "6. Update Product Price\n";
        cout << "7. Update Product Quantity\n";
        cout << "8. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            string name, category, expiry;
            double price;
            int qty;

            cout << "Enter Product Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Category: ";
            getline(cin, category);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Expiry Date (Leave empty for non-perishable products): ";
            cin.ignore();
            getline(cin, expiry);

            Product *newProduct;
            if (expiry.empty())
            {
                newProduct = new NonPerishableProduct(name, category, price, qty);
            }
            else
            {
                newProduct = new PerishableProduct(name, category, price, qty, expiry);
            }
            inventory->addProduct(*newProduct);
            delete newProduct;
            cout << "Product added successfully.\n";
            break;
        }

        case 2:
        {
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

        case 3:
        {
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
        {
            int productID;
            double newPrice, percentage;
            char choice;
            cout << "Enter Product ID to update price: ";
            cin >> productID;

            Product *product = inventory->findProduct(productID);
            if (product)
            {
                cout << "Update price by (d)irect value or (p)ercentage? ";
                cin >> choice;
                if (choice == 'd')
                {
                    cout << "Enter new price: ";
                    cin >> newPrice;
                    product->updatePrice(newPrice);
                    cout << "Price updated successfully.\n";
                }
                else if (choice == 'p')
                {
                    cout << "Enter percentage (positive for increase, negative for decrease): ";
                    cin >> percentage;
                    product->updatePrice(abs(percentage), percentage > 0);
                    cout << "Price updated by " << percentage << "% successfully.\n";
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }
            else
            {
                cout << "Product not found.\n";
            }
            break;
        }

        case 7:
        {
            int productID, quantity;
            char choice;
            cout << "Enter Product ID to update quantity: ";
            cin >> productID;

            Product *product = inventory->findProduct(productID);
            if (product)
            {
                cout << "Adjust (r)estock or (d)ecrement quantity? ";
                cin >> choice;
                if (choice == 'r')
                {
                    cout << "Enter quantity to add: ";
                    cin >> quantity;
                    product->updateQuantity(true, quantity);
                    cout << "Stock updated successfully.\n";
                }
                else if (choice == 'd')
                {
                    cout << "Enter quantity to remove: ";
                    cin >> quantity;
                    product->updateQuantity(false, quantity);
                    cout << "Stock decremented successfully.\n";
                }
                else
                {
                    cout << "Invalid choice.\n";
                }
            }
            else
            {
                cout << "Product not found.\n";
            }
            break;
        }

        case 8:
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid input. Please try again!" << endl;
        }
    } while (option != 8);
}

void AdministratorMenu::exit()
{
    cout << "Exiting the Administrator Menu. Thank you!\n";
}
