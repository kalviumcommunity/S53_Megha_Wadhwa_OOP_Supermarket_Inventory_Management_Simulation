#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include "AbstractCategory.h"

using namespace std;

class CategoryDetails
{
public:
    int categoryID;
    string categoryName;
    string description;

    CategoryDetails(int id, const string &name, const string &desc)
        : categoryID(id), categoryName(name), description(desc) {}
};

class Category : public AbstractCategory {
private:
    static int nextID;
    static int totalCategories;

    int categoryID;
    string categoryName;
    string description;

public:
    Category(const string &name, const string &desc);

    int getCategoryID() const override;
    string getCategoryName() const override;
    string getDescription() const override;

    CategoryDetails getDetails() const;
    void setCategoryName(const string &name);
    void setDescription(const string &desc);

    static int getTotalNumberOfCategories();
    static int getNextCategoryID();
};

#endif // CATEGORY_H