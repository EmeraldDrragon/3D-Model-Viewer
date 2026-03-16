#include "gpio.h"

// -----------------------------------------------------------------------------
// Base Registers used for GPIO configuration - DO NOT CHANGE - these are fixed!
// -----------------------------------------------------------------------------
static volatile uint32_t* const io_bank0_base = (volatile uint32_t*)0x40014000;   // Base pointer for the IO_BANK0 registers
static volatile uint32_t* const pads_bank0_base = (volatile uint32_t*)0x4001C000; // Base pointer for the PADS_BANK0 registers
static volatile uint32_t* const sio_base = (volatile uint32_t*)0xD0000000;        // Base pointer for the SIO registers


/** Configures the pin to be in the given mode using IO_BANK0
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param function function of the pin, make sure it is between 0 and 31. Functions are predefined as GPIO_FUNC_...
 */
void set_gpio_function(const int pin, const int function)
{
    if (pin < 0 || pin > 29)
    {
        return;
    }

    if (function < 0 || function > 31)
    {
        return;
    }

    uint32_t reg_offset = 0x04 + (pin * 8);
    uint32_t reg = io_bank0_base[reg_offset / 4];

    reg = reg & ~0x1F;
    reg |= (function & 0x1F);
    io_bank0_base[reg_offset / 4] = reg;
}

/** Sets the input/output mode of the given pin using the SIO. Furthermore, the input enable bit in the corresponding PADS_BANK0 register is set.
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param mode input/output mode, GPIO_IN for input, GPIO_OUT for output
 */
void set_gpio_mode(const int pin, const int mode)
{
    if (pin < 0 || pin > 29)
    {
        return;
    }

    if (mode != MODE_IN && mode != MODE_OUT)
    {
        return;
    }

    uint32_t mask = 1u << pin;

    uint32_t reg_offset = 0x04 + (pin * 4);
    uint32_t reg = pads_bank0_base[reg_offset / 4];

    reg = reg | (1 << 6);
    pads_bank0_base[reg_offset / 4] = reg;

    if (mode == MODE_OUT)
    {
        sio_base[0x024 / 4] = mask;
    }
    else
    {
        sio_base[0x028 / 4] = mask;
    }
}

/** Sets the output level of the given pin using the SIO
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param level output level, zero is low, non-zero-value is high
 */
void set_gpio_level(const int pin, const int level)
{
    if (pin < 0 || pin > 29)
    {
        return;
    }

    uint32_t mask = 1u << pin;

    if (level)
    {
        sio_base[0x014 / 4] = mask;
    }
    else
    {
        sio_base[0x018 / 4] = mask;
    }
}

/** Returns the input level of the given pin using the SIO
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @return zero if the pin is low, 1 if it is high. If pin is invalid, -1 is returned.
 */
int get_gpio_level(const int pin)
{
    if (pin < 0 || pin > 29)
    {
        return -1;
    }

    uint32_t mask = 1u << pin;
    uint32_t input = sio_base[0x004 / 4];

    uint32_t if_statement = input & mask;

    if (if_statement)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/** Sets the pull of the given pin using the PADS_BANK0 registers
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param pull pull of the pin, PULL_UP for pull-up, PULL_DOWN for pull-down, PULL_NONE for no pull
 */
void set_gpio_pull(const int pin, const int pull)
{
    if (pin < 0 || pin > 29)
    {
        return;
    }

    uint32_t reg_offset = 0x04 + (pin * 4);
    uint32_t reg = pads_bank0_base[reg_offset / 4];

    reg = reg & (~((1 << 2) | (1 << 3)));
    
    if (pull == PULL_UP)
    {
        reg = reg | (1 << 3);
    }
    else if (pull == PULL_DOWN)
    {
        reg = reg | (1 << 2);
    }
    pads_bank0_base[reg_offset / 4] = reg;
}