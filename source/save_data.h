//
// Created by Matthew on 11/23/2025.
//
#pragma once
#ifndef JDM_DS_RACER_SAVE_DATA_H
#define JDM_DS_RACER_SAVE_DATA_H

#include <stdint.h>

#define MAX_SLOT_NAME_SIZE 32

typedef struct {
    uint32_t magic;
    uint16_t version;

    uint8_t slot_index;
    char slot_name[MAX_SLOT_NAME_SIZE];

    uint32_t highscore;
    uint32_t money;

    uint32_t total_races;
    uint32_t total_wins;

    uint8_t difficulty;
    uint8_t  soundVolume;
    uint8_t  musicVolume;
    uint8_t  currentCarIndex;

} SaveData;

#endif //JDM_DS_RACER_SAVE_DATA_H