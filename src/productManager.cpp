#include "../headers/ProductManager.h"
#include "../headers/NonPerishableProduct.h"
#include "../headers/Product.h"
#include <iomanip>

ProductManager::~ProductManager()
{
    for (auto product : products)
    {
        delete product;
    }
}

void ProductManager::addProduct(Product* product) {
    products.push_back(product);
}

void ProductManager::removeProduct(int productID)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if ((*it)->getDetails().productID == productID)
        {
            delete *it;
            products.erase(it);
            break;
        }
    }
}

Product *ProductManager::findProduct(int productID)
{
    for (auto &product : products)
    {
        if (product->getDetails().productID == productID)
        {
            return product;
        }
    }
    return nullptr;
}

void ProductManager::listProducts()
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
