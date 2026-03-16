#pragma once
#include <stdint.h>
#include "../model/model.h"
#include "projection.h"

void renderFrame(
    const PointI* verts,
    const Edge* edges,
    uint16_t vertCount,
    uint16_t edgeCount,
    uint16_t angle
);

void Frame(
    const PointI* verts,
    const Edge* edges,
    uint16_t vertCount,
    uint16_t edgeCount,
    uint16_t angle
);
