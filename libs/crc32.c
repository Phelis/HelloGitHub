#include "crc32.h"

#include <stdio.h>

#define POLYNOMIAL 0xD8    /* 11011000, GF contains five bits, the remainder right-shits four bits */

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
#define POLYNOMIAL_SLOW 0x58           // In original, the most significant bit is one, therefore, we should
                                       // remove the GF most significant bit to be 0x58.
uint8_t crc32Slow (uint8_t const message[], int nBytes)    // instead of uint8_t array, use const void *buf
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
                remainder = (remainder << 1)^POLYNOMIAL_SLOW;    // assume that The most significant bit of any
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

// Refer to http://www.ross.net/crc/download/crc_v3.txt
uint8_t crcTable[256];
/*
 * In C, the algorithm main loop looks like this:
 
 * r=0;
 * while (len--)
 * {
 *      byte t = (r >> 24) & 0xFF;     // In first, compute the most 8 bits
 *      r = (r << 8) | *p++;           // add the least 8 bits into register
 *      r^=table[t];                   // the most 8 bits xor
 * }
 */
void genCRCTable(void) {
    uint32_t remainder;
    
    for (int dividend = 0; dividend < 256; dividend++) {
        remainder = dividend << 24;
        
        // perform module-2 division, a bit at a time
        for (uint16_t bit = 8; bit>0; bit--)
        {
            if (remainder & 0x80000000L) {
                remainder = (remainder << 1)^(0xedb88320);    // assume that The most significant bit of any
                // generator polynomial is always a one
            } else {
                remainder = (remainder << 1);
            }
        }
        if (dividend % 6 ==0) printf("\n");
        
        printf("0x%08x ", remainder);
    }
}

// reverse CRC32, this function refers to http://rosettacode.org/wiki/CRC-32
uint32_t rc_crc32(uint32_t crc, const char *buf, size_t len)
{
    static uint32_t table[256];
    static int have_table = 0;
    uint32_t rem;
    uint8_t octet;
    int i, j;
    const char *p, *q;
    
    /* This check is not thread safe; there is no mutex. */
    if (have_table == 0) {
        /* Calculate CRC table. */
        for (i = 0; i < 256; i++) {
            rem = i;  /* remainder from polynomial division */
            for (j = 0; j < 8; j++) {
                if (rem & 1) {
                    rem >>= 1;
                    rem ^= 0xedb88320;
                } else
                    rem >>= 1;
            }
            table[i] = rem;
        }
        have_table = 1;
    }
    
    crc = ~crc;
    q = buf + len;
    for (p = buf; p < q; p++) {
        octet = *p;  /* Cast to unsigned octet. */
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ octet];
    }
    return ~crc;
}