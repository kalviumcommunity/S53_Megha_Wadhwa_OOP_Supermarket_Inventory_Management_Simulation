#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

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

class Product
{
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
    void updatePrice(double newPrice);
    void updateQuantity(int amount);
    bool isAvailable(int requestedQuantity) const;
    bool isExpired() const;
    static int getTotalNumberOfProducts();
    static int getProductID();

    void setProductName(const string &name);
    void setCategory(const string &cat);
    void setExpiryDate(const string &expDate);

    string getProductName() const;
    string getCategory() const;
    double getPrice() const;
    int getQuantity() const;
    string getExpiryDate() const;
};

#endif