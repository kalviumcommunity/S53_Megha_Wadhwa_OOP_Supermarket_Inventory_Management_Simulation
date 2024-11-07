#ifndef ABSTRACT_PRODUCT_H
#define ABSTRACT_PRODUCT_H

#include <string>

class AbstractProduct {
public:
    virtual ~AbstractProduct() = default;

    virtual std::string getProductName() const = 0;
    virtual std::string getCategory() const = 0;
    virtual double getPrice() const = 0;
    virtual int getQuantity() const = 0;
    virtual std::string getExpiryDate() const = 0;
    virtual void updatePrice(double newPrice) = 0;
    virtual void updateQuantity(int amount) = 0;
    virtual bool isAvailable(int requestedQuantity) const = 0;
    virtual bool isExpired() const = 0;
};

#endif // ABSTRACT_PRODUCT_H