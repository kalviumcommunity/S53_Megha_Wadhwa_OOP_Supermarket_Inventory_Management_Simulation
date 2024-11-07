#include <iostream>
#include "../headers/Product.h"
#include "../headers/Category.h"

using namespace std;

int Product::nextID = 0;

int Product::totalProducts = 0;

int Product::getTotalNumberOfProducts(){
    return totalProducts;
}

int Product::getProductID(){
    return ++nextID;
}

ProductDetails Product::getDetails() const
{
    ProductDetails details;

    details.productID = productID;
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

bool Product::isAvailable(int requestedQuantity) const
{
    return this->quantity >= requestedQuantity;
}

bool Product::isExpired() const
{
    return false;
}

string Product::getProductName() const {
    return productName;
}

string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

string Product::getExpiryDate() const {
    return expiryDate;
}

void Product::setProductName(const string &name) {
    productName = name;
}

void Product::setCategory(const string &cat) {
    category = cat;
}

void Product::setExpiryDate(const string &expDate) {
    expiryDate = expDate;
}
