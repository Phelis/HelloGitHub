#include <unistd.h>

size_t roundUpToPageSize(size_t size) 
{
    size_t page_size = getpagesize();    // returns the operating system's default page size
    return (size + (page_size -1)) & ~(page_size-1);
}

