#include "display.h"
#include "math.h"
#include <stdlib.h>

bool framebuffer[SCR_HIGHT][SCR_WIDTH];

void display_clear(void)
{
    for (int y = 0; y < SCR_HIGHT; y++)
    {
        for (int x = 0; x < SCR_WIDTH; x++)
        {
            framebuffer[y][x] = false;
        }
    }
}

static void setPixel(int x, int y)
{
    if (x < 0 || x >= SCR_WIDTH || y < 0 || y >= SCR_HIGHT)
    {
        return;
    }
    framebuffer[y][x] = true;
}

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int stepx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int stepy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (true)
    {
        setPixel(x0, y0);

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * err;

        if (e2 >= dy)
        {
            err += dy;
            x0 += stepx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += stepy;
        }
    }
}


