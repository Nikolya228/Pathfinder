#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
	int state = 1;
   	unsigned words = 0;
   	int i = 0;
    
        while (str[i]) {
            if (str[i] == delimiter)
                state = 1;
            else if (state == 1) {
                state = 0;
                words++;
            }
            ++i;
	}
	return words;
}
