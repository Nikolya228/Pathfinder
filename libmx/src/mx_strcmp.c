#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
	int count = 0;
	
	while (s1[count] != '\0'
		|| s2[count] != '\0') {
		if (s1[count] == s2[count]) {
			count++;
			continue;
		}
		else if (s1[count] < s2[count]) {
			int temp = s1[count] - s2[count];
			return temp;
		}
		else {
			int temp = s1[count] - s2[count];
			return temp;
		}
	}
	return 0;
}

