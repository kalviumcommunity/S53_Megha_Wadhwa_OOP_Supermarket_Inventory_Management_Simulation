#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

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

class Category
{
private:
    static int nextID;
    static int totalCategories;

    int categoryID;
    string categoryName;
    string description;

public:
    Category(const string &name, const string &desc);

    CategoryDetails getDetails() const;
    int getCategoryID() const;
    string getCategoryName() const;
    string getDescription() const;

    void setCategoryName(const string &name);
    void setDescription(const string &desc);

    static int getTotalNumberOfCategories();
    static int getNextCategoryID();
};

#endif // CATEGORY_H
