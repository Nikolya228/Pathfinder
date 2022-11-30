#include "../inc/libmx.h"

char *mx_int_to_char(int n){
    char *array = mx_strnew(40);
    int count = 0;
    if (n == 0)
        mx_printchar(n + '0');
    if (n < 0) {
        n = -n;
        mx_printchar('-');
    }
    for( ; n > 0; count++) {
        array[count] = (n % 10) + 48;
        n /= 10;
    }
    return array;
}
