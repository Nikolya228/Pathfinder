#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	if (str == 0) {
        	return 0;
    	}
    	while (mx_isspace(*str)) {
        	str++;
    	}
    	
    	int l = mx_strlen(str);
    	
    	while (l > 0
    		&& mx_isspace(str[l - 1])){
    		l--;	
    	}
    	
    	char *s = mx_strnew(l);
    	
    	s = mx_strncpy(s, str, l);
    	return s;
    	
}

