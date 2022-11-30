#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right){
    if (!arr){
        return -1;
    }

    static int swaps = 0;

    if (left < right) {
        int l = left;
        int r = right;
        int pivot = mx_strlen(arr[right]);

        while (l <= r) {
            while (mx_strlen(arr[l]) < pivot) {
                l++;
            }
            while (mx_strlen(arr[r]) > pivot) {
                r--;
	    }
            if (l <= r) {
                if (mx_strlen(arr[r]) != mx_strlen(arr[l])) {
                    char *temp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = temp;
                    swaps++;
                }
                r--;
                l++;
            }
        }
        mx_quicksort(arr, left, r);
        mx_quicksort(arr, l, right);
    }   
    return swaps;
}
