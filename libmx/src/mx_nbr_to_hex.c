#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
    char *arr = malloc(1);

    int i = 0;

    while (nbr != 0){
        int r = nbr % 16;
        if (r > 9){
            r += 'a' - 10;
        }
        else  
            r += '0';
        arr = mx_realloc(arr, i + 1);
        arr[i] = r;
        i++;
        nbr /= 16;
    }
    
    char *temp = malloc(i + 1);
    
    for(int j = 0; j < i; j++){
        temp[j] = arr[i - j - 1];
    }
    return temp;
}
