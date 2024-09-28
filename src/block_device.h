#ifndef BLOCK_DEVICE_H
#define BLOCK_DEVICE_H

#include <stdint.h>

// Block device driver functions
void block_device_init(void);
uint32_t block_device_read_sector(uint32_t sector_number, void *buffer, uint32_t buffer_size);
uint32_t block_device_write_sector(uint32_t sector_number, void *buffer, uint32_t buffer_size);
uint32_t block_device_get_sector_size(void);
uint32_t block_device_get_sector_count(void);

#endif  // BLOCK_DEVICE_H