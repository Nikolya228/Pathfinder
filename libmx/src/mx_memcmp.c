#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *p = (char *)s1;
    char *q = (char *)s2;
    int compStatus = 0;

    if (s1 == s2){
        return compStatus;
    }
    while (n > 0){
        if (*p != *q){
            compStatus = (*p > *q) ? 1 : -1;
            break;
        }
        n--;
        p++;
        q++;
    }
    return compStatus;
}

