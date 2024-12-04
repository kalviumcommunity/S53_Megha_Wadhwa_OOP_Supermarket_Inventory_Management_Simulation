#include "../headers/Inventory.h"

ProductManager &Inventory::getProductManager()
{
    return productManager;
}

CategoryManager &Inventory::getCategoryManager()
{
    return categoryManager;
}
