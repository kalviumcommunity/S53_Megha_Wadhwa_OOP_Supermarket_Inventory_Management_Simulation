#ifndef INVENTORY_H
#define INVENTORY_H

#include "./ProductManager.h"
#include "./CategoryManager.h"

class Inventory
{
private:
    ProductManager productManager;
    CategoryManager categoryManager;

public:
    ProductManager &getProductManager();   // Provide access to ProductManager
    CategoryManager &getCategoryManager(); // Provide access to CategoryManager
};

#endif // INVENTORY_H
