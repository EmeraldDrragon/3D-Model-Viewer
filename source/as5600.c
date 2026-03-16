#include "as5600.h"

void as5600_init()
{
    i2c_init(AS5600_I2C, AS5600_BAUDRATE);
    gpio_set_function(AS5600_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(AS5600_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(AS5600_SDA_PIN);
    gpio_pull_up(AS5600_SCL_PIN);
}

uint16_t as5600_read_raw()
{
    uint8_t reg = REG_RAW_ANGLE_HI;
    uint8_t buf[2];

    if (i2c_write_blocking(AS5600_I2C, AS5600_ADDR, &reg, 1, true) < 0)
    {
        return 0;
    }
    if (i2c_read_blocking(AS5600_I2C, AS5600_ADDR, buf, 2, false) < 0)
    {
        return 0;
    }
    return ((uint16_t)buf[0] << 8 | buf[1] & 0x0FFF);
}