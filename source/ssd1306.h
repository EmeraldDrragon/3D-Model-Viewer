#ifndef MICROCONTROLLER_UE_SSD1306_H
#define MICROCONTROLLER_UE_SSD1306_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdlib.h>

#define OLED_I2C_PORT i2c0
#define OLED_SDA_PIN 8
#define OLED_SCL_PIN 9
//400kHz Fast Mode
#define OLED_BAUDRATE 400000
#define OLED_ADDR 0x3C

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_PAGES 8
#define OLED_BUF_SIZE (OLED_WIDTH * OLED_PAGES)

#define OLED_CMD_MODE 0x00
#define OLED_DATA_MODE 0x40

//send a single command byte
void oled_send_cmd(uint8_t cmd);

//send multiple command bytes
void oled_send_cmd_list(uint8_t *cmds, int len);

//oled i2c initialization
void oled_init();

//render the bool 2D array and send write pointers
void oled_render_2d(bool input[64][128]);

#endif //MICROCONTROLLER_UE_SSD1306_H