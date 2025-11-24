//
// Created by Matthew on 11/23/2025.
//
#include <stdio.h>

#include "save_menu.h"
#include "slot_system.h"

char menuDisplayStrings[SLOT_COUNT][32];

struct MenuItem saveMenuItems[SLOT_COUNT];

void prepareMenuStrings() {
    for (int i = 0; i < SLOT_COUNT; i++) {
        if (g_slotSystem.slots[i].magic == SAVE_MAGIC) {
            sprintf(menuDisplayStrings[i], "Slot %d: %s", i+1, g_slotSystem.slots[i].slotName);
        } else {
            sprintf(menuDisplayStrings[i], "Slot %d: -EMPTY-", i+1);
        }

        saveMenuItems[i].name = menuDisplayStrings[i];
        saveMenuItems[i].count = i; // TODO check this?
    }
}

void createNewSave(int slotIndex) {
    SaveSlot* s = &g_slotSystem.slots[slotIndex];

    memset(s, 0, sizeof(SaveSlot));

    s->magic = SAVE_MAGIC;
    s->version = 1;
    s->slotIndex = slotIndex;

    // TODO: ADD KEYBOARD SCREEN
    sprintf(s->slotName, "Player %d", slotIndex + 1);

    // TODO: GAME DEFAULT SPECIFICS
    SaveData d;
    memset(&d, 0, sizeof(SaveData));

    d.slotIndex = slotIndex;
    d.highscore = 0;
    d.money = 0;
    d.totalRaces = 0;
    d.totalWins = 0;
    d.difficulty = 0;
    d.musicVolume = 127;
    d.soundVolume = 127;
    d.currentCarIndex = 0;

    s->slotData = d;

    saveSlotToDisk(slotIndex);

    iprintf("\x1b[10;0HSave Created!");
}

int saveSlotsMenu(void) {
    initSaveSystem();

    while (1) {
        prepareMenuStrings();

        int selectedIndex = menuRun(saveMenuItems, SLOT_COUNT);

        if (selectedIndex == -1) {
            return -1; // User pressed B
        }

        if (g_slotSystem.slots[selectedIndex].magic == SAVE_MAGIC) {
            iprintf("\nLoading Slot %d...", selectedIndex + 1);
            return selectedIndex;
        } else {
            createNewSave(selectedIndex);
            for (int i=0; i<60; i++) swiWaitForVBlank();
        }
    }
}