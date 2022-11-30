#include "../inc/libmx.h"

int mx_bubble_sort(char**arr, int size){
	char *temp;
	int count = 0;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;	
			}
		}
	}
	return count;
}

