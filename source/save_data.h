//
// Created by Matthew on 11/23/2025.
//
#pragma once
#ifndef JDM_DS_RACER_SAVE_DATA_H
#define JDM_DS_RACER_SAVE_DATA_H

#include <stdint.h>

typedef struct {
    uint8_t  slotIndex;

    uint32_t highscore;
    uint32_t money;

    uint32_t totalRaces;
    uint32_t totalWins;

    uint8_t  difficulty;
    uint8_t  soundVolume;
    uint8_t  musicVolume;
    uint8_t  currentCarIndex;
} SaveData;

#endif //JDM_DS_RACER_SAVE_DATA_H