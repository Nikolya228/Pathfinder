#include "../inc/libmx.h"


long long int mx_atoi(const char *str) {
	long long int result = 0;
 	int i = 0;
 	int sign = 1;
 
 	while (str[i] != '\0') {
  		if (str[i] == '-') {
   			sign = -1;
   			i++;
   			break;
  		}
  		else if (str[i] == '+') {
   			sign = 1;
   			i++;
   			break;
  		}

  		if (mx_isspace(str[i])) {
   			continue;
  		}
  		else if (mx_isdigit(str[i]))
   			break;
  		else
   			return 0;
 		}
 
 	while (str[i] != '\0')	{
  		if (mx_isdigit(str[i])) {
   		result = result * 10 + str[i] - 48;
   		i++;
  		}
  		else{
  			result = 0;
   			break;
   		}
 	}
 
 	return result * sign;
}

bool mx_isdigit(int c) {
	if (c > 47 && c < 58) {
		return true;
	}
	else {
		return false;
	}
}

bool mx_isspace(char c) {
	if (c == 32) {
		return 1;
	}
	else {
		return 0;
	}
}
