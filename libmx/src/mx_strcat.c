#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2){
	int len2 = mx_strlen(s2);
	int len1 = mx_strlen(s1);
	char *temp = malloc(len1 + len2 + 1);
	int count = 0;
	
	for(int i = 0; i < len1; i++){
		temp[count] = s1[i];
		count++;
	}
	for (int i = 0; i < len2; i++){
		temp[count] = s2[i];
		count++;
	}
	temp[count] = '\0';
	return temp;
}
