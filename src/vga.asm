section .text
global vga_init
global vga_clear_screen
global vga_set_resolution
global vga_set_color
global vga_put_char
global vga_put_string

; VGA initialization
vga_init:
    ; Set the VGA mode to 80x25
    mov ax, 0x0003
    int 0x10

    ; Set the VGA cursor shape
    mov ah, 0x01
    mov cx, 0x0607
    int 0x10

    ; Set the VGA cursor position
    mov ah, 0x02
    mov bh, 0x00
    mov dh, 0x00
    mov dl, 0x00
    int 0x10

    ret

; VGA clear screen
vga_clear_screen:
    ; Clear the VGA screen
    mov ax, 0x0600
    mov bx, 0x0007
    mov cx, 0x0000
    mov dx, 0x184F
    int 0x10

    ret

; VGA set resolution
vga_set_resolution:
    ; Set the VGA resolution to 80x25
    mov ax, 0x0003
    int 0x10

    ret

; VGA set color
vga_set_color:
    ; Set the VGA color
    mov ah, 0x0F
    mov bh, 0x00
    mov bl, al
    int 0x10

    ret

; VGA put char
vga_put_char:
    ; Put a character on the VGA screen
    mov ah, 0x0E
    mov bh, 0x00
    mov bl, 0x07
    mov al, [esp + 4]
    int 0x10

    ret

; VGA put string
vga_put_string:
    ; Put a string on the VGA screen
    mov si, [esp + 4]
    mov ah, 0x0E
    mov bh, 0x00
    mov bl, 0x07

.loop:
    lodsb
    test al, al
    jz .done
    int 0x10
    jmp .loop

.done:
    ret