//
// Created by Matthew on 11/24/2025.
//

#ifndef JDM_DS_RACER_CAR_H
#define JDM_DS_RACER_CAR_H

#include "../core/math_utils.h"

typedef struct {
    int FL;
    int FR;
    int BL;
    int BR;
} WheelConfig;

typedef struct {
    // TODO ADD MORE CAR SPECS (Look at other car sims to gather needed / wanted info)
    int topSpeed;

    uint32_t mass;

    WheelConfig wheelLayout;
} CarStats;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 angularVelocity;

    int acceleration;
    int RPM;

    int16_t rotationX;
    int16_t rotationY;
    int16_t rotationZ;

    CarStats carStats;
} CarState;

#endif //JDM_DS_RACER_CAR_H