#include <iostream>
#include "../headers/Inventory.h"
#include "../headers/Product.h"
#include <iomanip>
#include <vector>

using namespace std;

void Inventory::addProduct(const Product &product)
{
    Product *newProduct;

    if (product.getExpiryDate().empty())
    {
        newProduct = new NonPerishableProduct(product.getProductName(), product.getCategory(), product.getPrice(), product.getQuantity());
    }
    else
    {
        newProduct = new PerishableProduct(product.getProductName(), product.getCategory(), product.getPrice(), product.getQuantity(), product.getExpiryDate());
    }

    products.push_back(newProduct);
}

void Inventory::removeProduct(int productID)
{
    for (auto item = this->products.begin(); item != this->products.end(); ++item)
    {
        if ((*item)->getDetails().productID == productID)
        {
            delete *item;
            this->products.erase(item);
            break;
        }
    }
}

Product *Inventory::findProduct(int productID)
{
    for (auto &product : this->products)
    {
        if (product->getDetails().productID == productID)
        {
            return product;
        }
    }
    return nullptr;
}

void Inventory::listProducts()

{
    const char separator = ' ';
    const int nameWidth = 20;
    const int numWidth = 5;
    cout << "Total Products in the Inventory: " << Product::getTotalNumberOfProducts() << endl;
    cout << "________________________________________________________________________________________________________________________\n";
    cout << left << setw(numWidth) << setfill(separator) << "ID" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Name" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Category" << "  | ";
    cout << left << setw(numWidth) << setfill(separator) << "Price" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Quantity" << "  | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Expiry Date" << " | ";
    cout << left << setw(nameWidth) << setfill(separator) << "Is Expired?" << " | ";
    cout << endl;
    for (auto &product : products)
    {
        ProductDetails details = product->getDetails();

        cout << "________________________________________________________________________________________________________________________\n";
        cout << left << setw(numWidth) << setfill(separator) << details.productID << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.productName << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.category << "  | ";
        cout << left << setw(numWidth) << setfill(separator) << details.price << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.quantity << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << details.expiryDate << "  | ";
        cout << left << setw(nameWidth) << setfill(separator) << (product->isExpired() ? "Yes" : "No") << "   | ";
        cout << endl;
    }
    cout << "________________________________________________________________________________________________________________________\n";
}

void Inventory::addCategory(const Category &category)
{
    categories.push_back(new Category(category));
}

void Inventory::listCategories() const
{
    for (const auto *category : categories)
    {
        cout << "Category ID: " << category->getCategoryID() << ", Name: " << category->getCategoryName() << "\n";
    }
}

void Inventory::listProductsByCategory(const string &categoryName) const
{
    for (const auto *product : products)
    {
        if (product->getCategory() == categoryName)
        {
            ProductDetails details = product->getDetails();
            cout << "ID: " << details.productID << ", Name: " << details.productName
                 << ", Price: " << details.price << ", Quantity: " << details.quantity << "\n";
        }
    }
}
