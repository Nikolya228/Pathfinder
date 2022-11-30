#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    if (!str || !sub || !replace) return NULL;

    char *temp = mx_strdup(str);
    int count = mx_count_substr(str, sub);
    if (count){
        int idx = mx_get_substr_index(temp, sub);
        char *arr = mx_strndup(temp, idx);
        arr = mx_strjoin(arr, replace);
        count--;
        while (count){
            temp = &temp[mx_get_substr_index(temp, sub) + mx_strlen(sub)];
            idx = mx_get_substr_index(temp, sub);
            char *temp_2 = mx_strndup(temp, idx);
            arr = mx_strjoin(arr, temp_2);
            arr = mx_strjoin(arr, replace);
            count--;
        }
        return arr;
    }
    else return mx_strdup(str);
}


