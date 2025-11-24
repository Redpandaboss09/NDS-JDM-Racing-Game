//
// Created by Matthew on 11/23/2025.
//
#include <stdio.h>
#include <fat.h>
#include "slot_system.h"

#include <string.h>

SlotSystem g_slotSystem;

const char* SAVE_FILENAME = "fat:/jdm_saves.dat";

void initSaveSystem() {
    FILE* file = fopen(SAVE_FILENAME, "rb");

    if (file) {
        fread(&g_slotSystem, sizeof(SlotSystem), 1, file);
        fclose(file);
    } else {
        memset(&g_slotSystem, 0, sizeof(SlotSystem));

        file = fopen(SAVE_FILENAME, "wb");
        if (file) {
            fwrite(&g_slotSystem, sizeof(SlotSystem), 1, file);
            fclose(file);
        }
    }
}

void saveSlotToDisk(int slotIndex) {
    FILE* file = fopen(SAVE_FILENAME, "rb+");
    if (file) {
        fseek(file, slotIndex * SLOT_SIZE_BYTES, SEEK_SET);
        fwrite(&g_slotSystem.slots[slotIndex], sizeof(SaveSlot), 1, file);
        fclose(file);
    }
}

void wipeSlot(int slotIndex) {
    memset(&g_slotSystem.slots[slotIndex], 0, sizeof(SaveSlot));
    saveSlotToDisk(slotIndex);
}
