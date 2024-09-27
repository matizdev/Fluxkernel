AS = nasm
CC = gcc
LD = ld

CFLAGS = -m64 -ffreestanding -c
LDFLAGS = -m elf64

all: kernel

kernel: kernel.asm fat32.asm block_device.asm vga.asm keyboard.asm kernel.c
    $(AS) -f elf64 kernel.asm -o kernel.o
    $(AS) -f elf64 fat32.asm -o fat32.o
    $(AS) -f elf64 block_device.asm -o block_device.o
    $(AS) -f elf64 vga.asm -o vga.o
    $(AS) -f elf64 keyboard.asm -o keyboard.o
    $(CC) $(CFLAGS) kernel.c -o kernel_c.o
    $(LD) $(LDFLAGS) kernel.o fat32.o block_device.o vga.o keyboard.o kernel_c.o -o kernel

run: kernel
    qemu-system-x86_64 -kernel kernel

clean:
    rm -f *.o kernel

32bit:
    $(AS) -f elf32 kernel.asm -o kernel_32.o
    $(AS) -f elf32 fat32.asm -o fat32_32.o
    $(AS) -f elf32 block_device.asm -o block_device_32.o
    $(AS) -f elf32 vga.asm -o vga_32.o
    $(AS) -f elf32 keyboard.asm -o keyboard_32.o
    $(CC) $(CFLAGS) -m32 kernel.c -o kernel_c_32.o