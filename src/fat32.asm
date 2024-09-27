section .text
global fat32_init
global fat32_read_sector
global fat32_write_sector
global fat32_change_directory

fat32_init:
    ; Initialize the FAT32 file system driver
    ; Load the FAT32 file system driver into memory
    mov eax, 0x100000 ; Load the FAT32 file system driver into memory
    mov ebx, 0x1000 ; Set the base address of the FAT32 file system driver
    mov ecx, 0x1000 ; Set the size of the FAT32 file system driver
    mov edx, 0x1000 ; Set the offset of the FAT32 file system driver
    int 0x10 ; Load the FAT32 file system driver into memory

    ; Initialize the FAT32 file system driver
    mov eax, 0x100000 ; Set the base address of the FAT32 file system driver
    mov ebx, 0x1000 ; Set the size of the FAT32 file system driver
    mov ecx, 0x1000 ; Set the offset of the FAT32 file system driver
    mov edx, 0x1000 ; Set the offset of the FAT32 file system driver
    int 0x10 ; Initialize the FAT32 file system driver

    ret

fat32_read_sector:
    ; Read a sector from the FAT32 file system
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes read
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the FAT32 file system driver
    mov ebx, 0x1000 ; Set the size of the FAT32 file system driver
    mov ecx, 0x1000 ; Set the offset of the FAT32 file system driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Read a sector from the FAT32 file system
    mov eax, edx ; Return the number of bytes read
    ret

fat32_write_sector:
    ; Write a sector to the FAT32 file system
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes written
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the FAT32 file system driver
    mov ebx, 0x1000 ; Set the size of the FAT32 file system driver
    mov ecx, 0x1000 ; Set the offset of the FAT32 file system driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Write a sector to the FAT32 file system
    mov eax, edx ; Return the number of bytes written
    ret

fat32_change_directory:
    ; Change the current directory
    ; Parameters:
    ;   eax: Directory name
    ; Returns:
    ;   eax: 0 if successful, -1 if failed
    mov edx, eax ; Save the directory name
    mov eax, 0x100000 ; Set the base address of the FAT32 file system driver
    mov ebx, 0x1000 ; Set the size of the FAT32 file system driver
    mov ecx, 0x1000 ; Set the offset of the FAT32 file system driver
    mov edx, edx ; Set the directory name
    int 0x10 ; Change the current directory
    mov eax, edx ; Return the result
    ret