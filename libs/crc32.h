#ifndef CRC32_H
#define CRC32_H
#include <stdint.h>

// native crc
uint8_t crc32native(uint8_t remainder);

// slow crc
uint8_t crc32Slow (uint8_t const message[], int nBytes);

#endif
