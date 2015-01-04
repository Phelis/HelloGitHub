#ifndef CRC32_H
#define CRC32_H
#include <stdint.h>
#include <stdio.h>

// native crc
uint8_t crc32native(uint8_t remainder);

// slow crc
uint8_t crc32Slow (uint8_t const message[], int nBytes);

// generate a CRC table
void genCRCTable(void);

uint32_t rc_crc32(uint32_t crc, const char *buf, size_t len);

#endif
