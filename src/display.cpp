#include "../headers/Display.h"
#include <iostream>
#include <iomanip>

void Display::listProducts(const ProductManager &productManager) const
{
    const char separator = ' ';
    const int nameWidth = 20;
    const int numWidth = 5;

    std::cout << "Total Products in the Inventory: " << Product::getTotalNumberOfProducts() << std::endl;
    std::cout << "________________________________________________________________________________________________________________________\n";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "ID" << "  | ";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Name" << "  | ";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Category" << "  | ";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "Price" << "  | ";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Quantity" << "  | ";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Expiry Date" << " | ";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Is Expired?" << " | ";
    std::cout << std::endl;

    for (auto &product : productManager.getAllProducts())
    {
        ProductDetails details = product->getDetails();

        std::cout << "________________________________________________________________________________________________________________________\n";
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << details.productID << "  | ";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << details.productName << "  | ";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << details.category << "  | ";
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << details.price << "  | ";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << details.quantity << "  | ";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << details.expiryDate << "  | ";
        std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << (product->isExpired() ? "Yes" : "No") << "   | ";
        std::cout << std::endl;
    }
    std::cout << "________________________________________________________________________________________________________________________\n";
}

void Display::listCategories(const CategoryManager &categoryManager) const
{
    for (const auto *category : categoryManager.getAllCategories())
    {
        std::cout << "Category ID: " << category->getCategoryID() << ", Name: " << category->getCategoryName() << "\n";
    }
}

void Display::listProductsByCategory(const ProductManager &productManager, const std::string &categoryName) const
{
    for (const auto *product : productManager.getAllProducts())
    {
        if (product->getCategory() == categoryName)
        {
            ProductDetails details = product->getDetails();
            std::cout << "ID: " << details.productID << ", Name: " << details.productName
                      << ", Price: " << details.price << ", Quantity: " << details.quantity << "\n";
        }
    }
}
