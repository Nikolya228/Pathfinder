#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str){
    int j = 0;
    
    if (str == NULL) {
        return NULL;
    }

    char *res = mx_strnew(mx_strlen(str));
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!mx_isspace(str[i])) {
            res[j] = str[i];
            j++;
        }
        else if(mx_isspace(str[i]) && mx_isspace(str[i + 1])){
            continue;
        }
        else if(mx_isspace(str[i]) && !mx_isspace(str[i + 1])){
            res[j] = ' ';
            j++;
        }
    }
    char *string1 = mx_strtrim(res);
    mx_strdel(&res);
    return string1;
}
