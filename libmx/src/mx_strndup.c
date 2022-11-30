#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t length = mx_strlen(s1);
    if (n < length)
    {
        length = n;
    }
    char *res = mx_strnew(length);
    for (size_t i = 0; i < length; i++)
    {
        res[i] = s1[i];
    }
    
    return res;
}
