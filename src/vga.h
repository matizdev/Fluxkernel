#ifndef VGA_H
#define VGA_H

#include <stdint.h>

// VGA driver functions
void vga_init(void);
void vga_clear_screen(void);
void vga_set_resolution(void);
void vga_set_color(uint8_t color);
void vga_put_char(char c);
void vga_put_string(const char *str);

#endif  // VGA_H