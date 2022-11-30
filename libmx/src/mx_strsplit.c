#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c){
    if(!s) {
        return NULL;
    }
    int coutn_of_words = mx_count_words(s, c);
    int i = 0;
    int wlen = 0;
    char** array = (char **)malloc((coutn_of_words + 1) * sizeof(char *));
    while(*s && (*s != '\0')) {
        if(*s != c) {
            int k = 0;
            while (s[k] && s[k] != c) {
                wlen++;
                k++;
            }
            array[i] = mx_strndup(s, wlen);
            i++;
            s += wlen;
            wlen = 0;
        }
        s++;
    }
    array[i] = NULL;
    return array;
}

