#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

using namespace std;

struct ProductDetails
{
public:
    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string expiryDate;
};

class Product
{
protected:
    static int nextID;
    static int totalProducts;

    int productID;
    string productName;
    string category;
    double price;
    int quantity;
    string expiryDate;

public:
    Product()
        : productName("Unknown"), category("General"), price(0.0), quantity(0), expiryDate("N/A")
    {
        productID = getProductID();
        totalProducts++;
    }

    Product(const string &name, const string &cat, double pr, int qty, const string &expDate)
        : productName(name), category(cat), price(pr), quantity(qty), expiryDate(expDate)
    {
        productID = getProductID();
        totalProducts++;
    }

    virtual ~Product() {
        totalProducts--;
    }

    virtual bool isExpired() const = 0;

    ProductDetails getDetails() const;
    void updatePrice(double newPrice);
    void updatePrice(double percentage, bool isIncrease);

    void updateQuantity(int amount);
    void updateQuantity(bool isRestock, int amount);
    bool isAvailable(int requestedQuantity) const;
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
