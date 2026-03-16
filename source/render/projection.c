#include "projection.h"
#include "scarray.h"

void rotate(const PointI* in, PointI* out, uint16_t count, uint16_t angle)
{
    int16_t s = sinarr[angle];
    int16_t c = cosarr[angle];

    for (uint16_t i = 0; i < count; i++)
    {
        int32_t x = in[i].x;
        int32_t z = in[i].z;

        out[i].x = (x * c - z * s) >> 15;
        out[i].z = (x * s + z * c) >> 15;
        out[i].y = in[i].y;
    }
}

void project(const PointI* in, Point2i* out, uint16_t count)
{
    for (uint16_t i = 0; i < count; i++)
    {
        out[i].x = (in[i].x >> SCALE) + 64;
        out[i].y = (in[i].y >> SCALE) + 32;
    }
}