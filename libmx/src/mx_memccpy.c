#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){
    char *t = dst;
    const char *s = src;
    const char *s_e = s + n;
    char ch = (char)c;
 
    for (;;) {
        if (ch == c || s >= s_e)
            break;
  
    *t++ = ch = *s++;
    }
 
    if (s >= s_e && ch != c)
        return (void *)NULL;
 
    return t;
}
