#include "../headers/PerishableProduct.h"
#include <iostream>

PerishableProduct::PerishableProduct(const string &name, const string &cat, double pr, int qty, const string &expDate)
    : Product(name, cat, pr, qty, expDate) {}

bool PerishableProduct::isExpired() const {
    if (getExpiryDate() == "N/A") return false;
    
    return false;
}
