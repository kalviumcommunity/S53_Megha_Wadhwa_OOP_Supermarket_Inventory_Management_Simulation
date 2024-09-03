#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/Product.h"

using namespace std;

void Inventory::addProduct(const Product& product)
{
    products.push_back(product);
}

void Inventory::removeProduct(int productID)
{
    for (auto item = products.begin(); item != products.end(); ++item)
    {
        if (item->getDetails().productID == productID)
        {
            products.erase(item);
            break;
        }
    }
}

Product* Inventory::findProduct(int productID) {
    for (auto& product : products) {
        if (product.getDetails().productID == productID) {
            return &product;
        }
    }
    return nullptr;
}

void Inventory::listProducts() {
    for (auto& product : products) {
        ProductDetails details = product.getDetails();
        
        cout << "ID: " << details.productID
             << ", Name: " << details.productName
             << ", Category: " << details.category
             << ", Price: " << details.price
             << ", Quantity: " << details.quantity
             << ", Expiry Date: " << details.expiryDate << endl;
    }
}