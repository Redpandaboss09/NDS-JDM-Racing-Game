//
// Created by Matthew on 11/24/2025.
//

#ifndef JDM_DS_RACER_MATH_COMPAT_H
#define JDM_DS_RACER_MATH_COMPAT_H

#include <stdint.h>

#define SHIFT_AMOUNT 12

typedef struct {
    int32_t x;
    int32_t y;
    int32_t z;
} Vector3;

static inline Vector3 vec_add(Vector3 a, Vector3 b) {
    Vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

// TODO FIX OVERFLOW (cast to 64?)
static inline Vector3 vec_scale(Vector3 v, int32_t scale) {
    Vector3 result;
    result.x = (v.x * scale) >> SHIFT_AMOUNT;
    result.y = (v.y * scale) >> SHIFT_AMOUNT;
    result.z = (v.z * scale) >> SHIFT_AMOUNT;
    return result;
}

#endif //JDM_DS_RACER_MATH_COMPAT_H