#include "../headers/PerishableProduct.h"
#include <iostream>
#include <ctime>

bool PerishableProduct::isExpired() const {

    if (expiryDate == "N/A") return false;
    return true;
}
