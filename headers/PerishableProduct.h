#ifndef PERISHABLE_PRODUCT_H
#define PERISHABLE_PRODUCT_H

#include "Product.h"  // Include the Product class header

class PerishableProduct : public Product {
public:
    PerishableProduct(const string &name, const string &cat, double pr, int qty, const string &expDate);

    virtual ~PerishableProduct() = default;

    bool isExpired() const override;
};

#endif
