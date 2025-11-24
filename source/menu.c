//
// Created by Matthew on 11/23/2025.
//
#include <nds.h>
#include <stdio.h>

#include "menu.h"

#include <stdbool.h>

int arrowKeysDownHandler(int keys, int cursorLocation, int itemCount) {
    int newCursorLocation = cursorLocation;
    if (keys & KEY_UP) newCursorLocation--;
    if (keys & KEY_DOWN) newCursorLocation++;
    if (newCursorLocation < 0 || newCursorLocation > itemCount) return cursorLocation;
    return newCursorLocation;
}

int menuRun(const struct MenuItem *items, int itemCount) {
    consoleSelect(&consoleSub);

    int keys;
    int cursorLocation = 0;
    bool selected = false;

    while (1) {
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
                cursorLocation = arrowKeysDownHandler(keys, cursorLocation, itemCount);
            }
        }
    }
}