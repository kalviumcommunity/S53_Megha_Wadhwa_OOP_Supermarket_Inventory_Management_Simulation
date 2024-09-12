#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/Product.h"

using namespace std;


void Inventory::addProduct(const Product& product)
{
    Product* newProduct = new Product(product);
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

Product* Inventory::findProduct(int productID) {
    for (auto& product : this->products) {
        if (product->getDetails().productID == productID) {
            return product;
        }
    }
    return nullptr;
}

void Inventory::listProducts() {
    for (auto& product : this->products) {
        ProductDetails details = product->getDetails();
        
        cout << "ID: " << details.productID
             << ", Name: " << details.productName
             << ", Category: " << details.category
             << ", Price: " << details.price
             << ", Quantity: " << details.quantity
             << ", Expiry Date: " << details.expiryDate << endl;
    }
}
