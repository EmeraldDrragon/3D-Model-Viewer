#pragma once
#include <stdint.h>
#include "../model/model.h"

extern uint16_t SCALE; 

typedef struct {
    int16_t x, y;
} Point2i;

void rotate(
    const PointI* in,
    PointI* out,
    uint16_t count,
    uint16_t angle
);

void project(
    const PointI* in,
    Point2i* out,
    uint16_t count
);
