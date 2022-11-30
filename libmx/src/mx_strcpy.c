#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
	int c = 0;
	
	while (src[c] != '\0') {
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return dst;
}

