#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include "AbstractProduct.h" // Include the abstract class header

using namespace std;

struct ProductDetails
{
    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string expiryDate;
};

class Product : public AbstractProduct { // Inherit from AbstractProduct
private:
    static int nextID;
    static int totalProducts;

    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string expiryDate;

public:
    Product(const string &name, const string &cat, double pr, int qty, const string &expDate)
        : productName(name), category(cat), price(pr), quantity(qty), expiryDate(expDate)
    {
        productID = getProductID();
        totalProducts++;
    }

    ProductDetails getDetails() const;

    // Implementing abstract methods
    string getProductName() const override;
    string getCategory() const override;
    double getPrice() const override;
    int getQuantity() const override;
    string getExpiryDate() const override;
    void updatePrice(double newPrice) override;
    void updateQuantity(int amount) override;
    bool isAvailable(int requestedQuantity) const override;
    bool isExpired() const override;

    static int getTotalNumberOfProducts();
    static int getProductID();

    void setProductName(const string &name);
    void setCategory(const string &cat);
    void setExpiryDate(const string &expDate);
};

#endif // PRODUCT_H