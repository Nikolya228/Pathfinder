#include "../inc/libmx.h"

char *mx_itoa(int number){
    int count = 0;
    int temp = number;
    char *arr; 
    
    if(number > 0){
        while (temp != 0)
        {
            temp /= 10;
            count++;
        }
    
        arr = malloc(count + 1);
        arr[count] = '\0';
    }
    else if (number < 0){
        temp *= -1, number *= -1;
        while (temp != 0)
        {
            temp /= 10;
            count++;
        }
    
        arr = malloc(count + 2);
        arr[count + 1] = '\0';
        arr[0] = '-';
        count++;
    }
    else{
        return "0";
    }

    while (number != 0){
        int n = number % 10;
        arr[count - 1] = n + 48;
        count--;
        number /= 10;
    }
    return arr;
}
