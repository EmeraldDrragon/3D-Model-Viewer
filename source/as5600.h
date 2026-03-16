#ifndef MICROCONTROLLER_UE_AS5600_H
#define MICROCONTROLLER_UE_AS5600_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define AS5600_I2C i2c1
#define AS5600_ADDR 0x36
#define AS5600_SDA_PIN 14
#define AS5600_SCL_PIN 15
#define AS5600_BAUDRATE 400000

#define REG_ZMCO            0x00
#define REG_ZPOS_HI         0x01
#define REG_CONF_HI         0x07
#define REG_STATUS          0x0B
#define REG_RAW_ANGLE_HI    0x0C
#define REG_ANGLE_HI        0x0E
#define REG_AGC             0x1A
#define REG_MAGNITUDE_HI    0x1B

//initialize the sensor
void as5600_init();

//returns 0 - 4095
uint16_t as5600_read_raw();

#endif //MICROCONTROLLER_UE_AS5600_H