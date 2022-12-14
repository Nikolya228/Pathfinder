#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2){
    if (s1 && s2){
        char *arr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        arr = mx_strdup(s1);
        arr = mx_strcat(arr, s2);
        return arr;
    }
    else if(s1) return mx_strdup(s1);
    else if(s2) return mx_strdup(s2);
    else return NULL;
}
