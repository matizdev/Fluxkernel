#ifndef FAT32_H
#define FAT32_H

#include <stdint.h>

// FAT32 file system driver functions
void fat32_init(void);
uint32_t fat32_read_sector(uint32_t sector_number, void *buffer, uint32_t buffer_size);
uint32_t fat32_write_sector(uint32_t sector_number, void *buffer, uint32_t buffer_size);
int fat32_change_directory(const char *directory_name);

#endif  // FAT32_H