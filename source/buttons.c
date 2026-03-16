#include "buttons.h"
#include "gpio.h"

#define BTN_PLUS_PIN 17
#define BTN_MINUS_PIN 16

static int prev_up = 1;
static int prev_down = 1;

uint16_t SCALE = 4;

void buttons_init(void)
{
    set_gpio_function(BTN_PLUS_PIN, FUNC_SIO);
    set_gpio_mode(BTN_PLUS_PIN, MODE_IN);
    set_gpio_pull(BTN_PLUS_PIN, PULL_UP);

    set_gpio_function(BTN_MINUS_PIN, FUNC_SIO);
    set_gpio_mode(BTN_MINUS_PIN, MODE_IN);
    set_gpio_pull(BTN_MINUS_PIN, PULL_UP);
}

void buttons_update(void)
{
    int up = get_gpio_level(BTN_PLUS_PIN);
    int down = get_gpio_level(BTN_MINUS_PIN);

    if (prev_up == 1 && up == 0)
    {
        if (SCALE < SCALE_MAX)
        {
            SCALE++;
        }
    }

    if (prev_down == 1 && down == 0)
    {
        if (SCALE > SCALE_MIN)
        {
            SCALE--;
        }
    }

    prev_up = up;
    prev_down = down;
}
