#include "scarray.h"
#include <math.h>


#define ANGLE_STEPS 4096

int16_t sinarr[ANGLE_STEPS];
int16_t cosarr[ANGLE_STEPS];

void trig_init(void)
{
    for (int i = 0; i < ANGLE_STEPS; i++)
    {
        double a = 2.0 * 3.141592653 * i / ANGLE_STEPS;
        sinarr[i] = (int16_t)(32767 * sin(a));
        cosarr[i] = (int16_t)(32767 * cos(a));
    }
}