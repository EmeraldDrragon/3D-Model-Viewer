#pragma once
#include <stdint.h>

#define ANGLE_STEPS 4096

extern int16_t sinarr[ANGLE_STEPS];
extern int16_t cosarr[ANGLE_STEPS];

void trig_init(void);