#pragma once
#include <stdbool.h>
#include <stdint.h>

#define SCR_WIDTH 128
#define SCR_HIGHT 64

extern bool framebuffer[SCR_HIGHT][SCR_WIDTH];

void display_clear(void);
void drawLine(int x0, int y0, int x1, int y1);

