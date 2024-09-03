#include <iostream>
#include "../headers/Product.h"

using namespace std;

ProductDetails Product::getDetails()
{
    ProductDetails details;
    details.productID = productID;
    details.productName = productName;
    details.category = category;
    details.price = price;
    details.quantity = quantity;
    details.expiryDate = expiryDate;
    return details;
}

void Product:: updatePrice(double newPrice){
    price = newPrice;
}

void Product::updateQuantity(int amount) {
    quantity += amount;
}

bool Product::isAvailable(int requestedQuantity) {
    return quantity >= requestedQuantity;
}

bool Product::isExpired() {
    return false;
}
