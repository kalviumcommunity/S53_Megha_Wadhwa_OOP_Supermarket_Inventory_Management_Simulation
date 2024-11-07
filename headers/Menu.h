#ifndef MENU_H
#define MENU_H

#include "Inventory.h"

class Menu
{
private:
    int choice;

public:
    int showMainMenu();
    void showCustomerMenu(Inventory* inventory);
    void showAdministratorMenu(Inventory* inventory);
    void exit();
};

#endif // MENU_H