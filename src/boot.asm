org 0x7C00
bits 16

section .multiboot
align 4
dd 0x1BADB002             ; magic number
dd 0x00000003             ; flags
dd 0x10000000 - (0x1BADB002 + 0x00000003) ; checksum

section .text
global start

start:
    ; Set up a basic stack
    mov ax, 0
    mov ss, ax
    mov esp, stack_top
    mov ebp, esp

    ; Load the kernel from the first sector of the hard drive
    mov eax, 0x1000        ; load address
    mov ecx, 1             ; sector count
    mov dl, 0x80          ; drive number (hard drive)
    
    ; Set up CHS values
    mov bl, 1             ; sector
    mov ch, 0             ; cylinder
    shr cx, 6             ; high 2 bits of cylinder
    mov cl, 0             ; head

    mov ah, 0x02           ; read sector
    int 0x13
    jc error               ; jump if carry flag is set (error)

    ; Jump to the kernel
    add eax, 0x1000
    jmp eax

error:
    ; handle error here
    mov si, error_message
    call print_string
    jmp $

kernel_main:
    ; kernel code here
    mov si, kernel_message
    call print_string
    jmp $

print_string:
    mov ah, 0x0E
.next:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .next
.done:
    ret

section .data
kernel_message db 'Kernel loaded successfully!', 0
error_message db 'Error loading kernel!', 0

section .bss
resb 1024
stack_top:

times 510-($-$$) db 0
dw 0xAA55