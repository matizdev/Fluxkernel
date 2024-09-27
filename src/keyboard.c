#include <stdint.h>
#include <stdbool.h>

// Keyboard buffer
#define KEYBOARD_BUFFER_SIZE 256
char keyboard_buffer[KEYBOARD_BUFFER_SIZE];
int keyboard_buffer_index = 0;

// Keyboard interrupt handler
void keyboard_interrupt_handler() {
    // Read the keyboard scan code
    uint8_t scan_code = inb(0x60);

    // Handle the keyboard scan code
    if (scan_code == 0x1C) {
        // Enter key pressed
        keyboard_buffer[keyboard_buffer_index++] = '\n';
    } else if (scan_code == 0x0E) {
        // Backspace key pressed
        if (keyboard_buffer_index > 0) {
            keyboard_buffer_index--;
        }
    } else {
        // Other key pressed
        char key = keyboard_scan_code_to_ascii(scan_code);
        if (key != 0) {
            keyboard_buffer[keyboard_buffer_index++] = key;
        }
    }

    // Check for buffer overflow
    if (keyboard_buffer_index >= KEYBOARD_BUFFER_SIZE) {
        keyboard_buffer_index = 0;
    }
}

// Convert keyboard scan code to ASCII
char keyboard_scan_code_to_ascii(uint8_t scan_code) {
    switch (scan_code) {
        case 0x1E:
            return 'a';
        case 0x30:
            return 'b';
        case 0x2E:
            return 'c';
        case 0x20:
            return 'd';
        case 0x12:
            return 'e';
        case 0x21:
            return 'f';
        case 0x22:
            return 'g';
        case 0x23:
            return 'h';
        case 0x17:
            return 'i';
        case 0x24:
            return 'j';
        case 0x25:
            return 'k';
        case 0x26:
            return 'l';
        case 0x32:
            return 'm';
        case 0x31:
            return 'n';
        case 0x18:
            return 'o';
        case 0x19:
            return 'p';
        case 0x10:
            return 'q';
        case 0x13:
            return 'r';
        case 0x1F:
            return 's';
        case 0x14:
            return 't';
        case 0x16:
            return 'u';
        case 0x2F:
            return 'v';
        case 0x11:
            return 'w';
        case 0x2D:
            return 'x';
        case 0x15:
            return 'y';
        case 0x2C:
            return 'z';
        default:
            return 0;
    }
}

// Read keyboard input
char *read_keyboard_input() {
    return keyboard_buffer;
}