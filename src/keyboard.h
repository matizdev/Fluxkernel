#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

// Keyboard driver functions
void keyboard_driver_init(void);
void keyboard_driver_interrupt_handler(void);
char *keyboard_driver_read_input(void);

#endif  // KEYBOARD_H