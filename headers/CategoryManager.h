#ifndef CATEGORY_MANAGER_H
#define CATEGORY_MANAGER_H

#include "Category.h"
#include <vector>

class CategoryManager
{
private:
    std::vector<Category *> categories;

public:
    ~CategoryManager();
    void addCategory(const Category &category);
    void listCategories();
};

#endif // CATEGORY_MANAGER_H
