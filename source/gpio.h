#pragma once
#include <stdint.h>

// GPIO functions
/** Pin is used for SPI */
#define FUNC_SPI 1
/** Pin is used for UART */
#define FUNC_UART 2
/** Pin is used for I2C */
#define FUNC_I2C 3
/** Pin is used for PWM */
#define FUNC_PWM 4
/** Pin is used for Input/Output */
#define FUNC_SIO 5
/** Pin is used for PIO0 */
#define FUNC_PIO0 6
/** Pin is used for PIO1 */
#define FUNC_PIO1 7
/** Pin is disabled */
#define FUNC_NONE 31

// GPIO input/output modes
/** Pin is used as an input */
#define MODE_IN 0
/** Pin is used as an output */
#define MODE_OUT 1

// Pull up/down modes
/** No pull up/down */
#define PULL_NONE 0
/** Pull down */
#define PULL_DOWN 1
/** Pull up */
#define PULL_UP 2

/** Configures the pin to be in the given mode using IO_BANK0.
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param function function of the pin, make sure it is between 0 and 31. Functions are predefined as GPIO_FUNC_...
 */
void set_gpio_function(int pin, int function);

/** Sets the input/output mode of the given pin using the SIO. Furthermore, the input enable bit in the corresponding PADS_BANK0 register is set.
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param mode input/output mode, GPIO_IN for input, GPIO_OUT for output
 */
void set_gpio_mode(int pin, int mode);

/** Sets the output level of the given pin using the SIO
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param level output level, zero is low, non-zero-value is high
 */
void set_gpio_level(int pin, int level);

/** Returns the input level of the given pin using the SIO
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @return zero if the pin is low, 1 if it is high. If pin is invalid, -1 is returned.
 */
int get_gpio_level(int pin);

/** Sets the pull of the given pin using the PADS_BANK0 registers
 *  @param pin id of the gpio pin, make sure that it is between 0 and 29
 *  @param pull pull of the pin, PULL_UP for pull-up, PULL_DOWN for pull-down, PULL_NONE for no pull
 */
void set_gpio_pull(int pin, int pull);