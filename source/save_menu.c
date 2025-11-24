//
// Created by Matthew on 11/23/2025.
//
#include "save_menu.h"

struct MenuItem saveMenuItems[] = {
    {"SLOT ONE", 0},
    {"SLOT TWO", 1},
    {"SLOT THREE", 2},
    {"SLOT FOUR", 3}
};

int saveSlotsMenu(void) {
    return menuRun(saveMenuItems, SAVE_MENU_ITEM_COUNT);
}