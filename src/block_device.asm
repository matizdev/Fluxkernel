section .text
global block_device_init
global block_device_read_sector
global block_device_write_sector

block_device_init:
    ; Initialize the block device driver
    ; Parameters:
    ;   None
    ; Returns:
    ;   None
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    int 0x10 ; Initialize the block device driver
    ret

block_device_read_sector:
    ; Read a sector from the block device
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes read
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Read a sector from the block device
    mov eax, edx ; Return the number of bytes read
    ret

block_device_write_sector:
    ; Write a sector to the block device
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes written
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Write a sector to the block device
    mov eax, edx ; Return the number of bytes written
    ret

; Block device driver functions
block_device_read:
    ; Read data from the block device
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes read
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Read data from the block device
    mov eax, edx ; Return the number of bytes read
    ret

block_device_write:
    ; Write data to the block device
    ; Parameters:
    ;   eax: Sector number
    ;   ebx: Buffer address
    ;   ecx: Buffer size
    ; Returns:
    ;   eax: Number of bytes written
    mov edx, eax ; Save the sector number
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    mov edx, edx ; Set the sector number
    int 0x10 ; Write data to the block device
    mov eax, edx ; Return the number of bytes written
    ret

block_device_get_sector_size:
    ; Get the sector size of the block device
    ; Parameters:
    ;   None
    ; Returns:
    ;   eax: Sector size
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    int 0x10 ; Get the sector size of the block device
    ret

block_device_get_sector_count:
    ; Get the sector count of the block device
    ; Parameters:
    ;   None
    ; Returns:
    ;   eax: Sector count
    mov eax, 0x100000 ; Set the base address of the block device driver
    mov ebx, 0x1000 ; Set the size of the block device driver
    mov ecx, 0x1000 ; Set the offset of the block device driver
    int 0x10 ; Get the sector count of the block device
    ret