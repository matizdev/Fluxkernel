section .multiboot
align 4
dd 0x1BADB002             ; magic number
dd 0x00000003             ; flags
dd - (0x1BADB002 + 0x00000003) ; checksum

section .data
stack:
    times 1024 db 0
stack_top:

section .bss
resb 1024

section .text
global start
extern kernel_main

start:
    ; Set up a basic stack
    mov esp, stack_top
    mov ebp, esp

    ; Initialize the GDT
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:init_pm

init_pm:
    ; Set up a basic IDT
    lidt [idt_descriptor]

    ; Enable interrupts
    sti

    ; Initialize the block device driver
    call init_block_device

    ; Initialize the FAT32 file system driver
    call init_fat32

    ; Initialize the VGA driver
    call init_vga

    ; Call the kernel main function
    call kernel_main

    ; Halt the CPU
    cli
    hlt

section .data
gdt_start:
    ; Null descriptor
    dd 0
    dd 0

    ; Code segment descriptor
    dw 0xFFFF           ; segment limit
    dw 0                ; base low
    db 0                ; base middle
    db 0x9A             ; access byte
    db 0xCF             ; granularity
    db 0                ; base high

    ; Data segment descriptor
    dw 0xFFFF           ; segment limit
    dw 0                ; base low
    db 0                ; base middle
    db 0x92             ; access byte
    db 0xCF             ; granularity
    db 0                ; base high

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size of GDT
    dd gdt_start            ; start address of GDT

idt_start:
    ; Null descriptor
    dd 0
    dd 0

    ; Keyboard interrupt handler
    dw keyboard_handler
    dw CODE_SEG
    db 0
    db 0x8E
    db 0

    ; Timer interrupt handler
    dw timer_handler
    dw CODE_SEG
    db 0
    db 0x8E
    db 0

idt_end:

idt_descriptor:
    dw idt_end - idt_start - 1 ; size of IDT
    dd idt_start            ; start address of IDT

section .text
CODE_SEG equ gdt_start + (0x10 - 1)
DATA_SEG equ gdt_start + (0x20 - 1)

keyboard_handler:
    ; Handle keyboard interrupt
    in al, 0x60
    mov [key_pressed], al
    iret

timer_handler:
    ; Handle timer interrupt
    mov eax, [timer_count]
    inc eax
    mov [timer_count], eax
    iret

section .data
key_pressed db 0
timer_count dd 0