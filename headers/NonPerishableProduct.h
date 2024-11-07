#ifndef NON_PERISHABLE_PRODUCT_H
#define NON_PERISHABLE_PRODUCT_H

#include "Product.h"

class NonPerishableProduct : public Product
{
public:
    NonPerishableProduct() {
        // Default values for non-perishable product
        productName = "Default NonPerishable";
        category = "General";
        price = 0.0;
        quantity = 0;
    }
    NonPerishableProduct(const string &name, const string &cat, double pr, int qty)
        : Product(name, cat, pr, qty, "") {}

    bool isExpired() const override;
};

#endif
