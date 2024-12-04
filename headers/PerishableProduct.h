#ifndef PERISHABLE_PRODUCT_H
#define PERISHABLE_PRODUCT_H

#include "Product.h"

class PerishableProduct : public Product
{
public:
    PerishableProduct() {
        // Default values for perishable product
        productName = "Default Perishable";
        category = "General";
        price = 0.0;
        quantity = 0;
        expiryDate = "N/A";
    }

    PerishableProduct(const string &name, const string &cat, double pr, int qty, const string &expDate)
        : Product(name, cat, pr, qty, expDate)
    {}

    bool isExpired() const override;  // Correctly override the base class method
};

#endif
