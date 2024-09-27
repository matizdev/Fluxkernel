section .multiboot
align 4
dd 0x1BADB002             ; magic number
dd 0x00000003             ; flags
dd - (0x1BADB002 + 0x00000003) ; checksum

section .text
global start
extern kernel_main

start:
    ; Set up a basic stack
    mov esp, stack_top
    mov ebp, esp

    ; Load the kernel from the first sector of the hard drive
    mov eax, 0x1000        ; load address
    mov ecx, 1             ; sector count
    mov edx, 0x80          ; drive number (hard drive)
    mov ebx, 0x00000001    ; cylinder/head/sector
    mov ah, 0x02           ; read sector
    int 0x13

    ; Jump to the kernel
    jmp kernel_main

section .bss
resb 1024
stack_top: