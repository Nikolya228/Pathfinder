#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
    char *p = (char *) s;
    char *isChar = NULL;
    
    while((s != NULL) && (n--)){
        if (*p != (char) c){
            p++;
        }
        else{
            isChar = p;
            break;
        }
    }
    return isChar;
}
