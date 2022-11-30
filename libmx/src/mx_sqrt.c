#include "../inc/libmx.h"

int mx_sqrt(int x) {
	int square = x / 2;
	int t = square;
	
	if (x == 0)
		return 0;
	else if (x == 1)
		return 1;
	
	while ((t - square) != 0){
		t = square;
		square = (t + (x / t)) / 2;
	}
	
	if (square*square == x) return square;
	
	else return 0;
}
