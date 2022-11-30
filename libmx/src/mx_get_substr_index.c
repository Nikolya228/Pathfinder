#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
    if (str == NULL || sub == NULL){
        return -2;
    }
    int l2 = mx_strlen(sub);
    bool check = false;

    for (int i = 0; i < mx_strlen(str); i++){
        if (str[i] == sub[0]){
            check = true;
            for (int j = 0; j < l2; j++){
                if (i + j >= mx_strlen(str)){
                    check = false;
                    break;
                }
                if (str[i + j] != sub[j]){
                    check = false;
                    break;
                }
            }
            if (check){
                return i;
            }
        }
    }
    return -1;
}

