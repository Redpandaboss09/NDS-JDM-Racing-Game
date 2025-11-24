//
// Created by Matthew on 11/23/2025.
//

#ifndef JDM_DS_RACER_SAVE_SYSTEM_H
#define JDM_DS_RACER_SAVE_SYSTEM_H

#include "save_data.h"

#define TOTAL_SLOT_SIZE 65536
#define SLOT_COUNT 4
#define SLOT_SIZE_BYTES (TOTAL_SLOT_SIZE / SLOT_COUNT) // Each slot should be 16kb = 16384 bytes

#define MAX_SLOT_NAME_SIZE 32

typedef struct {
    uint32_t magic;
    uint16_t version;
    uint8_t  slotIndex;

    char slotName[MAX_SLOT_NAME_SIZE];

    SaveData slotData;

    uint8_t padding[SLOT_SIZE_BYTES - (sizeof(uint32_t) + sizeof(uint16_t) + sizeof(uint8_t) + 32 + sizeof(SaveData))];
} SaveSlot;

typedef struct {
    SaveSlot slots[SLOT_COUNT];
} SlotSystem;

SlotSystem g_slotSystem;

#endif //JDM_DS_RACER_SAVE_SYSTEM_H