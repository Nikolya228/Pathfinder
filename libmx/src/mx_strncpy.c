#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	for (int i = 0; i < len; i++){
		if (src[i] == '\0'){
			while (i < len){
				dst[i] = 0;
				i++;
			}
			
			break;
		}
		else dst[i] = src[i];
	}
	return &dst[0];
}

