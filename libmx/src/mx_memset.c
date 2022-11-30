#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len){
    char* p = b;
    while (len--){
        *p++ = (char)c;
    }
    return b;
}
