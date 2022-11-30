#include "../inc/libmx.h"

void mx_printstr(const char *s)
{
    if (s == NULL){
        return;
    }
    
    int i = 0;
    
    while (s[i] != '\0'){
        mx_printchar(s[i]);
        i++;
    }
}
