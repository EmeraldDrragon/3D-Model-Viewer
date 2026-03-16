#include "ssd1306.h"

void oled_send_cmd(uint8_t cmd)
{
    uint8_t buf[2] = {OLED_CMD_MODE, cmd};
    i2c_write_blocking(OLED_I2C_PORT, OLED_ADDR, buf, 2, false);
}

void oled_send_cmd_list(uint8_t* cmds, int len)
{
    for(int i = 0; i < len; i++)
    {
        oled_send_cmd(cmds[i]);
    }
}

void oled_init()
{
    i2c_init(OLED_I2C_PORT, OLED_BAUDRATE);
    gpio_set_function(OLED_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(OLED_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(OLED_SDA_PIN);
    gpio_pull_up(OLED_SCL_PIN);

    uint8_t init_sequence[] = {
        0xAE,
        0xD5, 0x80,
        0xA8, 0x3F,
        0xD3, 0x00,
        0x40,
        0x8D, 0x14,
        0x20, 0x00,
        0xA1,
        0xC8,
        0xDA,
        0x12,
        0x81, 0Xcf,
        0xD9, 0x40,
        0xA4,
        0xA6,
        0xAF
    };
    oled_send_cmd_list(init_sequence, sizeof(init_sequence));
}

void oled_render_2d(bool input[64][128])
{
    oled_send_cmd(0x21);
    oled_send_cmd(0);
    oled_send_cmd(127);

    oled_send_cmd(0x22);
    oled_send_cmd(0);
    oled_send_cmd(7);

    static uint8_t hw_buffer[OLED_BUF_SIZE + 1];
    hw_buffer[0] = OLED_DATA_MODE;

    for(int page = 0; page < OLED_PAGES; page++)
    {
        for(int x = 0; x < OLED_WIDTH; x++)
        {
            uint8_t current_byte = 0;
            for(int bit = 0; bit < 8; bit++)
            {
                if(input[page * 8 + bit][x])
                {
                    current_byte |= (1 << bit);
                }
            }
            hw_buffer[1 + (page * OLED_WIDTH + x)] = current_byte;
        }
    }

    i2c_write_blocking(OLED_I2C_PORT, OLED_ADDR, hw_buffer, OLED_BUF_SIZE + 1, false);
}