#pragma once
#include <stdint.h>

#define SCALE_MIN  3
#define SCALE_MAX  10

extern uint16_t SCALE;

void buttons_init(void);

void buttons_update(void);