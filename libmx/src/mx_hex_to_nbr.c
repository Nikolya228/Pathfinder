#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;

    if (hex == NULL) {
        return 0;
    }
    int digit;

    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= 97 && hex[i] <= 102)
        	digit = hex[i] - 87;
        else if (hex[i] >= 65 && hex[i] <= 70)
        	digit = hex[i] - 55;
        else if (hex[i] >= 48 && hex[i] <= 57){
            digit = hex[i] - 48;
        }
        else 
        	return 0;

        nbr *= 16;
        nbr += digit;
    }
    return nbr;
}
