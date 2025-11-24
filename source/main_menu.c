#include "main_menu.h"

#include "menu.h"

struct MenuItem mainMenuItems[] = {
    {"New Game", 0},
    {"Load Game", 1},
    {"Settings", 2}
};

int mainMenu(void) {
    return menuRun(mainMenuItems, MAIN_MENU_ITEM_COUNT);
}