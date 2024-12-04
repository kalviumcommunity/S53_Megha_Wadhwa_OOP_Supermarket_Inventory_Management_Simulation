#include "../headers/NonPerishableProduct.h"

NonPerishableProduct::NonPerishableProduct(const string &name, const string &cat, double pr, int qty)
    : Product(name, cat, pr, qty, "N/A") {}

bool NonPerishableProduct::isExpired() const {
    return false;
}
