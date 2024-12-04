#ifndef DISPLAY_H
#define DISPLAY_H

#include "./ProductManager.h"
#include "./CategoryManager.h"

class Display
{
public:
    void listProducts(const ProductManager &productManager) const;
    void listCategories(const CategoryManager &categoryManager) const;
    void listProductsByCategory(const ProductManager &productManager, const std::string &categoryName) const;
};

#endif // DISPLAY_H
