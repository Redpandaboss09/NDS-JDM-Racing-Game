//
// Created by Matthew on 11/22/2025.
//

#include <nds.h>
#include <stdio.h>

#include "menu.h"

struct MenuItem items[] = {
    {"New Game", 0},
    {"Load Game", 1},
    {"Settings", 2}
};

int mainMenu(void) {
    consoleSelect(&consoleSub);

    int keys;
    int itemCount = 3;
    int cursorLocation = 0;
    bool selected = false;

    while(1) {
        swiWaitForVBlank();
        consoleClear();

        scanKeys();
        keys = keysDown();

        if (!selected) {
            for (int x = 0; x < itemCount; x++) {
                char cursor = (x == cursorLocation) ? '>' : ' ';
                iprintf("%c %s\n\n\n\n", cursor, items[x].name);
            }
        } else {
            iprintf("Selected: %s", items[cursorLocation].name);
        }

        if (keys & KEY_A) {
            return cursorLocation;
        } else if (keys & KEY_B) {
            return -1;
        } else {
            if (!selected) {
                cursorLocation = arrowKeysDownHandler(keys, cursorLocation);
            }
        }
    }
}

int arrowKeysDownHandler(int keys, int cursorLocation) {
    int newCursorLocation = cursorLocation;
    if (keys & KEY_UP) newCursorLocation--;
    if (keys & KEY_DOWN) newCursorLocation++;
    if (newCursorLocation < 0 || newCursorLocation > 2) return cursorLocation;
    return newCursorLocation;
}