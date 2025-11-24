#include "impl/main_menu.h"

#include "menu.h"

struct MenuItem mainMenuItems[] = {
    {"Play", 0},
    {"Settings", 1}
};

int mainMenu(void) {
    return menuRun(mainMenuItems, MAIN_MENU_ITEM_COUNT);
}