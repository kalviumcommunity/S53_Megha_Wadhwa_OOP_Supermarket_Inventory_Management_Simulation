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
    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string expiryDate;

public:
    Product(int id, const string &name, const string &cat, double pr, int qty, const string &expDate)
        : productID(id), productName(name), category(cat), price(pr), quantity(qty), expiryDate(expDate) {}
    ProductDetails getDetails();
    void updatePrice(double newPrice);
    void updateQuantity(int amount);
    bool isAvailable(int requestedQuantity);
    bool isExpired();
};

#endif