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
    ProductManager &getProductManager();  
    CategoryManager &getCategoryManager();
};

#endif // INVENTORY_H
