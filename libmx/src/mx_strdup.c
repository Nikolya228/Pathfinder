#include "../inc/libmx.h"


char *mx_strdup(const char *str) {
	int l = 0;
	char *arr;
	
	while(str[l] != '\0') {
		l++;
	}
	
	if (l > 0) {
		arr = (char*)malloc(l + 1);
		for (int i = 0; i < l + 1; i++)
			arr[i] = '\0';
	}
	
	l = 0;
	
	while (str[l] != '\0') {
		arr[l] = str[l];
		l++;
	}
	
	return arr;
}

