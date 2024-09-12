#ifndef INVENTORY_H
#define INVENTORY_H

#include "../headers/Product.h"

#include <vector>

class Inventory
{
private:
    vector<Product*> products;

public:
    void addProduct(const Product &product);
    void removeProduct(int productID);
    Product *findProduct(int productID);
    void listProducts();
};

#endif // INVENTORY_H
