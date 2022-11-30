#include "../inc/libmx.h"

void mx_printint(int n) {
    char array[80];
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
    for (int j = count - 1; j >= 0; j--)
        mx_printchar(array[j]);
}
