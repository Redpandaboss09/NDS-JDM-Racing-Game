//
// Created by Matthew on 11/22/2025.
//

#ifndef JDM_DS_RACER_MENU_H
#define JDM_DS_RACER_MENU_H

#include <nds.h>

struct MenuItem {
    const char* name;
    int count;
};

int arrowKeysDownHandler(int keys, int cursorLocation, int itemCount);
int menuRun(const struct MenuItem *items, int count);

extern PrintConsole consoleSub;

#endif //JDM_DS_RACER_MENU_H