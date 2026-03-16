#include "pico/stdio.h"
#include "render/renderer.h"
#include "model/model_data.h"
#include <stdio.h>
#include "as5600.h"
#include "buttons.h"
#include "display.h"
#include "render/renderer.h"
#include "render/scarray.h"
#include "ssd1306.h"
#include "gpio.h"

extern bool framebuffer[SCR_HIGHT][SCR_WIDTH];

int main()
{
    stdio_init_all();
    trig_init();
    oled_init();
    as5600_init();
    buttons_init();

    uint16_t angle = 0;

    while(true)
    {
        uint16_t sensor_angle = as5600_read_raw();
        //TODO update frame buffer
        //this prints the single 2x2 dot in the middle of the screen
        buttons_update();
        display_clear();
        renderFrame(
            modelVerts,
            modelEdges,
            vertCount,
            edgeCount,
            sensor_angle
        );
        oled_render_2d(framebuffer);
        sleep_ms(10);
    }
}
