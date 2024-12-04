#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H

#include "./Product.h"
#include <vector>
#include <string>

class ProductManager
{
private:
    std::vector<Product *> products;

public:
    ~ProductManager();
    void addProduct(Product* product);
    void removeProduct(int productID);
    Product *findProduct(int productID);
    void listProducts();
};

#endif // PRODUCT_MANAGER_H
