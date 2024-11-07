#include "../headers/Category.h"

using namespace std;

int Category::nextID = 1;
int Category::totalCategories = 0;

Category::Category(const string &name, const string &desc)
    : categoryName(name), description(desc) {
    categoryID = getNextCategoryID();
    totalCategories++;
}

int Category::getTotalNumberOfCategories() {
    return totalCategories;
}

int Category::getNextCategoryID() {
    return nextID++;
}

CategoryDetails Category::getDetails() const {
    return CategoryDetails(categoryID, categoryName, description);
}

int Category::getCategoryID() const {
    return categoryID;
}

string Category::getCategoryName() const {
    return categoryName;
}

string Category::getDescription() const {
    return description;
}

void Category::setCategoryName(const string &name) {
    categoryName = name;
}

void Category::setDescription(const string &desc) {
    description = desc;
}