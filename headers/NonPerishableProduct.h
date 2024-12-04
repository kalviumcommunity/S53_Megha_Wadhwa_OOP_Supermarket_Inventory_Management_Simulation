#ifndef NON_PERISHABLE_PRODUCT_H
#define NON_PERISHABLE_PRODUCT_H

#include "Product.h"

class NonPerishableProduct : public Product {
public:
    NonPerishableProduct(const string &name, const string &cat, double pr, int qty);
    virtual ~NonPerishableProduct() = default;

    bool isExpired() const override;
};

#endif
