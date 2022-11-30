#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    char *csrc = (char *)src;
    char *cdest = (char *)dst;
    int n = (int)len;

    char *temp = malloc(len);

    for (int i = 0; i < n; i++){
        temp[i] = csrc[i];
    }

    for (int i = 0; i < n; i++){
        cdest[i] = temp[i];
    }
    free(temp);
    return dst;
}
