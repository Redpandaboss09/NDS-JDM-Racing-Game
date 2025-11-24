//
// Created by Matthew on 11/22/2025.
//

#ifndef JDM_DS_RACER_MENU_H
#define JDM_DS_RACER_MENU_H

struct MenuItem {
    const char* name;
    int count;
};

int arrowKeysDownHandler(int keys, int cursorLocation);
int mainMenu(void);

extern PrintConsole consoleSub;

#endif //JDM_DS_RACER_MENU_H