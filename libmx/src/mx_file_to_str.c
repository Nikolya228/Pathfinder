#include "../inc/libmx.h"

char *mx_file_to_str(const char *file){
	char *error = NULL;
	if (file == NULL){
		return error;
	}
    int fp = open(file, O_RDONLY);
    if (fp == -1){
        return error;
    }
    char temp;
    int count = 0;

    while (read(fp, &temp, 1) > 0){
        count++;
    }
    close(fp);
    if (count == 0) return error;

    char *arr = mx_strnew(count);
    fp = open(file, O_RDONLY);
    count = 0;

    while(read(fp, &temp, 1) > 0){
        arr[count] = temp;
        count++;
    }
    close(fp);
    return arr;
}

