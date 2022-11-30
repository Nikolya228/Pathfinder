#include "../inc/libmx.h"

void mx_printerr(const char *s) {
	int count = 0;
	
	while(s[count] != '\0') {
		count++;
	}
	
	write(2, s, count);
}
