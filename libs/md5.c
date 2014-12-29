#include "md5.h"
#include <stdio.h>
#include <math.h>

#define ABS(X) ( (X)<0 ? -X : X )

void createMD5Table() 
{
    int i = 1;
    for (; i<= 64; i++)
    {
        printf("%.8x ", (unsigned int) (4294967296.0 *ABS(sin(i))));
        
        if (i%5 == 0)
            printf("\n");
    }
}
