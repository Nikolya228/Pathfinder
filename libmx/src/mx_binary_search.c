#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
	int f = 0, m;
	int l = size - 1;
	
	while (f <= l)
	{
		m = (f + l) / 2;
		(*count)++;
		if (mx_strcmp(arr[m], s) > 0)
			l = m - 1;
		else if (mx_strcmp(arr[m], s) == 0)
			return m;
		else
			f = m + 1;
	}
	
	if (f > l) {
		*count = 0;
		return -1;
	}
	
	return -1;
}

