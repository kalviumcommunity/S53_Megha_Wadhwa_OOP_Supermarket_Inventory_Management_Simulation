#ifndef ABSTRACT_CATEGORY_H
#define ABSTRACT_CATEGORY_H

#include <string>

class AbstractCategory {
public:
    virtual ~AbstractCategory() = default;

    virtual int getCategoryID() const = 0;
    virtual std::string getCategoryName() const = 0;
    virtual std::string getDescription() const = 0;
};

#endif // ABSTRACT_CATEGORY_H