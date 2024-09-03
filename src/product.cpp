#include <iostream>
#include "../headers/Product.h"

using namespace std;

ProductDetails Product::getDetails()
{
    ProductDetails details;
    details.productID = this->productID;
    details.productName = this->productName;
    details.category = this->category;
    details.price = this->price;
    details.quantity = this->quantity;
    details.expiryDate = this->expiryDate;
    return details;
}

void Product::updatePrice(double newPrice)
{
    this->price = newPrice;
}

void Product::updateQuantity(int amount)
{
    this->quantity += amount;
}

bool Product::isAvailable(int requestedQuantity)
{
    return this->quantity >= requestedQuantity;
}

bool Product::isExpired()
{
    return false;  // This is a placeholder. Implement actual expiry check if needed.
}
