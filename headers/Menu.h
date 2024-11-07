#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Inventory.h"
using namespace std;

class Menu {
public:
    virtual ~Menu() {}
    virtual void showMenu(Inventory* inventory) = 0;
    void exit();
};

#endif
