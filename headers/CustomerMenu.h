#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "Menu.h"
#include "Inventory.h"

using namespace std;

class CustomerMenu : public Menu {
public:
    void showMenu(Inventory* inventory) override;
    void exit();
};

#endif
