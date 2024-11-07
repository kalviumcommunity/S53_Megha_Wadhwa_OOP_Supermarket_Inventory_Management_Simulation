#ifndef INVENTORY_H
#define INVENTORY_H

#include "./Product.h"
#include "./Category.h"
#include <vector>

using namespace std;

class Inventory
{
private:
    vector<Product*> products;
    vector<Category*> categories;

public:
    void addProduct(const Product &product);
    void removeProduct(int productID);
    Product *findProduct(int productID);
    void listProducts();
    void addCategory(const Category &category);
    void listCategories() const;
    void listProductsByCategory(const string &categoryName) const;
};

#endif // INVENTORY_H