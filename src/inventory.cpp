#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include <iomanip>
#include <vector>

using namespace std;

void Inventory::addProduct(const Product &product)
{
    Product *newProduct = new Product(product);
    this->products.push_back(newProduct);
}

void Inventory::removeProduct(int productID)
{
    for (auto item = this->products.begin(); item != this->products.end(); ++item)
    {
        if ((*item)->getDetails().productID == productID)
        {
            delete *item;
            this->products.erase(item);
            break;
        }
    }
}

Product *Inventory::findProduct(int productID)
{
    for (auto &product : this->products)
    {
        if (product->getDetails().productID == productID)
        {
            return product;
        }
    }
    return nullptr;
}

void Inventory::listProducts()
{
    const char separator = ' ';
    const int nameWidth = 10;
    const int numWidth = 10;
    cout << "Total Products in the Inventory: " << Product::getTotalNumberOfProducts() << endl;
    // cout << "_____________________________________________________________________________\n";
    cout << "_________________________________________________________________________________\n";
    cout << left << setw(nameWidth) << setfill(separator) << "ID" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Name" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Category" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Price" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Quantity" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Expiry Date" << " | ";
    cout << endl;
    for (auto &product : products)
    {
        ProductDetails details = product->getDetails();

        cout << "_________________________________________________________________________________\n";
        cout << left << setw(nameWidth) << setfill(separator) << details.productID << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.productName << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.category << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.price << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.quantity << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.expiryDate << "  | ";
        cout << endl;
    }
    cout << "_________________________________________________________________________________\n";
}