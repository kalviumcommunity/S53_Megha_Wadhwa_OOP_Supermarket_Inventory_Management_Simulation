#include "../headers/CategoryManager.h"
#include "../headers/Category.h"

CategoryManager::~CategoryManager()
{
    for (auto category : categories)
    {
        delete category;
    }
}

void CategoryManager::addCategory(const Category &category)
{
    categories.push_back(new Category(category));
}

void CategoryManager::listCategories()
{
    for (const auto *category : categories)
    {
        cout << "Category ID: " << category->getCategoryID() << ", Name: " << category->getCategoryName() << "\n";
    }
}
