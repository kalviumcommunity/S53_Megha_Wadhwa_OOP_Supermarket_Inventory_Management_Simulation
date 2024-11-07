#ifndef ADMINISTRATORMENU_H
#define ADMINISTRATORMENU_H

#include "Menu.h"
#include "Inventory.h"

class AdministratorMenu : public Menu {
public:
    void showMenu(Inventory* inventory) override;
    void exit();
};

#endif
