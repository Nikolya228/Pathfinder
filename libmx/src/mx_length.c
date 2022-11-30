#include "../inc/libmx.h"

int mx_length(int **arr){
    int count = 0;
    while (arr[count] != NULL){
        count++;
    }
    return count;
}
