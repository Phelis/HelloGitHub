#include "crc32.h"

#include <stdio.h>

#define POLYNOMIAL 0xD8    /* 11011000 */

// bit by bit
uint8_t crc32native(uint8_t remainder)
{
    /*
     * Initially, the dividen is the remainder
     */
    
    for (uint8_t bit = 8; bit>0; bit--)
    {
        
        if (remainder & 0x80) 
        {
            remainder ^= POLYNOMIAL;
        }
        remainder = (remainder << 1);
    }

    return (remainder >> 4);
}

// byte by byte
/*
 * The width of the CRC calculation
 */
#define WIDTH (8 * sizeof(uint8_t))    // from byte to bit
#define TOPBIT (1<<(WIDTH-1))          // (WIDTH-1) is to know how many zeros should be filled with

uint8_t crc32Slow (uint8_t const message[], int nBytes)
{
    uint8_t remainder = 0;

    /*
     * perform modulo-2 division, a byte at a time
     */
    for (int byte = 0; byte < nBytes; ++byte)
    {
        // bring the next byte into the remainder.
        remainder ^= (message[byte] << (WIDTH-8));    // if WIDTH = 32 then (32 - 8) is 24
        
        // perform module-2 division, a bit at a time
        for (uint8_t bit = 8; bit>0; bit--)
        {
            if (remainder & TOPBIT) {
                remainder = (remainder << 1)^POLYNOMIAL;    // assume that The most significant bit of any
                                                            // generator polynomial is always a one
            } else {
                remainder = (remainder << 1);
            }
        }
    }
    
    /*
     * The final remainder is the CRC result
     */
    return (remainder >> 4);
}

