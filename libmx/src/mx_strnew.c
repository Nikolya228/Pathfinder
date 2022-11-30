#include "../inc/libmx.h"

char *mx_strnew(const int size) {
	if (size >= 0) {
		char *arr = malloc(size + 1);
		for (int i = 0; i < size; i++)
			arr[i] = '\0';
		arr[size] = '\0';
		return arr;
	} 
	else return NULL;
}

