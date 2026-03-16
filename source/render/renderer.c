#include "renderer.h"
#include "display.h"
#include "projection.h"

#define MAX_VERTS 1024

static PointI rotated[MAX_VERTS];
static Point2i projected[MAX_VERTS];

void renderFrame(
    const PointI* verts,
    const Edge* edges,
    uint16_t vertCount,
    uint16_t edgeCount,
    uint16_t angle
)
{
    if (vertCount > MAX_VERTS)
    {
        return;
    }
    
    rotate(verts, rotated, vertCount, angle);
    project(rotated, projected, vertCount);

    for (uint16_t i = 0; i < edgeCount; i++)
    {
        uint16_t a = edges[i].a;
        uint16_t b = edges[i].b;

        if (a >= vertCount || b >= vertCount)
            continue;

        drawLine(
            projected[a].x,
            projected[a].y,
            projected[b].x,
            projected[b].y
        );
    }
}

